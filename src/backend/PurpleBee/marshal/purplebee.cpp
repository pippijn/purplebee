/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <typeinfo>

#include "common/util/xassert.h"

#include "backend/PurpleBee.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (perl_interpreter* ob)
{
  xassert (ob);
  xassert (typeid (*static_cast<PurpleBee*> (ob)) == typeid (PurpleBee));
  return to_sv<PurpleBee*> (static_cast<PurpleBee*> (ob));
}


/*
 * SV* -> T
 */

template<>
perl_interpreter*
perl_interpreter::sv_to (SV* sv)
{
  auto ob = sv_to<PurpleBee*> (sv);
  // XXX: I would be dynamic_casting here, but that doesn't work with private
  // inheritance. Yes, I know I'm evil but in my opinion, this is clean code.
  // Improve it if you know a better way.
  xassert (typeid (*ob) == typeid (PurpleBee));
  return ob;
}

// vim:ft=xs
