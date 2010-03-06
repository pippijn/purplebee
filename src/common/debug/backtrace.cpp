/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <stdio.h>
#include <stdlib.h>

#if HAVE_EXECINFO_H
#include <execinfo.h>
#endif

#include "common/debug/backtrace.h"
#include "common/util/array_size.h"

void
print_backtrace (int pid) throw ()
{
#if HAVE_EXECINFO_H
  printf ("==%d== stack trace:\n", pid);

  static void* buffer[128];
  size_t size = backtrace (buffer, array_size (buffer));
  frame* frames = backtrace_frames (buffer, size);

  size_t i = 0;
  printf ("==%d==    at %s (%s:%ld)\n", pid, frames[i].func, frames[i].file, frames[i].line);
  for (++i; i < size; i++)
    printf ("==%d==    by %s (%s:%ld)\n", pid, frames[i].func, frames[i].file, frames[i].line);

  delete[] frames;
#else
  printf ("==%d== stack trace is not available on this system\n", pid);
#endif
}

#if 0
static bool
backtrace_test ()
{
  print_backtrace (0);
  exit (0);
}

static bool b = backtrace_test ();
#endif
