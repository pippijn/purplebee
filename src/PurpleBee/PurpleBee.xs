#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#include <purple.h>

#include "PurpleBee.h"
#include "PurpleBee/stash.h"
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
      LOCALSTATEDIR "/pippijn"
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

  purple_accounts_set_ui_ops (&account_ops);
  purple_blist_set_ui_ops (&blist_ops);
  purple_connections_set_ui_ops (&connection_ops);
  purple_conversations_set_ui_ops (&conversation_ops);
  purple_core_set_ui_ops (&core_ops);
  purple_debug_set_ui_ops (&debug_ops);
  purple_dnsquery_set_ui_ops (&dnsquery_ops);
  purple_eventloop_set_ui_ops (&eventloop_ops);
  purple_idle_set_ui_ops (&idle_ops);
  purple_notify_set_ui_ops (&notify_ops);
  purple_privacy_set_ui_ops (&privacy_ops);
  purple_request_set_ui_ops (&request_ops);
  purple_roomlist_set_ui_ops (&roomlist_ops);
  purple_sound_set_ui_ops (&sound_ops);
  purple_whiteboard_set_ui_ops (&whiteboard_ops);
  purple_xfers_set_ui_ops (&xfer_ops);

  /* Now that all the essential stuff has been set, let's try to init the core. It's
   * necessary to provide a non-NULL name for the current ui to the core. This name
   * is used by stuff that depends on this ui, for example the ui-specific plugins. */
  UI_ID = package ();
  if (!purple_core_init (UI_ID))
    throw init_error ("libpurple initialisation failed");

  for (auto iter = purple_plugins_get_protocols (); iter; iter = iter->next)
    {
      auto plugin = (PurplePlugin*)iter->data;
      PurplePluginInfo* info = plugin->info;
      if (info && info->name)
        protocols.push_back (info->name);
    }

  /* Create and load the buddylist. */
  purple_set_blist (purple_blist_new ());
  purple_blist_load ();

  /* Load the preferences. */
  purple_prefs_load ();
}

void
PurpleBee::run ()
{
  call<void> ("main");
}

template<typename T>
static void
const_val (HV* stash, char const* name, T v)
{
  newCONSTSUB (stash, (char*)name, server->to_sv (v));
}

#include "PurpleBee/Callback.h"

MODULE = PurpleBee      PACKAGE = PurpleBee

BOOT:
{
    stash::PurpleBee            = gv_stashpv ("PurpleBee", 1);
    stash::Callback             = gv_stashpv ("PurpleBee::Callback", 1);
    stash::PurpleBee_Account    = gv_stashpv ("PurpleBee::Account", 1);
#define const_val(value) const_val (stash::PurpleBee, #value, value)
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

INCLUDE: PurpleBee/Account.xs
INCLUDE: PurpleBee/AccountOption.xs
INCLUDE: PurpleBee/Buddy.xs
INCLUDE: PurpleBee/BuddyIcon.xs
INCLUDE: PurpleBee/BuddyIcons.xs
INCLUDE: PurpleBee/BuddyList.xs
INCLUDE: PurpleBee/Callback.xs
