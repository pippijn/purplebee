#include "PurpleBee/stash.h"

namespace stash
{
  HV* Callback;
  HV* PurpleBee;
#define PTYPE(T, P) HV* PASTE(PurpleBee_, T);
#include "PurpleBee/types.h"
}
