/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee.h"
#include "common/perl/call.h"

template<typename R, typename... Args>
static inline R
perl_call (char const* method, Args const&... args)
{
  return perl_caller<R, Args...>::call (*server, method, args...);
}
