/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/xassert.h"

#include "stacktrace.h"

#if HAVE_BFD_H
stacktrace::~stacktrace ()
{
  xassert (pthread_mutex_destroy (&mtx) == 0);
}
#endif
