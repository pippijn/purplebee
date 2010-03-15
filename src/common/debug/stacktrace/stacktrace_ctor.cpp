/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/xassert.h"

#include "stacktrace.h"

#if HAVE_BFD_H
#include "dlbfd.h"

stacktrace::stacktrace ()
  : syms (0)
  , dbfd ()
  , pc (0)
  , filename ("file")
  , funcname ("func")
  , line (0)
  , found (false)
{
  bfd_init ();
  xassert (pthread_mutex_init (&mtx, NULL) == 0);
}
#endif
