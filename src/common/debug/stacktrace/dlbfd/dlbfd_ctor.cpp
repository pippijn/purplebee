/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "../stacktrace.h"

#if HAVE_BFD_H
stacktrace::dlbfd::dlbfd ()
  : handle (0)
{
#if DLBFD
  std::string errors;

  if (!load_bfd (*this, errors))
    {
      // we tried so hard but failed in the end
      // that probably means it's not there, so bail out
      fprintf (stderr, "unable to load BFD library, backtrace will not be available:%s\n",
               errors.c_str ());
      handle = 0;
    }
#endif
}
#endif
