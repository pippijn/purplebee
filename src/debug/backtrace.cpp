#include <stdio.h>
#include <stdlib.h>

#include <execinfo.h>

#include "debug/backtrace.h"
#include "util/array_size.h"

void
print_backtrace (int pid) throw ()
{
  printf ("==%d== stacktrace:\n", pid);

  static void* buffer[128];
  size_t size = backtrace (buffer, array_size (buffer));
  frame* frames = backtrace_frames (buffer, size);

  size_t i = 0;
  printf ("==%d==    at %s (%s:%ld)\n", pid, frames[i].func, frames[i].file, frames[i].line);
  for (++i; i < size; i++)
    printf ("==%d==    by %s (%s:%ld)\n", pid, frames[i].func, frames[i].file, frames[i].line);

  delete[] frames;
}
