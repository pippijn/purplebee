/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <vector>

#include <boost/foreach.hpp>

#include "common/perl/interpreter.h"
#include "common/perl/marshal.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (std::vector<char const*> v)
{
  AV* av = newAV ();
  BOOST_FOREACH (char const* s, v)
    {
      av_push (av, to_sv (s));
    }
  return to_sv (av);
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

// vim:ft=xs
