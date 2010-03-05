/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <tuple>

#include <purple.h>

#include "PurpleBee/Closure.h"
#include "PurpleBee/marshal.h"
#include "perl/interpreter.h"
#include "perl/package.h"
#include "util/make_closure.h"
#include "util/unimplemented.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (GCallback closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, make_closure (closure)), perl_package<PurpleBeeClosure>::stash, newSV (0));
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleInputFunction, gpointer, int, PurpleInputCondition> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), perl_package<PurpleBeeClosure>::stash, newSV (0));
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryResolvedCallback, PurpleDnsQueryData*, GSList*> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), perl_package<PurpleBeeClosure>::stash, newSV (0));
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryFailedCallback, PurpleDnsQueryData*, char const*> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), perl_package<PurpleBeeClosure>::stash, newSV (0));
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleAccountRequestAuthorizationCb, gpointer> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), perl_package<PurpleBeeClosure>::stash, newSV (0));
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
