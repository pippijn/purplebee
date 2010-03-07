/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/debug/signal.h"
#include "common/util/xassert.h"

#include "backend/PurpleBee.h"

#include "arguments.h"

#if HAVE_VALGRIND_VALGRIND_H
# include <valgrind.h>
#endif

#ifndef RUNNING_ON_VALGRIND
#define RUNNING_ON_VALGRIND false
#endif

extern char** environ;

int
main (int argc, char* argv[])
try
{
  switch (parse_arguments (argc, argv))
    {
    case parse_status::success:
      return EXIT_SUCCESS;
    case parse_status::failure:
      return EXIT_FAILURE;
    case parse_status::resume:
      break;
    }

  if (RUNNING_ON_VALGRIND)
    fprintf (stderr, "%s: running on valgrind, not catching signals\n", g_get_prgname ());
  else
    init_signals ();
  init_server (argc, argv, environ);
  server->run ();
  // XXX: just for the heck of it. it should be freed automatically, but
  // I like controlled global initialisation and destruction
  uninit_server ();
  uninit_signals ();
  puts ("done");

  return EXIT_SUCCESS;
}
catch (std::exception const& ex)
{
  puts (ex.what ());
  return EXIT_FAILURE;
}
catch (...)
{
  puts ("unknown exception caught");
  return EXIT_FAILURE;
}
