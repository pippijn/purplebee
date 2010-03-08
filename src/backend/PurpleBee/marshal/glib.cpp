/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/marshal.h"
#include "common/perl/package.h"
#include "common/perl/operation_invoke.h"
#include "common/util/wrapper.h"
#include "common/util/xassert.h"

#include "backend/PurpleBee.h"
#include "backend/PurpleBee/Closure.h"


/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (GHashTable* list)
{
  NO_CONV (list, "GHashTable*");
}

template<>
SV*
perl_interpreter::to_sv (GByteArray* list)
{
  NO_CONV (list, "GByteArray*");
}

template<>
SV*
perl_interpreter::to_sv (GList* list)
{
  NO_CONV (list, "GList*");
}

template<>
SV*
perl_interpreter::to_sv (GSList* list)
{
  NO_CONV (list, "GSList*");
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<GSourceFunc, gpointer> closure)
{
  return newSVptr (PurpleBeeClosure::create (*this, closure), perl_package<PurpleBeeClosure>::stash, newSV (0));
}


/*
 * SV* -> T
 */

template<>
GData**
perl_interpreter::sv_to (SV* v)
{
  NO_CONV (v, "GData**");
}

template<>
GString*
perl_interpreter::sv_to (SV* v)
{
  NO_CONV (v, "GString*");
}

template<>
GHashTable*
perl_interpreter::sv_to (SV* v)
{
  NO_CONV (v, "GHashTable*");
}

template<>
GList*
perl_interpreter::sv_to (SV* v)
{
  NO_CONV (v, "GList*");
}

template<>
GSList*
perl_interpreter::sv_to (SV* v)
{
  NO_CONV (v, "GSList*");
}

template<>
GSourceFunc
perl_interpreter::sv_to (SV* v)
{
  NO_CONV (v, "GSourceFunc");
}

// TODO: this leaks
template<>
wrapper<GHashTable*, char const*, char const*>
perl_interpreter::sv_to (SV* sv)
{
  xassert (sv);
  xassert (SvROK (sv));
  xassert (SvTYPE (SvRV (sv)) == SVt_PVHV);

  GHashTable* hash_table = g_hash_table_new (g_str_hash, g_str_equal);

  HV* hv = (HV*)SvRV (sv);

  hv_iterinit (hv);
  char* key;
  I32 retlen;
  while (SV* value = hv_iternextsv (hv, &key, &retlen))
    g_hash_table_insert (hash_table, strdup (key), strdup (SvPV_nolen (value)));

  return { hash_table };
}

// vim:ft=xs
