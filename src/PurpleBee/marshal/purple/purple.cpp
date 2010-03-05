/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "PurpleBee.h"
#include "PurpleBee/Closure.h"
#include "PurpleBee/marshal.h"
#include "perl/package.h"
#include "util/make_closure.h"
#include "util/unimplemented.h"
#include "util/xassert.h"

/*
 * T -> SV*
 */

#define ITYPE(T, P) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)  it) { return newSViv (it); }
#define FTYPE(T, P) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)  fn) { NO_CONV (fn, P); }
#include "PurpleBee/types.h"


/*
 * SV* -> T
 */

#define ITYPE(T, P) template<> PASTE (Purple, T)  perl_interpreter::sv_to (SV* v) { return static_cast<PASTE (Purple, T) > (SvIV  (v)); }
#define FTYPE(T, P) template<> PASTE (Purple, T)  perl_interpreter::sv_to (SV* v) { NO_CONV (v, P); }
#include "PurpleBee/types.h"

// vim:ft=xs
