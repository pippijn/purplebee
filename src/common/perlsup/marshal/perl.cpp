/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/interpreter.h"
#include "common/perl/marshal.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (AV* v)
{
  return newRV_noinc ((SV*)v);
}

template<>
SV*
perl_interpreter::to_sv (SV* v)
{
  return newSVsv (v);
}

/*
 * SV* -> T
 */

template<>
SV*
perl_interpreter::sv_to (SV* v)
{
  return newSVsv (v);
}

// vim:ft=xs
