#include "uiops/debug.h"
#include "PurpleBee.h"

#define OPS "Ops::Debug::"

namespace debug
{
  PurpleCoreUiOps
  debug::create ()
  {
    return {
      ui_prefs_init,
      debug_ui_init,
      ui_init,
      quit,
      get_ui_info,
    };
  }
}
