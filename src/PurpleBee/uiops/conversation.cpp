#include "uiops/conversation.h"
#include "PurpleBee.h"

#define OPS "Ops::Conversation::"

namespace conversation
{
  PurpleCoreUiOps
  conversation::create ()
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
