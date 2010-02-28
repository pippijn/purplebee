#include "perl/interpreter.h"

extern char** environ;

int
main (int argc, char* argv[])
{
  perl_interpreter perl (argc, argv, environ);

  return 0;
}
