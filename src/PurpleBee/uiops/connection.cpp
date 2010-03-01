#include "uiops/connection.h"
#include "PurpleBee.h"

#define OPS "Ops::Connection::"

namespace connection
{
  PurpleCoreUiOps
  connection::create ()
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
