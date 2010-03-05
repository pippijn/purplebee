#include <map>
#include <memory>
#include <string>

#include <valgrind/memcheck.h>

#include "PurpleBee.h"
#include "PurpleBee/Closure.h"
#include "perl/call.h"
#include "perl/package.h"
#include "uiops/core.h"
#include "uiops/conversation.h"
#include "uiops/eventloop.h"
#include "uiops/account.h"
#include "uiops/blist.h"
#include "uiops/connection.h"
#include "uiops/conversation.h"
#include "uiops/core.h"
#include "uiops/debug.h"
#include "uiops/dnsquery.h"
#include "uiops/eventloop.h"
#include "uiops/idle.h"
#include "uiops/notify.h"
#include "uiops/privacy.h"
#include "uiops/request.h"
#include "uiops/roomlist.h"
#include "uiops/sound.h"
#include "uiops/whiteboard.h"
#include "uiops/xfer.h"
#include "util/array_size.h"
#include "util/init_error.h"
#include "util/xassert.h"

#include "perlxsi.c"
#include "faults.cpp"

static std::auto_ptr<PurpleBee> server_instance;

void
init_server (int argc, char* argv[], char* env[])
{
  xassert (!server_instance.get ());
  server_instance.reset (new PurpleBee (argc, argv, env));
  xassert (server_instance.get ());
  server_instance->init ();
}

void
uninit_server ()
{
  xassert (server_instance.get ());
  server_instance.reset (NULL);
}

PurpleBee*
get_server_instance ()
{
  xassert (server_instance.get ());
  return server_instance.get ();
}


PurpleBee::PurpleBee (int argc, char* argv[], char* env[])
  : perl_interpreter (argc, argv, env)
  , dirs {
      LOCALSTATEDIR "/pippijn",
      "/plugins/saved",
      "",
    }
  , account_uiops (uiops::account::create ())
  , blist_uiops (uiops::blist::create ())
  , connection_uiops (uiops::connection::create ())
  , conversation_uiops (uiops::conversation::create ())
  , core_uiops (uiops::core::create ())
  , debug_uiops (uiops::debug::create ())
  , dnsquery_uiops (uiops::dnsquery::create ())
  , eventloop_uiops (uiops::eventloop::create ())
  , idle_uiops (uiops::idle::create ())
  , notify_uiops (uiops::notify::create ())
  , privacy_uiops (uiops::privacy::create ())
  , request_uiops (uiops::request::create ())
  , roomlist_uiops (uiops::roomlist::create ())
  , sound_uiops (uiops::sound::create ())
  , whiteboard_uiops (uiops::whiteboard::create ())
  , xfer_uiops (uiops::xfer::create ())
{
}

PurpleBee::~PurpleBee ()
{
  purple_core_quit ();
}

char const*
PurpleBee::package () const
{
  return "PurpleBee";
}

