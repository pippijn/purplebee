#pragma once

#include "util/common.h"

#ifdef __cplusplus
extern "C" {
#endif

struct frame
{
  static unsigned int const MAX_FILE = 64;
  static unsigned int const MAX_FUNC = 512;

  char file[MAX_FILE];
  char func[MAX_FUNC];
  long line;
};

void print_backtrace (int pid = 0) NOTHROW;
char** backtrace_symbols (void* const* buffer, int size) NOTHROW;
frame* backtrace_frames (void* const* buffer, int size) NOTHROW;
char* resolve_symbol (void* sym) NOTHROW;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

template<typename R, typename... Args>
char* resolve_symbol (R sym (Args...))
{
  return resolve_symbol (reinterpret_cast<void*> (sym));
}

#endif
