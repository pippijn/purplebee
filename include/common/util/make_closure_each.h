/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>
#include <vector>

#include <boost/foreach.hpp>

#include "common/util/type_traits/return_type.h"
#include "common/util/make_closure.h"

template<typename FuncT, typename... Args>
std::vector<std::tuple<FuncT, Args...>>
make_closure_tuple_each (std::vector<FuncT> const& funcs, Args... args)
{
  std::vector<std::tuple<FuncT, Args...>> closures;

  BOOST_FOREACH (FuncT const& func, funcs)
    {
      closures.emplace_back (make_closure (func, args...));
    }

  return closures;
}
