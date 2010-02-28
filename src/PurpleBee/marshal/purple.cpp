#include "PurpleBee.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (PurpleConversation* conv)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (PurpleMessageFlags flags)
{
  return newSViv (flags);
}

template<>
SV*
perl_interpreter::to_sv (PurpleInputCondition cond)
{
  return newSViv (cond);
}

template<>
SV*
perl_interpreter::to_sv (PurpleInputFunction func)
{
  HV* hv = newHV ();

  typedef void (*PurpleInputFunction)(gpointer, gint, PurpleInputCondition);

  // return value
  hv_store (hv, "0", 1, newSViv (VOID), 0);
  // arguments
  hv_store (hv, "1", 1, newSViv (PTR), 0);
  hv_store (hv, "2", 1, newSViv (INT), 0);
  hv_store (hv, "3", 1, newSViv (INT), 0);

  return newSVptr (reinterpret_cast<void*> (func), stash::Callback, hv);
}


/*
 * SV* -> T
 */

// vim:ft=xs
