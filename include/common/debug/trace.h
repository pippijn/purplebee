#pragma once

#include <csignal>

extern unsigned long stack_end;

bool fork_trace ();

#if __WORDSIZE == 64
# define init_debug()    \
   asm ("movq %%rbp, %0" : "=a" (stack_end));
#else
# define init_debug()    \
   asm ("movl %%ebp, %0" : "=a" (stack_end));
#endif
