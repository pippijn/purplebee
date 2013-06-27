/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/marshal.h"
#include "common/perl/package.h"
#include "common/util/make_closure.h"
#include "common/util/unimplemented.h"
#include "common/util/xassert.h"

#include "backend/PurpleBee.h"
#include "backend/PurpleBee/Closure.h"
#include "backend/PurpleBee/callbacks.h"

/*
 * T -> SV*
 */

#define ITYPE(T, P) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)  it) { return newSViv (it); }
#define FTYPE(T, P) template<> SV* perl_interpreter::to_sv (PASTE (Purple, T)  fn) { NO_CONV (fn, P); }
#include "backend/PurpleBee/types.h"


/*
 * SV* -> T
 */

#define ITYPE(T, P) template<> PASTE (Purple, T)  perl_interpreter::sv_to (SV* v) { return static_cast<PASTE (Purple, T) > (SvIV  (v)); }
#define FTYPE(T, P) template<> PASTE (Purple, T)  perl_interpreter::sv_to (SV* v) { NO_CONV (v, P); }
#include "backend/PurpleBee/types.h"

// vim:ft=xs
