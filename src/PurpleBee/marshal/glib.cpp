#include <tuple>

#include "PurpleBee.h"
#include "PurpleBee/stash.h"
#include "perl/callback.h"

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
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
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
