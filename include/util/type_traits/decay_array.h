/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <cstddef>

// Helper trait to make sure an array is converted to a pointer without
// having to copy it (and all other tuple members).
template<typename T>
struct decay_array
{
  typedef T type;
};

template<typename T, size_t N>
struct decay_array<T[N]>
{
  typedef T const* type;
};
