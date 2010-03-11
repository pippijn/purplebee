/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>

template<typename R, typename... Args>
std::tuple<R (*)(Args...), Args...>
make_closure_tuple (R (*function)(Args...), Args... args)
{
  return std::make_tuple (function, args...);
}
