#include "perl/callback.h"

template<size_t N>
static SV*
hv_fetch_nonnull (HV* hv, char const (&key)[N])
{
  SV** ptr = hv_fetch (hv, key, N - 1, 0);
  xassert (ptr);
  return *ptr;
}

// vim:ft=xs
