#include "PurpleBee.h"

extern char** environ;

int
main (int argc, char* argv[])
{
  PurpleBee bee (argc, argv, environ);
  bee.run ();

  return 0;
}
