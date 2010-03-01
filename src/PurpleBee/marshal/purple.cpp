#include <tuple>

#include "PurpleBee.h"
#include "PurpleBee/stash.h"
#include "perl/callback.h"
#include "util/xassert.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (GCallback closure)
{
  return newSVptr (perl_callback::create (*this, std::make_tuple (closure)), newSV (0), stash::Callback);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleInputFunction, gpointer, int, PurpleInputCondition> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleAccountRequestAuthorizationCb, gpointer> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

#if 0
template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryResolvedCallback, PurpleDnsQueryData*, char const*> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}
#endif

#define PTYPE(T) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)* ob) { return newSVptr (ob, newHV (), stash::PASTE (PurpleBee_, T)); }
#define ITYPE(T) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)  it) { return newSViv (it); }
#include "PurpleBee/types.h"


/*
 * SV* -> T
 */

#define PTYPE(T) template<> PASTE (Purple, T)* perl_interpreter::sv_to (SV* v) { return static_cast<PASTE (Purple, T)*> (SvPTR (v)); }
#define ITYPE(T) template<> PASTE (Purple, T)  perl_interpreter::sv_to (SV* v) { return static_cast<PASTE (Purple, T) > (SvIV  (v)); }
# include "PurpleBee/types.h"

// vim:ft=xs
