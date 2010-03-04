#include "PurpleBee.h"
#include "debug/signal.h"
#include "util/xassert.h"

extern char** environ;

int
main (int argc, char* argv[])
try
{
  char const* prgname = strrchr (argv[0], '/');
  if (prgname)
    ++prgname;
  else
    prgname = argv[0];
  g_set_prgname (prgname);

  init_signals ();
  init_server (argc, argv, environ);
  server->run ();
  // XXX: just for the heck of it. it should be freed automatically, but
  // I like controlled global initialisation and destruction
  uninit_server ();
  uninit_signals ();
  puts ("done");

  return 0;
}
catch (std::exception const& ex)
{
  puts (ex.what ());
}
catch (...)
{
  puts ("exception caught");
}
