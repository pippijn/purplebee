#pragma once

#include <purple.h>

namespace uiops
{
  struct idle
  {
    static time_t get_time_idle (void);

    static PurpleIdleUiOps create ();
  };
}
