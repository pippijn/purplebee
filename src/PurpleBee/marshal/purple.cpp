#include <tuple>

#include "PurpleBee.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (PurpleConversation* conv)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (PurpleMessageFlags flags)
{
  return newSViv (flags);
}

template<>
SV*
perl_interpreter::to_sv (PurpleInputCondition cond)
{
  return newSViv (cond);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleInputFunction, gpointer, int, PurpleInputCondition> closure)
{
  HV* hv = newHV ();

  // return value
  hv_store (hv, "0", 1, newSViv (VOID), 0);
  // argument types
  hv_store (hv, "T1", 2, newSViv (PTR), 0);
  hv_store (hv, "T2", 2, newSViv (INT), 0);
  hv_store (hv, "T3", 2, newSViv (INT), 0);
  // arguments
  hv_store (hv, "T1", 2, newSVptr (std::get<1> (closure)), 0);
  hv_store (hv, "T2", 2, newSViv  (std::get<2> (closure)), 0);
  hv_store (hv, "T3", 2, newSViv  (std::get<3> (closure)), 0);

  return newSVptr (reinterpret_cast<void*> (std::get<0> (closure)), hv, stash::Callback);
}


/*
 * SV* -> T
 */

// vim:ft=xs
