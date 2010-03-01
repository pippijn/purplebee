#include "PurpleBee.h"
#include "PurpleBee/stash.h"
#include "util/unimplemented.h"
#include "util/wrapper.h"
#include "perl/callback.h"


/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (GHashTable* list)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (GByteArray* list)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (GList* list)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (GSList* list)
{
  UNIMPLEMENTED;
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
GData**
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
GString*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
GHashTable*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
GList*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
GSList*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
GSourceFunc
perl_interpreter::sv_to (SV* sv)
{
  UNIMPLEMENTED;
}

template<>
wrapper<GHashTable*, char const*, char const*>
perl_interpreter::sv_to (SV* sv)
{
  GHashTable* hash_table = g_hash_table_new (g_str_hash, g_str_equal);

  HV* hv = (HV*)SvRV (sv);

  hv_iterinit (hv);
  char* key;
  I32 retlen;
  while (SV* value = hv_iternextsv (hv, &key, &retlen))
    g_hash_table_insert (hash_table, key, SvPV_nolen (value));

  return { hash_table };
}

// vim:ft=xs
