#pragma once

#include <iostream>
#include <vector>
#include <tuple>

template<typename T>
static inline void
output (T const& object, std::ostream& os = std::cout)
{
  os << object;
}

template<typename T>
static inline void
output (T const* object, std::ostream& os = std::cout)
{
  if (object)
    os << object;
  else
    os << "NULL";
}

template<>
inline void
output (char const* object, std::ostream& os)
{
  if (object)
    os << '"' << object << '"';
  else
    os << "NULL";
}

template<typename T, size_t N>
static inline void
output (T const (&array)[N], std::ostream& os = std::cout)
{
  os << '{';
  for (size_t i = 0; i < N; ++i)
    {
      output (os, array[i]);
      if (i < N - 1)
        os << ", ";
    }
  os << '}';
}

template<typename T>
static inline void
output (std::vector<T> const &vector, std::ostream& os = std::cout)
{
  os << '{';
  for (size_t i = 0; i < vector.size (); ++i)
    {
      output (os, vector[i]);
      if (i < vector.size () - 1)
        os << ", ";
    }
  os << '}';
}

template<typename... Args>
static inline void
output (std::tuple<Args...> const& tuple, std::ostream& os = std::cout)
{
  os << "tuple (";
  os << "<unimplemented>";
  os << ")";
}
