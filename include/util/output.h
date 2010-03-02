#pragma once

#include <iostream>
#include <vector>
#include <tuple>

template<typename T>
static inline std::ostream&
output (T const& object, std::ostream& os = std::cout)
{
  return os << object;
}

template<typename T>
static inline std::ostream&
output (T const* object, std::ostream& os = std::cout)
{
  if (object)
    os << object;
  else
    os << "NULL";
  return os;
}

static inline std::ostream&
output (char const* object, std::ostream& os = std::cout)
{
  if (object)
    os << '"' << object << '"';
  else
    os << "NULL";
  return os;
}

template<typename T, size_t N>
static inline std::ostream&
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
  return os;
}

template<typename T>
static inline std::ostream&
output (std::vector<T> const &vector, std::ostream& os = std::cout)
{
  os << '{';
  for (size_t i = 0; i < vector.size (); ++i)
    {
      output (vector[i], os);
      if (i < vector.size () - 1)
        os << ", ";
    }
  os << '}';
  return os;
}

namespace detail
{
  template<typename R, typename... Args>
  static inline std::ostream&
  operator << (std::ostream& os, R (*func)(Args...))
  {
    return os << "<func>";
  }

  template<size_t N, size_t Max>
  struct tuple_formatter
  {
    template<typename... Args>
    static void output (std::tuple<Args...> const& tuple, std::ostream& os)
    {
      os << ", " << std::get<N> (tuple);
    }
  };

  template<size_t Max>
  struct tuple_formatter<0, Max>
  {
    template<typename... Args>
    static void output (std::tuple<Args...> const& tuple, std::ostream& os)
    {
      os << std::get<0> (tuple);
      tuple_formatter<1, Max>::output (tuple, os);
    }
  };

  template<>
  struct tuple_formatter<0, 1>
  {
    template<typename... Args>
    static void output (std::tuple<Args...> const& tuple, std::ostream& os)
    {
      os << std::get<0> (tuple);
    }
  };

  template<size_t N>
  struct tuple_formatter<N, N>
  {
    template<typename... Args>
    static void output (std::tuple<Args...> const& tuple, std::ostream& os)
    {
    }
  };
}

template<typename... Args>
static inline std::ostream&
output (std::tuple<Args...> const& tuple, std::ostream& os = std::cout)
{
  os << "tuple (";
  detail::tuple_formatter<0, sizeof... (Args)>::output (tuple, os);
  os << ")";
  return os;
}
