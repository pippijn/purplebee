#include "uiops/blist.h"
#include "PurpleBee.h"

#define OPS "Ops::Blist::"

namespace blist
{
  PurpleCoreUiOps
  blist::create ()
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
