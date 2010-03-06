/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "PurpleBee.h"
#include "perl/call.tcc"
#include "uiops/core.h"
#include "util/type_traits/wrapper.h"

#define OPS "UiOps::Core::"

namespace uiops
{
  void
  core::ui_prefs_init (void)
  {
    return perl_call<void> (OPS "ui_prefs_init");
  }

  void
  core::debug_ui_init (void)
  {
    return perl_call<void> (OPS "debug_ui_init");
  }

  void
  core::ui_init (void)
  {
    return perl_call<void> (OPS "ui_init");
  }

  void
  core::quit (void)
  {
    return perl_call<void> (OPS "quit");
  }

  GHashTable*
  core::get_ui_info (void)
  {
    return perl_call<wrapper<GHashTable*, char const*, char const*>> (OPS "get_ui_info");
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

      // reserved
      NULL,
      NULL,
      NULL,
    };
  }
}
