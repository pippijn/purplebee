#pragma once

#include <ostream>
#include <vector>

namespace detail
{
  template<typename T>
  static inline void
  output (std::ostream& os, T const& object)
  {
    os << object;
  }

  template<typename T>
  static inline void
  output (std::ostream& os, T const* object)
  {
    if (object)
      os << object;
    else
      os << +"NULL";
  }

  template<>
  inline void
  output (std::ostream& os, char const* object)
  {
    if (object)
      os << '"' << object << '"';
    else
      os << +"NULL";
  }
}

template<typename T, size_t N>
static inline std::ostream&
operator << (std::ostream& os, T const (&array)[N])
{
  os << '{';
  for (size_t i = 0; i < N; ++i)
    {
      detail::output (os, array[i]);
      if (i < N - 1)
        os << +", ";
    }
  os << '}';
  return os;
}

template<typename T>
static inline std::ostream&
operator << (std::ostream& os, std::vector<T> const &vector)
{
  os << '{';
  for (size_t i = 0; i < vector.size (); ++i)
    {
      detail::output (os, vector[i]);
      if (i < vector.size () - 1)
        os << +", ";
    }
  os << '}';
  return os;
}
