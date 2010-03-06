/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "util/xassert.h"

// A specialised hv_fetch that requires the key to exist within the hash.
template<size_t N>
static SV*
hv_fetch_nonnull (HV* hv, char const (&key)[N])
{
  SV** ptr = hv_fetch (hv, key, N - 1, 0);
  xassert (ptr);
  xassert (*ptr);
  return *ptr;
}
