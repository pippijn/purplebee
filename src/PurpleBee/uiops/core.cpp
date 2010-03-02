#include "PurpleBee.h"
#include "uiops/core.h"
#include "util/wrapper.h"

#define OPS "Ops::Core::"

namespace uiops
{
  void
  core::ui_prefs_init (void)
  {
    return server->call<void> (OPS "ui_prefs_init");
  }

  void
  core::debug_ui_init (void)
  {
    return server->call<void> (OPS "debug_ui_init");
  }

  void
  core::ui_init (void)
  {
    purple_conversations_set_ui_ops (&server->conversation_ops);
    //return server->call<void> (OPS "ui_init");
  }

  void
  core::quit (void)
  {
    return server->call<void> (OPS "quit");
  }

  GHashTable*
  core::get_ui_info (void)
  {
    return server->call<wrapper<GHashTable*, char const*, char const*>> (OPS "get_ui_info");
  }

  PurpleCoreUiOps
  core::create ()
  {
    return {
      NULL,//ui_prefs_init,
      NULL,//debug_ui_init,
      ui_init,
      NULL,//quit,
      NULL,//get_ui_info,
    };
  }
}
