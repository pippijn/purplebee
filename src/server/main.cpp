#include "PurpleBee.h"

extern char** environ;

int
main (int argc, char* argv[])
{
  server = new PurpleBee (argc, argv, environ);
  server->run ();

  return 0;
}
