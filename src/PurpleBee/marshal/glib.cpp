#include <glib.h>

#include "perl/interpreter.h"

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
perl_interpreter::to_sv (GSourceFunc list)
{
  return newSViv (0);
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
