/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <sys/time.h>

#include "common/perl/call.h"

#include "backend/PurpleBee.h"
#include "backend/uiops/debug.h"

#define OPS "UiOps::Debug::"

// We don't use perl_call here, as these functions are used by it
// to print out method name, arguments and return value (it would
// cause a deadlock).
// Besides, if everything else works, this will work, as well, so
// no need to debug these two.
namespace uiops
{
  static char const* catname[] = {
    "ALL",
    "MISC",
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL",
  };

  static FILE* logfh;
  static timeval begin;

#define LOG_STDERR 1

  void
  debug::print (PurpleDebugLevel level, const char* category, const char* arg_s)
  {
    if (begin.tv_sec == 0)
      gettimeofday (&begin, NULL);
    timeval now;
    gettimeofday (&now, NULL);
    timeval diff;
    timersub (&now, &begin, &diff);
    if (logfh)
      fprintf (logfh
              , "[%5ld.%06ld] %s %s: %s\n"
              , diff.tv_sec
              , diff.tv_usec
              , catname[level]
              , category
              , arg_s);
    if (LOG_STDERR || !logfh)
      fprintf (stderr
              , "[%5ld.%06ld] %s %s: %s\n"
              , diff.tv_sec
              , diff.tv_usec
              , catname[level]
              , category
              , arg_s);
    //return server->call<void> (OPS "print", level, category, arg_s);
  }

  gboolean
  debug::is_enabled (PurpleDebugLevel level, const char* category)
  {
    return server->call<gboolean> (OPS "is_enabled", level, category);
  }

  PurpleDebugUiOps
  debug::create ()
  {
    logfh = fopen ("server.log", "w");
    setvbuf (logfh, NULL, _IONBF, 0);

    return {
      print,
      is_enabled,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }

  void
  debug::destroy (G_GNUC_UNUSED PurpleDebugUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying debug callbacks");
    fclose (logfh);
    logfh = NULL;
  }
}
