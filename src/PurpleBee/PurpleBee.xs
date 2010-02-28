#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#include <purple.h>

#include "PurpleBee.h"
#include "uiops/conversation.h"
#include "uiops/core.h"
#include "uiops/eventloop.h"
#include "util/array_size.h"
#include "util/init_error.h"
#include "util/xassert.h"

#include "perlxsi.c"

static PurpleBee* server_instance;

namespace stash
{
  HV* Callback;
}

void
init_server (int argc, char* argv[], char* env[])
{
  xassert (!server_instance);
  server_instance = new PurpleBee (argc, argv, env);
  xassert (server_instance);
  server_instance->init ();
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
  , core_uiops (uiops::core::create ())
  , conversation_uiops (uiops::conversation::create ())
  , eventloop_uiops (uiops::eventloop::create ())
{
}

PurpleBee::~PurpleBee ()
{
  purple_blist_uninit ();
  purple_prefs_uninit ();
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
    "-e", "unshift @INC, '"DATADIR"';",
    "-e", "require PurpleBee;",
    0
  };

  // initialise perl
  if (perl_parse (my_perl, xs_init, array_size (embedding) - 1, const_cast<char**> (embedding), args.env)
      || perl_run (my_perl))
    throw init_error ("unable to initialise perl interpreter");

  if (SvTRUE (ERRSV))
    throw init_error (SvPV_nolen (ERRSV));

  /* Set a custom user directory (optional) */
  purple_util_set_user_dir (dirs.user);

  /* Enable debugging */
  purple_debug_set_enabled (true);

  /* Set the core-uiops, which is used to
   *      - initialise the ui specific preferences.
   *      - initialise the debug ui.
   *      - initialise the ui components for all the modules.
   *      - uninitialise the ui components for all the modules when the core terminates.
   */
  purple_core_set_ui_ops (&core_uiops);

  /* Set the uiops for the eventloop. If your client is glib-based, you can safely
   * copy this verbatim. */
  purple_eventloop_set_ui_ops (&eventloop_uiops);

  /* Now that all the essential stuff has been set, let's try to init the core. It's
   * necessary to provide a non-NULL name for the current ui to the core. This name
   * is used by stuff that depends on this ui, for example the ui-specific plugins. */
  if (!purple_core_init (package ()))
    throw init_error ("libpurple initialisation failed");

  for (auto iter = purple_plugins_get_protocols (); iter; iter = iter->next)
    {
      auto plugin = (PurplePlugin*)iter->data;
      PurplePluginInfo* info = plugin->info;
      if (info && info->name)
        {
          printf ("\t%s\n", info->name);
        }
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


MODULE = PurpleBee      PACKAGE = PurpleBee

BOOT:
{
    stash::Callback = gv_stashpv ("PurpleBee::Callback" , 1);
}

INCLUDE: PurpleBee/Callback.xs
