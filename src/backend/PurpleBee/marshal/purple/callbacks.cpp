/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <tuple>

#include <boost/foreach.hpp>

#include <purple.h>

#include "common/perl/interpreter.h"
#include "common/perl/marshal.h"
#include "common/perl/operation_invoke.h"
#include "common/perl/package.h"
#include "common/util/make_closure.h"
#include "common/util/unimplemented.h"

#include "backend/PurpleBee/Closure.h"
#include "backend/PurpleBee/callbacks.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (PurpleBeeClosure* closure)
{
  return newSVptr (closure, perl_package<PurpleBeeClosure>::stash, newSV (0));
}

template<>
SV*
perl_interpreter::to_sv (std::vector<PurpleBeeClosure*> closures)
{
  AV* av = newAV ();
  BOOST_FOREACH (PurpleBeeClosure* clos, closures)
    {
      av_push (av, to_sv (clos));
    }
  return to_sv (av);
}


/*
 * SV* -> T
 */

template<>
GCallback
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "GCallback");
}

template<>
PurpleBeeClosure*
perl_interpreter::sv_to (SV* sv)
{
  return static_cast<PurpleBeeClosure*> (SvPTR (sv));
}
