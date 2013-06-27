/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/marshal.h"
#include "common/perl/output.h"
#include "common/util/xassert.h"

PerlInterpreter* our_perl;

std::ostream&
operator << (std::ostream& os, SV* sv)
{
  xassert (our_perl);
  PerlInterpreter* my_perl = our_perl;
  if (!sv)
    os << "NULL";
  else if (sv == &PL_sv_undef)
    os << "undef";
  else
    os << SvPV_nolen (sv);
  return os;
}

std::ostream&
operator << (std::ostream& os, handle hnd)
{
  return os << hnd.ptr;
}
