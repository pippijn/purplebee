/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <type_traits>
#include <ostream>

// A wrapper template that simply creates a type for untyped values such as
// GHashTable and void*. It can be used to create the proper overloads or
// template specialisations and to simply add type safety without having to
// wrap each type separately.
template<typename Wrapped, typename... Args>
struct wrapper
{
  Wrapped wrapped;

  friend std::ostream& operator << (std::ostream& os, wrapper const& wrapper)
  {
    return os << wrapper.wrapped;
  }

  operator Wrapped () const
  {
    static_assert (std::is_pod<wrapper>::value, "wrapped type fails to qualify as POD");
    return wrapped;
  }
};
