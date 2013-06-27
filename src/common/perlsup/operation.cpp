/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/debug/backtrace.h"
#include "common/perl/operation.h"

frame const*
perl_operation_base::get_frames ()
{
#if TRACE_CLOSURE_CREATION
  // XXX: we currently have 12 stack frames above us, but this may change
  return backtrace_frames_current (12);
#else
  return NULL;
#endif
}

void
perl_operation_base::destroy_frames (frame const* frames)
{
  delete[] frames;
}
