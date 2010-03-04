#pragma once

void print_backtrace ();
char** backtrace_symbols (void* const* buffer, int size);
char* resolve_symbol (void* sym);

template<typename R, typename... Args>
char* resolve_symbol (R sym (Args...))
{
  return resolve_symbol (reinterpret_cast<void*> (sym));
}
