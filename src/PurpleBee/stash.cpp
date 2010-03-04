#include <purple.h>

#include "PurpleBee.h"
#include "PurpleBee/Closure.h"
#include "perl/package.h"

#define PTYPE(T, P) template<> HV* perl_package<PASTE (Purple, T)>::stash = 0;
#include "PurpleBee/types.h"

#define PTYPE(T, P) template<> char const* perl_package<PASTE (Purple, T)>::name = P;
#include "PurpleBee/types.h"
