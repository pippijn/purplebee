#include <cassert>
#include <iostream>

#include "perl/interpreter.h"

perl_interpreter::perl_interpreter (int argc, char* argv[], char* env[])
  : args { argc, argv, env }
  , my_perl (perl_alloc ())
{
  assert (my_perl);

  PERL_SYS_INIT3 (&args.argc, &args.argv, &args.env);
  perl_construct (my_perl);
  PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
}

perl_interpreter::~perl_interpreter ()
{
  perl_destruct (my_perl);
  perl_free (my_perl);
}
