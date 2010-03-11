/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <boost/foreach.hpp>

#include "common/util/va_list_unpack.h"

template<typename IntT, typename... Info>
std::vector<typename va_listN<IntT, Info...>::info_type>
va_listN<IntT, Info...>::unpack ()
{
  va_list list;
  va_copy (list, ap);
  std::vector<info_type> vector;
  for (IntT i = 0; i != size; ++i)
    vector.push_back (va_argN<info_type> (list));
  va_end (list);
  return vector;
}

template<typename IntT, typename... Info>
template<int Index>
std::vector<typename std::tuple_element<Index, typename va_listN<IntT, Info...>::info_type>::type>
va_listN<IntT, Info...>::unpack ()
{
  auto all = unpack ();
  std::vector<typename std::tuple_element<Index, typename va_listN<IntT, Info...>::info_type>::type> vector;
  BOOST_FOREACH (auto const& tuple, all)
    {
      vector.push_back (std::get<Index> (tuple));
    }

  return vector;
}
