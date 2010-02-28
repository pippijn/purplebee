#include "uiops/core.h"

namespace uiops
{
  void
  core::ui_prefs_init (void)
  {
  }

  void
  core::debug_ui_init (void)
  {
  }

  void
  core::ui_init (void)
  {
  }

  void
  core::quit (void)
  {
  }

  GHashTable*
  core::get_ui_info (void)
  {
    return NULL;
  }

  PurpleCoreUiOps
  core::create ()
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
