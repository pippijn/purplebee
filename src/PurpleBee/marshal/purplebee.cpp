#include <typeinfo>

#include "PurpleBee.h"
#include "util/xassert.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (PurpleBee* ob)
{
  xassert (ob);
  return to_sv<perl_interpreter*> (ob);
}


/*
 * SV* -> T
 */

template<>
PurpleBee*
perl_interpreter::sv_to (SV* sv)
{
  auto ob = sv_to<perl_interpreter*> (sv);
  // XXX: I would be dynamic_casting here, but that doesn't work with private
  // inheritance. Yes, I know I'm evil but in my opinion, this is clean code.
  // Improve it if you know a better way.
  xassert (typeid (*ob) == typeid (PurpleBee));
  return static_cast<PurpleBee*> (ob);
}

// vim:ft=xs
