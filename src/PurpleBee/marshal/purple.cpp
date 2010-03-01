#include <tuple>

#include "PurpleBee.h"
#include "PurpleBee/stash.h"
#include "perl/callback.h"
#include "util/unimplemented.h"
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
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryResolvedCallback, PurpleDnsQueryData*, GSList*> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryFailedCallback, PurpleDnsQueryData*, char const*> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleAccountRequestAuthorizationCb, gpointer> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

#define PTYPE(T) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)** ob) { UNIMPLEMENTED; }
#include "PurpleBee/types.h"

#define PTYPE(T) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T) const* ob) { return newSVptr (ob, newHV (), stash::PASTE (PurpleBee_, T)); }
#include "PurpleBee/types.h"

#define PTYPE(T) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)* ob) { return to_sv<PASTE (Purple, T) const*> (ob); }
#define ITYPE(T) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)  it) { return newSViv (it); }
#define FTYPE(T) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)  fn) { UNIMPLEMENTED; }
#include "PurpleBee/types.h"


/*
 * SV* -> T
 */

template<>
GCallback
perl_interpreter::sv_to (SV* sv)
{
  UNIMPLEMENTED;
}

#define PTYPE(T) template<> PASTE (Purple, T)** perl_interpreter::sv_to (SV* v) { UNIMPLEMENTED; }
#include "PurpleBee/types.h"

#define PTYPE(T) template<> PASTE (Purple, T)* perl_interpreter::sv_to (SV* v) { return static_cast<PASTE (Purple, T)*> (SvPTR (v)); }
#define ITYPE(T) template<> PASTE (Purple, T)  perl_interpreter::sv_to (SV* v) { return static_cast<PASTE (Purple, T) > (SvIV  (v)); }
#define FTYPE(T) template<> PASTE (Purple, T)  perl_interpreter::sv_to (SV* v) { UNIMPLEMENTED; }
#include "PurpleBee/types.h"

// vim:ft=xs
