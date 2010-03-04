#include <stdio.h>
#include <stdlib.h>

#include <execinfo.h>

#include "debug/backtrace.h"
#include "util/array_size.h"

void
print_backtrace ()
{
  printf ("stacktrace:\n");

  static void* buffer[128];
  size_t size = backtrace (buffer, array_size (buffer));
  char** strings = backtrace_symbols (buffer, size);
  for (size_t i = 0; i < size; i++)
    printf ("  [%2zu] %s\n", size - i, strings[i]);
  free (strings);
}

#if 0
static bool
test ()
{
  printf ("%s\n", resolve_symbol (print_backtrace));
  exit (0);
}

static bool b = test ();
#endif
