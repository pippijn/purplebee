/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>
#include <vector>

#include <boost/foreach.hpp>

#include "common/util/type_traits/return_type.h"
#include "common/util/make_closure.h"

template<int Index, typename VaList>
struct va_return_type
{
  typedef typename return_type<typename std::tuple_element<Index, typename VaList::info_type>::type>::type type;
};

template<int Index, typename VaList, typename... Args>
struct closure_each_traits
{
  typedef typename va_return_type<Index, VaList>::type  function_type (Args...);
  typedef std::tuple<function_type*, Args...>           closure_type;
  typedef typename VaList::info_type                    info_type;
  typedef std::pair<info_type, closure_type>            info_closure_type;
};

template<int Index, typename VaList, typename... Args>
std::vector<typename closure_each_traits<Index, VaList, Args...>::info_closure_type>
make_closure_each (VaList&& va_wrap, Args... args)
{
  typedef typename closure_each_traits<Index, VaList, Args...>::function_type           function_type;
  typedef typename closure_each_traits<Index, VaList, Args...>::closure_type            closure_type;
  typedef typename closure_each_traits<Index, VaList, Args...>::info_type               info_type;
  typedef typename closure_each_traits<Index, VaList, Args...>::info_closure_type       info_closure_type;

  std::vector<info_closure_type> closures;
  std::vector<typename VaList::info_type> info = va_wrap.unpack ();

  BOOST_FOREACH (auto const& tuple, info)
    {
      closures.emplace_back (tuple, make_closure (std::get<Index> (tuple), args...));
    }

  return closures;
}

template<typename FuncT, typename... Args>
std::vector<std::tuple<FuncT, Args...>>
make_closure_each (std::vector<FuncT> const& funcs, Args... args)
{
  std::vector<std::tuple<FuncT, Args...>> closures;

  BOOST_FOREACH (FuncT const& func, funcs)
    {
      closures.emplace_back (make_closure (func, args...));
    }

  return closures;
}
