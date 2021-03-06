/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <tuple>
#include <vector>

#include "common/perl/interpreter.h"
#include "common/perl/marshal.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (std::vector<std::tuple<char const*, int>> v)
{
  NO_CONV (v, "va_list");
}

/*
 * SV* -> T
 */

#if 0
template<>
bool
perl_interpreter::sv_to (SV* v)
{
  return SvUV (v);
}
#endif
