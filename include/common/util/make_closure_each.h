/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>
#include <vector>

#include <boost/foreach.hpp>

#include "common/util/type_traits/return_type.h"
#include "common/util/make_closure.h"
#include "common/util/va_list_unpack.h"

template<int Index, typename VaList>
struct va_return_type
{
  typedef typename return_type<typename std::tuple_element<Index, typename VaList::info_type>::type>::type type;
};

template<int Index, typename VaList, typename... Args>
char*
make_closure_each (VaList&& va_wrap, Args... args)
{
  std::vector<std::tuple<typename va_return_type<Index, VaList>::type (*)(Args...), Args...>> closures;
  std::vector<typename VaList::info_type> info = va_wrap.unpack ();

  // TODO: finish this
#if 0
  BOOST_FOREACH (auto const& tuple, info)
    {
      closures.emplace_back ();
    }
#endif

  return 0;
  //return std::make_tuple (function, args...);
}
