/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <purple.h>

#include "common/perl/package.h"

#include "backend/PurpleBee.h"
#include "backend/PurpleBee/Closure.h"

#define PTYPE(T, P) template<> HV* perl_package<PASTE (Purple, T)>::stash = 0;
#define ITYPE(T, P) PTYPE(T, P)
#include "backend/PurpleBee/types.h"

#define PTYPE(T, P) template<> char const* perl_package<PASTE (Purple, T)>::name = P;
#define ITYPE(T, P) PTYPE(T, P)
#include "backend/PurpleBee/types.h"
