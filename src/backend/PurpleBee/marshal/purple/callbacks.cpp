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

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleRequestInputCb, gpointer, char const*> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), perl_package<PurpleBeeClosure>::stash, newSV (0));
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleRequestChoiceCb, gpointer, int> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), perl_package<PurpleBeeClosure>::stash, newSV (0));
}

template<>
SV*
perl_interpreter::to_sv (std::vector<std::tuple<PurpleRequestActionCb, gpointer, int>> closures)
{
  AV* av = newAV ();
  BOOST_FOREACH (auto const& clos, closures)
    {
      av_push (av, to_sv (clos));
    }
  return to_sv (av);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleRequestFieldsCb, gpointer, PurpleRequestFields*> closure)
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
