/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/idle.h"

#define OPS "UiOps::Idle::"

namespace uiops
{
  time_t
  idle::get_time_idle (void)
  {
    return perl_call<time_t> (OPS "get_time_idle");
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

  void
  idle::destroy (G_GNUC_UNUSED PurpleIdleUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying idle callbacks");
  }
}
