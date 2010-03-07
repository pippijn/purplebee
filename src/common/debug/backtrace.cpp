/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

#if HAVE_EXECINFO_H
#include <execinfo.h>
#endif
#include <unistd.h>

#include "common/debug/backtrace.h"
#include "common/util/array_size.h"

void
std_print (char const* fmt)
{
  printf ("==%d==    %s\n", getpid (), fmt);
}

static void
printf (print_fn print, char const* fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  char buffer[512];
  vsnprintf (buffer, sizeof buffer, fmt, ap);
  va_end (ap);

  print (buffer);
}

frame*
backtrace_frames_current (int skip) throw ()
{
#if HAVE_EXECINFO_H
  static void* buffer[128];
  size_t size = backtrace (buffer, array_size (buffer));
  return backtrace_frames (buffer + skip, size - skip);
#else
  return NULL;
#endif
}

void
print_frames (frame const* const frames, print_fn print) throw ()
{
  frame const* current = frames;

  if (frames)
    while (current->file[0])
      {
        printf ( print
               , "%s %s (%s:%d)"
               , current == frames ? "at" : "by"
               , current->func
               , current->file
               , current->line
               );
        ++current;
      }
  else
    print ("stack trace is not available on this system");
}

void
print_backtrace (print_fn print) throw ()
{
  frame* frames = backtrace_frames_current (3);
  print_frames (frames, print);
  delete[] frames;
}

#if 0
static bool
backtrace_test ()
{
  print_backtrace ();
  exit (0);
}

static bool b = backtrace_test ();
#endif
