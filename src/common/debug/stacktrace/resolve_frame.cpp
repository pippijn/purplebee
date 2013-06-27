/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/xassert.h"

#include "stacktrace.h"

#include "frame.h"

stacktrace::frame
stacktrace::resolve_frame (void const* base)
{
  xassert (base);
  if (!check_bfd ())
    return { "func", "file", 0 };

#if HAVE_BFD_H
  xassert (pthread_mutex_lock (&mtx) == 0);

  frame frame = resolve_frame_internal (static_cast<char const*> (base));

  xassert (pthread_mutex_unlock (&mtx) == 0);

  return frame;
#endif
}
