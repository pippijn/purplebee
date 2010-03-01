#include "PurpleBee.h"
#include "uiops/debug.h"

#define OPS "Ops::Debug::"

namespace uiops
{
  void
  debug::print (PurpleDebugLevel level, const char* category, const char* arg_s)
  {
  }

  gboolean
  debug::is_enabled (PurpleDebugLevel level, const char* category)
  {
  }

  PurpleDebugUiOps
  debug::create ()
  {
  }
}
