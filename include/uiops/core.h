/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

namespace uiops
{
  struct core
  {
    static void ui_prefs_init (void);
    static void debug_ui_init (void);
    static void ui_init (void);
    static void quit (void);
    static GHashTable* get_ui_info (void);

    static PurpleCoreUiOps create ();
  };
}
