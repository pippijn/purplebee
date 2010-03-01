#include "uiops/account.h"
#include "PurpleBee.h"

#define OPS "Ops::Account::"

namespace account
{
  PurpleCoreUiOps
  account::create ()
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
