#include "PurpleBee.h"

extern char** environ;

int
main (int argc, char* argv[])
{
  init_server (argc, argv, environ);
  server->run ();

  return 0;
}
