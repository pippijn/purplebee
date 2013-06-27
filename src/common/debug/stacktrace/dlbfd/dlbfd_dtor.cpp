/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "../stacktrace.h"

#if HAVE_BFD_H
stacktrace::dlbfd::~dlbfd ()
{
#if DLBFD
  if (handle)
    dlclose (handle);
#endif
}
#endif
