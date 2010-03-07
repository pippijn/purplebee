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

  static timeval begin;

#define LOG_STDERR 1

  static struct auto_file
  {
    auto_file ()
    {
      fh = fopen ("server.log", "w");
      setvbuf (fh, NULL, _IONBF, 0); // give me my freaking debug log RIGHT NOW!
    }

    ~auto_file ()
    {
      fclose (fh);
    }

    FILE* fh;
  } logfh;

  void
  debug::print (PurpleDebugLevel level, const char* category, const char* arg_s)
  {
    if (begin.tv_sec == 0)
      gettimeofday (&begin, NULL);
    timeval now;
    gettimeofday (&now, NULL);
    timeval diff;
    timersub (&now, &begin, &diff);
    fprintf (logfh.fh
            , "[%5ld.%06ld] %s %s: %s\n"
            , diff.tv_sec
            , diff.tv_usec
            , catname[level]
            , category
            , arg_s);
#if LOG_STDERR
    fprintf (stderr
            , "[%5ld.%06ld] %s %s: %s\n"
            , diff.tv_sec
            , diff.tv_usec / 1000
            , catname[level]
            , category
            , arg_s);
#endif
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
}