void
PurpleBee::init ()
{
  char const *embedding[] = {
    args.argv[0],
    "-e", "bootstrap PurpleBee;",
    "-e", "unshift @INC, PurpleBee->DATADIR;",
    "-e", "require PurpleBee;",
    0
  };

  // initialise perl
  if (perl_parse (my_perl, xs_init, array_size (embedding) - 1, const_cast<char**> (embedding), args.env)
      || perl_run (my_perl))
    throw init_error ("unable to initialise perl interpreter");

  if (SvTRUE (ERRSV))
    throw init_error (SvPV_nolen (ERRSV));

  init_self ();

  /* Set a custom user directory (optional) */
  purple_util_set_user_dir (dirs.user);

  /* Enable debugging */
  purple_debug_set_enabled (true);
  purple_debug_set_enabled (false);

  purple_accounts_set_ui_ops (&account_uiops);
  purple_blist_set_ui_ops (&blist_uiops);
  purple_connections_set_ui_ops (&connection_uiops);
  purple_conversations_set_ui_ops (&conversation_uiops);
  purple_core_set_ui_ops (&core_uiops);
  purple_debug_set_ui_ops (&debug_uiops);
  purple_dnsquery_set_ui_ops (&dnsquery_uiops);
  purple_eventloop_set_ui_ops (&eventloop_uiops);
  purple_idle_set_ui_ops (&idle_uiops);
  purple_notify_set_ui_ops (&notify_uiops);
  purple_privacy_set_ui_ops (&privacy_uiops);
  purple_request_set_ui_ops (&request_uiops);
  purple_roomlist_set_ui_ops (&roomlist_uiops);
  purple_sound_set_ui_ops (&sound_uiops);
  purple_whiteboard_set_ui_ops (&whiteboard_uiops);
  purple_xfers_set_ui_ops (&xfer_uiops);

  /* Set path to search for plugins. The core (libpurple) takes care of loading the
   * core-plugins, which includes the protocol-plugins. So it is not essential to add
   * any path here, but it might be desired, especially for ui-specific plugins. */
  purple_plugins_add_search_path (dirs.plugins_path);

  /* Now that all the essential stuff has been set, let's try to init the core. It's
   * necessary to provide a non-NULL name for the current ui to the core. This name
   * is used by stuff that depends on this ui, for example the ui-specific plugins. */
  if (!purple_core_init (package ()))
    throw init_error ("libpurple initialisation failed");

  /* Create and load the buddylist. */
  purple_set_blist (purple_blist_new ());
  purple_blist_load ();

  /* Load the preferences. */
  purple_prefs_load ();

  /* Load the desired plugins. The client should save the list of loaded plugins in
   * the preferences using purple_plugins_save_loaded(dirs.plugin_save) */
  purple_plugins_load_saved (dirs.plugins_saved);

  /* Load the pounces. */
  purple_pounces_load();

  for (auto iter = purple_plugins_get_protocols (); iter; iter = iter->next)
    {
      auto plugin = static_cast<PurplePlugin*> (iter->data);
      PurplePluginInfo* info = plugin->info;
      if (info && info->name)
        printf ("PurplePluginInfo {\n"
                "  id => %s\n"
                "  name => %s\n"
                "  version => %s\n"
                "  summary => %s\n"
                "  description => %s\n"
                "  author => %s\n"
                "  homepage => %s\n"
                "}\n"
                , info->id
                , info->name
                , info->version
                , info->summary
                , info->description
                , info->author
                , info->homepage
                );
    }
}

void
PurpleBee::boot ()
{
#define PTYPE(T, P) \
  perl_package<PASTE (Purple, T)>::stash = gv_stashpv (perl_package<PASTE (Purple, T)>::name, 1);
#include "PurpleBee/types.h"
#define const_val(value) newCONSTSUB (perl_package<PurpleBee>::stash, #value, to_sv (value))
  const_val (PACKAGE);
  const_val (PACKAGE_BUGREPORT);
  const_val (PACKAGE_NAME);
  const_val (PACKAGE_STRING);
  const_val (PACKAGE_TARNAME);
  const_val (PACKAGE_URL);
  const_val (PACKAGE_VERSION);

  const_val (BINDIR);
  const_val (SBINDIR);
  const_val (LIBEXECDIR);
  const_val (DATAROOTDIR);
  const_val (DATADIR);
  const_val (SYSCONFDIR);
  const_val (SHAREDSTATEDIR);
  const_val (LOCALSTATEDIR);
  const_val (INCLUDEDIR);
  const_val (OLDINCLUDEDIR);
  const_val (DOCDIR);
  const_val (INFODIR);
  const_val (HTMLDIR);
  const_val (DVIDIR);
  const_val (PDFDIR);
  const_val (PSDIR);
  const_val (LIBDIR);
  const_val (LOCALEDIR);
  const_val (MANDIR);
#undef const_val
}

void
PurpleBee::run ()
{
  char const* username = getenv ("USERNAME");
  char const* password = getenv ("PASSWORD");
  char const* protocol = getenv ("PROTOCOL");
#define XMPP    0
#define ICQ     0
#define MSN     1
#if XMPP
  if (!username) username = "purplebee-test@xinutec.org";
  if (!password) password = "purplebee-test";
  if (!protocol) protocol = "prpl-jabber";
#elif ICQ
  if (!username) username = "621180987";
  if (!password) password = "B1neMaya";
  if (!protocol) protocol = "prpl-icq";
#elif MSN
  if (!username) username = "pippijn88@hotmail.com";
  if (!password) password = getpass ("Password: ");
  if (!protocol) protocol = "prpl-msn";
#endif

  call<void> ("main", username, password, protocol);
}

void
PurpleBee::valgrind (bool full)
{
  if (full)
    {
      VALGRIND_DO_LEAK_CHECK;
    }
  else
    {
      VALGRIND_DO_QUICK_LEAK_CHECK;
    }
}
