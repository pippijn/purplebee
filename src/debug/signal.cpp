#include <csignal>
#include <cstdio>

#include <ucontext.h>
#include <unistd.h>

#include "debug/backtrace.h"
#include "debug/signal.h"

// large stack, but it's important data we want to save
static size_t const stacksize = 8 * 1024 * 1024 + SIGSTKSZ;
static char stack[stacksize];

static char const*
signame (int signum)
{
  switch (signum)
    {
    case SIGABRT: return "SIGABRT";
    case SIGQUIT: return "SIGQUIT";
    case SIGBUS:  return "SIGBUS";
    case SIGSEGV: return "SIGSEGV";
    default:      return "<unknown>";
    }
}

template<size_t N>
static ssize_t
write (int fd, char const (&str)[N])
{
  return write (fd, str, N - 1);
}

static void
triple_fault_action (int signum)
{
  signal (signum, SIG_DFL);
  write (STDERR_FILENO, "*** triple fault: aborting process immediately ***\n");
  raise (signum); // XXX: do I have to re-raise it?
}

static void
double_fault_action (int signum)
{
  signal (signum, triple_fault_action);
  printf ("*** double fault *** for signal %d (%s)\n", signum, signame (signum));

  signal (signum, SIG_DFL);
  raise (signum); // XXX: do I have to re-raise it?
}

static void
fault_action (int signum, siginfo_t* info, void* vctx)
{
  ucontext_t* ctx = static_cast<ucontext_t*> (vctx);
  pid_t self = getpid ();

  signal (signum, double_fault_action);
  printf ("==%d== caught signal %d (%s) at %p sent by process %d%s\n"
          "==%d== stack at %p, %zu KiB\n"
          "==%d==\n"
          , self
          , signum
          , signame (signum)
          , info->si_addr
          , info->si_pid
          , info->si_pid == 0 ? " (kernel)" : ""

          , self
          , ctx->uc_stack.ss_sp
          , ctx->uc_stack.ss_size / 1024

          , self
          );
  print_backtrace (self);

  signal (signum, SIG_DFL);
  raise (signum); // XXX: do I have to re-raise it?
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
  sa.sa_flags = SA_RESTART
              | SA_SIGINFO
              | SA_ONSTACK
              ;

  sa.sa_sigaction = fault_action; sigaction (SIGABRT, &sa, 0);
  sa.sa_sigaction = fault_action; sigaction (SIGQUIT, &sa, 0);
  sa.sa_sigaction = fault_action; sigaction (SIGBUS,  &sa, 0);
  sa.sa_sigaction = fault_action; sigaction (SIGSEGV, &sa, 0);
}

void
uninit_signals ()
{
  signal (SIGABRT, SIG_DFL);
  signal (SIGQUIT, SIG_DFL);
  signal (SIGBUS , SIG_DFL);
  signal (SIGSEGV, SIG_DFL);
}
