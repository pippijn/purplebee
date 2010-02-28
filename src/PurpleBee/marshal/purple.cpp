#include <purple.h>

#include "perl/interpreter.h"

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
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (PurpleInputCondition cond)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (PurpleInputFunction func)
{
  return newSViv (0);
}


/*
 * SV* -> T
 */
