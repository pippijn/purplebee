#pragma once

#include <tuple>

template<typename R, typename... Args>
std::tuple<R (*)(Args...), Args...>
make_closure (R (*function)(Args...), Args... args)
{
  return std::make_tuple (function, args...);
}
