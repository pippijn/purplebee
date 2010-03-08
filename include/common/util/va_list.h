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

  va_list0 (va_list ap)
    : ap (ap)
  {
  }
};

template<typename... Info>
std::ostream&
output (va_list0<Info...> const& wrap, std::ostream& os)
{
  return os << "<va_list>";
}

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

  va_listN (IntT size, va_list ap)
    : size (size)
    , ap (ap)
  {
  }
};

template<typename IntT, typename... Info>
std::ostream&
output (va_listN<IntT, Info...> const& wrap, std::ostream& os)
{
  return os << "<va_list>";
}

template<typename IntT, typename... Info>
va_listN<IntT, Info...>
wrap_va_list (IntT size, va_list ap)
{
  return va_listN<IntT, Info...> (size, ap);
}
