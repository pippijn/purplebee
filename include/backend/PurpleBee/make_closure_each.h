/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/make_closure_each.h"
#include "common/perl/operation_invoke.h"

#include "backend/PurpleBee/Closure.h"
#include "backend/PurpleBee.h"

template<int... Curried, typename R, typename... Args>
std::vector<PurpleBeeClosure*>
make_closure_each (std::vector<R (*)(Args...)> const& funcs, Args... args)
{
  return make_closure_each<Curried...> (server->base (), funcs, args...);
}
