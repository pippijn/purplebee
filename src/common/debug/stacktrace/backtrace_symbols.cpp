/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/xassert.h"

#include "stacktrace.h"

#include "frame.h"

std::vector<stacktrace::frame>
stacktrace::backtrace_symbols (void* const* buffer, size_t size)
{
  xassert (buffer);
  xassert (size > 0);

  size_t stack_depth = size;
  std::vector<frame> frames;

  if (!check_bfd ())
    {
      for (size_t x = 0; x < stack_depth; ++x)
        frames.emplace_back (frame { "func", "file", 0 });
      return frames;
    }

#if HAVE_BFD_H
  xassert (pthread_mutex_lock (&mtx) == 0);

  for (size_t x = 0; x < stack_depth; ++x)
    frames.push_back (resolve_frame_internal (static_cast<char const*> (buffer[x])));

  xassert (pthread_mutex_unlock (&mtx) == 0);

  return frames;
#endif
}
