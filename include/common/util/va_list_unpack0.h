/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/util/va_list_unpack.h"

template<typename T>
T
va_rest (va_list ap)
{
  return va_arg1<T> (ap);
}

template<typename... Info>
std::vector<typename va_list0<Info...>::info_type>
va_list0<Info...>::unpack ()
{
  va_list list = ap;
  std::vector<info_type> vector;
  while (va_rest<typename std::tuple_element<0, info_type>::type> (ap))
    vector.push_back (va_argN<info_type> (list));
  return vector;
}

#if 0
template<typename IntT, typename... Info>
template<int Index>
std::vector<typename std::tuple_element<Index, typename va_list0<IntT, Info...>::info_type>::type>
va_list0<IntT, Info...>::unpack ()
{
  auto all = unpack ();
  std::vector<typename std::tuple_element<Index, typename va_list0<IntT, Info...>::info_type>::type> vector;
  BOOST_FOREACH (auto const& tuple, all)
    {
      vector.push_back (std::get<Index> (tuple));
    }

  return vector;
}
#endif
