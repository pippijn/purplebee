#include <tuple>

#include "PurpleBee.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (GList* list)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (GSList* list)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<GSourceFunc, gpointer> closure)
{
  HV* hv = newHV ();

  // return value
  hv_store (hv, "R", 1, newSViv (INT), 0);
  // argument types
  hv_store (hv, "T1", 2, newSViv (PTR), 0);
  // arguments
  hv_store (hv, "A1", 2, newSVptr (std::get<1> (closure)), 0);

  return newSVptr (reinterpret_cast<void*> (std::get<0> (closure)), hv, stash::Callback);
}


/*
 * SV* -> T
 */

template<>
GHashTable*
perl_interpreter::sv_to (SV* v)
{
  return NULL;
}

// vim:ft=xs
