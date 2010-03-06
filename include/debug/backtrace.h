/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "util/common.h"

BEGIN_DECLS

// XXX: Lift arbitrary limits by allocating enough memory for all files,
// functions and frame objects in one piece. This would save memory, too.
// See backtrace_symbols.
enum
{
  MAX_FILE = 64,
  MAX_FUNC = 512,
};

struct frame
{
  char file[MAX_FILE];
  char func[MAX_FUNC];
  long line;
};

void print_backtrace (int pid DEFAULT_ARG (0)) NOTHROW;
char** backtrace_symbols (void* const* buffer, int size) NOTHROW;
frame* backtrace_frames (void* const* buffer, int size) NOTHROW;
char* resolve_symbol (void* sym) NOTHROW;

END_DECLS

#ifdef __cplusplus

// Small helper template that relieves client code from the need to cast.
template<typename R, typename... Args>
char* resolve_symbol (R sym (Args...))
{
  return resolve_symbol (reinterpret_cast<void*> (sym));
}

#endif
