/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "PurpleBee.h"
#include "perl/call.tcc"
#include "uiops/debug.h"

#define OPS "UiOps::Debug::"

// We don't use perl_call here, as these functions are used by it
// to print out method name, arguments and return value (it would
// cause a deadlock).
// Besides, if everything else works, this will work, as well, so
// no need to debug these two.
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

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }
}
