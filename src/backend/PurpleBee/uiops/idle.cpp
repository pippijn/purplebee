/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee.h"
#include "backend/uiops/idle.h"
#include "common/perl/call.tcc"

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
}
