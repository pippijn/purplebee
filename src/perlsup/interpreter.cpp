#include "autoconf.h"

#include <cassert>
#include <iostream>

#include "perl/interpreter.h"
#include "util/array_size.h"
#include "util/initialisation_error.h"

#include "perlxsi.c"

perl_interpreter::perl_interpreter (int argc, char* argv[], char* env[])
  : my_perl (perl_alloc ())
{
  assert (my_perl);

  PERL_SYS_INIT3 (&argc, &argv, &environ);
  perl_construct (my_perl);
  PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

  char const *embedding[] = {
    argv[0],
    "-e", "bootstrap PurpleBee;",
    "-e", "unshift @INC, '"DATADIR"';",
    "-e", "require PurpleBee;",
    0
  };

  if (perl_parse (my_perl, xs_init, array_size (embedding) - 1, const_cast<char**> (embedding), env)
      || perl_run (my_perl))
    throw initialisation_error ("unable to initialise perl interpreter");

  if (SvTRUE (ERRSV))
    throw initialisation_error (SvPV_nolen (ERRSV));
}

perl_interpreter::~perl_interpreter ()
{
  perl_destruct (my_perl);
  perl_free (my_perl);
}
