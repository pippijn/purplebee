#include "PurpleBee.h"

extern char** environ;

int
main (int argc, char* argv[])
{
  char const* prgname = strrchr (argv[0], '/');
  if (prgname)
    ++prgname;
  else
    prgname = argv[0];
  g_set_prgname (prgname);

  init_server (argc, argv, environ);
  server->run ();
  uninit_server ();
  puts ("done");

  return 0;
}
