#include <EXTERN.h>
#include <perl.h>

namespace stash
{
  extern HV* Callback;
  extern HV* PurpleBee;
#define PTYPE(T) extern HV* PASTE(PurpleBee_, T);
#include "PurpleBee/types.h"
}
