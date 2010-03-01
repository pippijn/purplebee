#pragma once

#include <type_traits>
#include <ostream>

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
