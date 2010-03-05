/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "PurpleBee.h"
#include "perl/call.h"
#include "uiops/idle.h"

#define OPS "UiOps::Idle::"

namespace uiops
{
  time_t
  idle::get_time_idle (void)
  {
    return server->call<time_t> (OPS "get_time_idle");
  }

  PurpleIdleUiOps
  idle::create ()
  {
    return {
      get_time_idle,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }
}
