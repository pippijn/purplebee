/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <cstring>

template<size_t N>
static inline int
strncmp (char const* s1, char const (&s2)[N])
{
  return strncmp (s1, s2, N - 1);
}
