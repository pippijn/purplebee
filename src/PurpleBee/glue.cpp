#include "PurpleBee.h"
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

static PurpleBee* server_instance;
static char const* UI_ID;

void
init_server (int argc, char* argv[], char* env[])
{
  xassert (!server_instance);
  server_instance = new PurpleBee (argc, argv, env);
  xassert (server_instance);
  server_instance->init ();
}

void
uninit_server ()
{
  xassert (server_instance);
  delete server_instance;
  server_instance = NULL;
}

PurpleBee*
get_server_instance ()
{
  xassert (server_instance);
  return server_instance;
}


PurpleBee::PurpleBee (int argc, char* argv[], char* env[])
  : perl_interpreter (argc, argv, env)
  , dirs {
      LOCALSTATEDIR "/pippijn",
      "/plugins/saved",
      "",
    }
  , account_ops (uiops::account::create ())
  , blist_ops (uiops::blist::create ())
  , connection_ops (uiops::connection::create ())
  , conversation_ops (uiops::conversation::create ())
  , core_ops (uiops::core::create ())
  , debug_ops (uiops::debug::create ())
  , dnsquery_ops (uiops::dnsquery::create ())
  , eventloop_ops (uiops::eventloop::create ())
  , idle_ops (uiops::idle::create ())
  , notify_ops (uiops::notify::create ())
  , privacy_ops (uiops::privacy::create ())
  , request_ops (uiops::request::create ())
  , roomlist_ops (uiops::roomlist::create ())
  , sound_ops (uiops::sound::create ())
  , whiteboard_ops (uiops::whiteboard::create ())
  , xfer_ops (uiops::xfer::create ())
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

#if 0
  purple_accounts_set_ui_ops (&account_ops);
  purple_blist_set_ui_ops (&blist_ops);
  purple_connections_set_ui_ops (&connection_ops);
#endif
  purple_conversations_set_ui_ops (&conversation_ops);
  purple_core_set_ui_ops (&core_ops);
#if 0
  purple_debug_set_ui_ops (&debug_ops);
  purple_dnsquery_set_ui_ops (&dnsquery_ops);
#endif
  purple_eventloop_set_ui_ops (&eventloop_ops);
#if 0
  purple_idle_set_ui_ops (&idle_ops);
  purple_notify_set_ui_ops (&notify_ops);
  purple_privacy_set_ui_ops (&privacy_ops);
  purple_request_set_ui_ops (&request_ops);
  purple_roomlist_set_ui_ops (&roomlist_ops);
  purple_sound_set_ui_ops (&sound_ops);
  purple_whiteboard_set_ui_ops (&whiteboard_ops);
  purple_xfers_set_ui_ops (&xfer_ops);
#endif

  /* Set path to search for plugins. The core (libpurple) takes care of loading the
   * core-plugins, which includes the protocol-plugins. So it is not essential to add
   * any path here, but it might be desired, especially for ui-specific plugins. */
  purple_plugins_add_search_path (dirs.plugins_path);

  /* Now that all the essential stuff has been set, let's try to init the core. It's
   * necessary to provide a non-NULL name for the current ui to the core. This name
   * is used by stuff that depends on this ui, for example the ui-specific plugins. */
  UI_ID = package ();
  if (!purple_core_init (UI_ID))
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
      auto plugin = (PurplePlugin*)iter->data;
      PurplePluginInfo* info = plugin->info;
      if (info && info->name)
        protocols.push_back (info->name);
    }
}

void
PurpleBee::run ()
{
  char const* username = "pippijn88@hotmail.com";
  char const* password = getpass ("Password: ");
  char const* protocol = "prpl-msn";

  //auto account = purple_account_new (username, protocol);
  //purple_account_set_password (account, password);
  //purple_account_set_enabled (account, package (), true);
  //auto status = purple_savedstatus_new (NULL, PURPLE_STATUS_AVAILABLE);
  //purple_savedstatus_activate (status);

  call<void> ("main", username, password, protocol);
}
