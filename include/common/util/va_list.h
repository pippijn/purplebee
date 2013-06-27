/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <cstdarg>

#include <ostream>
#include <tuple>
#include <vector>

template<typename... Info>
struct va_list0
{
  va_list ap;

  typedef std::tuple<Info...> info_type;

  std::vector<info_type> unpack ();
  template<int Index>
  std::vector<typename std::tuple_element<Index, info_type>::type>
  unpack ();

  va_list0 (va_list ap)
  {
    va_copy (this->ap, ap);
  }

  ~va_list0 ()
  {
    va_end (ap);
  }
};

template<typename... Info>
va_list0<Info...>
wrap_va_list (va_list ap)
{
  return va_list0<Info...> (ap);
}

template<typename IntT, typename... Info>
struct va_listN
{
  IntT size;
  va_list ap;

  typedef std::tuple<Info...> info_type;

  std::vector<info_type> unpack ();
  template<int Index>
  std::vector<typename std::tuple_element<Index, info_type>::type>
  unpack ();

  va_listN (IntT size, va_list ap)
    : size (size)
  {
    va_copy (this->ap, ap);
  }

  ~va_listN ()
  {
    va_end (ap);
  }
};

template<typename IntT, typename... Info>
va_listN<IntT, Info...>
wrap_va_list (IntT size, va_list ap)
{
  return va_listN<IntT, Info...> (size, ap);
}
