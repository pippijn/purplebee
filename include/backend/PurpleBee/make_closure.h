/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/make_closure.h"
#include "common/perl/operation_invoke.h"

#include "backend/PurpleBee/Closure.h"
#include "backend/PurpleBee.h"

template<int... Curried, typename R, typename... Args>
PurpleBeeClosure*
make_closure (R (*function)(Args...), Args... args)
{
  return make_closure<Curried...> (server->base (), function, args...);
}
