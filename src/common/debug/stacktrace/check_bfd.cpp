/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "stacktrace.h"

#if HAVE_BFD_H
bool
stacktrace::check_bfd ()
{
#if DLBFD
  return dbfd.handle;
#else
  return true;
#endif
}
#endif
