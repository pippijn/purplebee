#pragma once

#include <iostream>

#include "common/util/va_list.h"
#include "common/util/output.h"

template<typename T>
T
va_arg1 (va_list& ap)
{
  return va_arg (ap, T);
}

template<int N, int Size, typename TupleT>
struct va_arg_unpack1
{
  static void unpack (TupleT& tuple, va_list& ap)
  {
    std::get<N> (tuple) = va_arg1<typename std::tuple_element<N, TupleT>::type> (ap);
    va_arg_unpack1<N + 1, Size, TupleT>::unpack (tuple, ap);
  }
};

template<int N, typename TupleT>
struct va_arg_unpack1<N, N, TupleT>
{
  static void unpack (TupleT& tuple, va_list& ap)
  {
  }
};

template<typename TupleT>
TupleT
va_argN (va_list& ap)
{
  TupleT tuple;
  va_arg_unpack1<0, std::tuple_size<TupleT>::value, TupleT>::unpack (tuple, ap);
  return tuple;
}

template<typename IntT, typename... Info>
std::vector<typename va_listN<IntT, Info...>::info_type>
va_listN<IntT, Info...>::unpack ()
{
  std::vector<info_type> vector;
  for (IntT i = 0; i != size; ++i)
    vector.push_back (va_argN<info_type> (ap));
  return vector;
}
