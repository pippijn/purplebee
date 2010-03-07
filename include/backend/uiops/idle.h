/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

namespace uiops
{
  struct idle
  {
    static time_t get_time_idle (void);

    static PurpleIdleUiOps create ();
    static void destroy (PurpleIdleUiOps& ops);
  };
}
