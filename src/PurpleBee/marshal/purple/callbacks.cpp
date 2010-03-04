#include <tuple>

#include <purple.h>

#include "PurpleBee/Closure.h"
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
  return newSVptr (PurpleBeeClosure::create (*this, make_closure (closure)), newSV (0), perl_package<PurpleBeeClosure>::stash);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleInputFunction, gpointer, int, PurpleInputCondition> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), newSV (0), perl_package<PurpleBeeClosure>::stash);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryResolvedCallback, PurpleDnsQueryData*, GSList*> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), newSV (0), perl_package<PurpleBeeClosure>::stash);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryFailedCallback, PurpleDnsQueryData*, char const*> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), newSV (0), perl_package<PurpleBeeClosure>::stash);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleAccountRequestAuthorizationCb, gpointer> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), newSV (0), perl_package<PurpleBeeClosure>::stash);
}


/*
 * SV* -> T
 */

template<>
GCallback
perl_interpreter::sv_to (SV* sv)
{
  UNIMPLEMENTED;
}
