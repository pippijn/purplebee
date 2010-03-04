#include <csignal>
#include <cstring>
#include <cstdio>

#include "debug/backtrace.h"
#include "debug/signal.h"

// large stack, but it's important data we want to save
static size_t const stacksize = 8 * 1024 * 1024 + SIGSTKSZ;
static char stack[stacksize];

static void
handler (int signum)
{
  printf ("signal %d (%s) caught\n", signum, strsignal (signum));
  print_backtrace ();
  signal (signum, SIG_DFL);
}

void
init_signals ()
{
  stack_t ss;
  ss.ss_sp = stack;
  ss.ss_flags = 0;
  ss.ss_size = stacksize;
  sigaltstack (&ss, 0);

  struct sigaction sa;

  sigfillset (&sa.sa_mask);
  sa.sa_flags = SA_RESTART;

  sa.sa_handler = SIG_IGN; sigaction (SIGPIPE, &sa, 0);
  sa.sa_handler = handler; sigaction (SIGABRT, &sa, 0);
  sa.sa_handler = handler; sigaction (SIGQUIT, &sa, 0);
  sa.sa_handler = handler; sigaction (SIGBUS,  &sa, 0);

  sa.sa_flags |= SA_ONSTACK;
  sa.sa_handler = handler; sigaction (SIGSEGV, &sa, 0);
}

void
uninit_signals ()
{
  signal (SIGABRT, SIG_DFL);
  signal (SIGQUIT, SIG_DFL);
  signal (SIGSEGV, SIG_DFL);
  signal (SIGBUS , SIG_DFL);
  signal (SIGINT , SIG_DFL);
  signal (SIGTERM, SIG_DFL);
}
