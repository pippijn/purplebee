#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#include <purple.h>

#include "PurpleBee.h"
#include "util/array_size.h"
#include "util/initialisation_error.h"

#include "perlxsi.c"

PurpleBee::PurpleBee (int argc, char* argv[], char* env[])
  : perl_interpreter (argc, argv, env)
{
}

PurpleBee::~PurpleBee ()
{
}

void
PurpleBee::run ()
{
  char const *embedding[] = {
    args.argv[0],
    "-e", "bootstrap PurpleBee;",
    "-e", "unshift @INC, '"DATADIR"';",
    "-e", "require PurpleBee;",
    0
  };

  if (perl_parse (my_perl, xs_init, array_size (embedding) - 1, const_cast<char**> (embedding), args.env)
      || perl_run (my_perl))
    throw initialisation_error ("unable to initialise perl interpreter");

  if (SvTRUE (ERRSV))
    throw initialisation_error (SvPV_nolen (ERRSV));
}

MODULE = PurpleBee      PACKAGE = PurpleBee

BOOT:
{
}
