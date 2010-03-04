#include "perl/callback.h"
#include "util/xassert.h"

template<size_t N>
static SV*
hv_fetch_nonnull (HV* hv, char const (&key)[N])
{
  SV** ptr = hv_fetch (hv, key, N - 1, 0);
  xassert (ptr);
  return *ptr;
}

template<>
perl_callback*
perl_interpreter::sv_to (SV* sv)
{
  return static_cast<perl_callback*> (SvPTR (sv));
}

// vim:ft=xs
