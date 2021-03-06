/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <iostream>

#include <purple.h> // XXX: G_GNUC_UNUSED

#include "common/util/va_list.h"
#include "common/util/output.h"

template<int N, int Size, typename TupleT>
struct va_arg_unpack1
{
  static void unpack (TupleT& tuple, va_list& ap)
  {
    typedef typename std::tuple_element<N, TupleT>::type arg_type;
    std::get<N> (tuple) = va_arg (ap, arg_type);
    va_arg_unpack1<N + 1, Size, TupleT>::unpack (tuple, ap);
  }
};

template<int N, typename TupleT>
struct va_arg_unpack1<N, N, TupleT>
{
  static void unpack (G_GNUC_UNUSED TupleT& tuple, G_GNUC_UNUSED va_list& ap)
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
