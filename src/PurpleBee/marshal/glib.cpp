#include <tuple>

#include "PurpleBee.h"
#include "PurpleBee/stash.h"
#include "perl/callback.h"
#include "util/wrapper.h"

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
GList*
perl_interpreter::sv_to (SV* v)
{
  return NULL;
}

template<>
GSList*
perl_interpreter::sv_to (SV* v)
{
  return NULL;
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
