#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#include <purple.h>

#include "PurpleBee.h"
#include "uiops/conversation.h"
#include "uiops/core.h"
#include "uiops/eventloop.h"
#include "util/array_size.h"
#include "util/initialisation_error.h"

#include "perlxsi.c"

PurpleBee* server;

PurpleBee::PurpleBee (int argc, char* argv[], char* env[])
  : perl_interpreter (argc, argv, env)
  , dirs {
      LOCALSTATEDIR "/pippijn"
    }
  , core_uiops (uiops::core::create ())
  , conversation_uiops (uiops::conversation::create ())
  , eventloop_uiops (uiops::eventloop::create ())
{
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
  if (!purple_core_init ("PurpleBee"))
    throw initialisation_error ("libpurple initialisation failed");

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

PurpleBee::~PurpleBee ()
{
}

void
PurpleBee::run ()
{
  char const *embedding[] = {
    args.argv[0],
    "-e", "bootstrap PurpleBee;",
    "-e", "unshift @INC, '"DATADIR"';",
    "-e", "require PurpleBee;",
    0
  };

  if (perl_parse (my_perl, xs_init, array_size (embedding) - 1, const_cast<char**> (embedding), args.env)
      || perl_run (my_perl))
    throw initialisation_error ("unable to initialise perl interpreter");

  if (SvTRUE (ERRSV))
    throw initialisation_error (SvPV_nolen (ERRSV));
}


MODULE = PurpleBee      PACKAGE = PurpleBee

BOOT:
{
}
