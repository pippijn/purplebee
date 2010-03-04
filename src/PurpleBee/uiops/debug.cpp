#include "PurpleBee.h"
#include "perl/call.h"
#include "uiops/debug.h"

#define OPS "UiOps::Debug::"

namespace uiops
{
  void
  debug::print (PurpleDebugLevel level, const char* category, const char* arg_s)
  {
    return server->call<void> (OPS "print", level, category, arg_s);
  }

  gboolean
  debug::is_enabled (PurpleDebugLevel level, const char* category)
  {
    return server->call<gboolean> (OPS "is_enabled", level, category);
  }

  PurpleDebugUiOps
  debug::create ()
  {
    return {
      print,
      is_enabled,
    };
  }
}
