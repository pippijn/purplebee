#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>

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
    case SIGBUS : return "SIGBUS";
    case SIGSEGV: return "SIGSEGV";
    case SIGILL : return "SIGILL";
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
double_fault_action (int signum)
{
  printf ("*** double fault *** for signal %d (%s)\n", signum, signame (signum));
  _Exit (EXIT_FAILURE);
}

static char const*
strsicode (int signal, int code)
{
  switch (code)
    {
    case SI_USER        : return "a user process";
    case SI_KERNEL      : return "the kernel";
    case SI_QUEUE       : return "sigqueue(2)";
    case SI_TIMER       : return "an expiring timer";
    case SI_MESGQ       : return "a message queue state change";
    case SI_ASYNCIO     : return "completed async I/O";
    case SI_SIGIO       : return "queued SIGIO";
    }

  switch (signal)
    {
    case SIGILL:
      switch (code)
        {
        case ILL_ILLOPC     : return "an illegal opcode";
        case ILL_ILLOPN     : return "an illegal operand";
        case ILL_ILLADR     : return "an illegal addressing mode";
        case ILL_ILLTRP     : return "an illegal trap";
        case ILL_PRVOPC     : return "using a privileged opcode";
        case ILL_PRVREG     : return "using a privileged register";
        case ILL_COPROC     : return "a coprocessor error";
        case ILL_BADSTK     : return "a internal stack error";
        }
      break;
    case SIGFPE:
      switch (code)
        {
        case FPE_INTDIV     : return "integer divide by zero";
        case FPE_INTOVF     : return "integer overflow";
        case FPE_FLTDIV     : return "floating-point divide by zero";
        case FPE_FLTOVF     : return "floating-point overflow";
        case FPE_FLTUND     : return "floating-point underflow";
        case FPE_FLTRES     : return "floating-point inexact result";
        case FPE_FLTINV     : return "floating-point invalid operation";
        case FPE_FLTSUB     : return "subscript out of range";
        }
      break;
    case SIGSEGV:
      switch (code)
        {
        case SEGV_MAPERR    : return "address not mapped to object";
        case SEGV_ACCERR    : return "invalid permissions for mapped object";
        }
      break;
    case SIGBUS:
      switch (code)
        {
        case BUS_ADRALN     : return "invalid address alignment";
        case BUS_ADRERR     : return "nonexistent physical address";
        case BUS_OBJERR     : return "object-specific hardware error";
        }
      break;
    case SIGTRAP:
      switch (code)
        {
        case TRAP_BRKPT     : return "process breakpoint";
        case TRAP_TRACE     : return "process trace trap";
        }
      break;
    case SIGCHLD:
      switch (code)
        {
        case CLD_EXITED     : return "child has exited";
        case CLD_KILLED     : return "child was killed";
        case CLD_DUMPED     : return "child terminated abnormally";
        case CLD_TRAPPED    : return "traced child has trapped";
        case CLD_STOPPED    : return "child has stopped";
        case CLD_CONTINUED  : return "stopped child has continued";
        }
      break;
    case SIGPOLL:
      switch (code)
        {
        case POLL_IN        : return "data input available";
        case POLL_OUT       : return "output buffers available";
        case POLL_MSG       : return "input message available";
        case POLL_ERR       : return "i/o error";
        case POLL_PRI       : return "high priority input available";
        case POLL_HUP       : return "device disconnected";
        }
      break;
    }

  return "<unknown>";
}

static void
fault_action (int signum, siginfo_t* si, void* vctx)
{
  ucontext_t* ctx = static_cast<ucontext_t*> (vctx);
  pid_t self = getpid ();

  signal (signum, double_fault_action);
  printf ("==%d== caught signal %d (%s)"
          , self
          , si->si_signo
          , signame (si->si_signo)
          );

  switch (si->si_signo)
    {
    case SIGILL:
    case SIGFPE:
    case SIGSEGV:
    case SIGBUS:
      printf (" at %p", si->si_addr);
      break;
    }

  printf (" caused by %s\n", strsicode (si->si_signo, si->si_code));

  printf ("==%d== stack at %p, %zu KiB\n"
          , self
          , ctx->uc_stack.ss_sp
          , ctx->uc_stack.ss_size / 1024
          );
  printf ("==%d==\n", self);

  print_backtrace (self);

  signal (signum, SIG_DFL);
  raise (signum);
}

static struct sigaction
signal (int signum, void action (int, siginfo_t*, void*), int flags = 0)
{
  struct sigaction sa;
  struct sigaction old;

  sigfillset (&sa.sa_mask);
  sa.sa_flags = SA_NODEFER
              | SA_RESTART
              | SA_SIGINFO
              | flags
              ;

  sa.sa_sigaction = action;
  sigaction (signum, &sa, &old);

  return old;
}

void
init_signals ()
{
  stack_t ss;
  ss.ss_sp = stack;
  ss.ss_flags = 0;
  ss.ss_size = stacksize;
  sigaltstack (&ss, 0);

  signal (SIGABRT, fault_action);
  signal (SIGQUIT, fault_action);
  signal (SIGBUS,  fault_action);
  signal (SIGSEGV, fault_action, SA_ONSTACK);
  signal (SIGILL , fault_action);
  signal (SIGFPE , fault_action);
}

void
uninit_signals ()
{
  signal (SIGABRT, SIG_DFL);
  signal (SIGQUIT, SIG_DFL);
  signal (SIGBUS, SIG_DFL);
  signal (SIGSEGV, SIG_DFL);
  signal (SIGILL, SIG_DFL);
  signal (SIGFPE, SIG_DFL);
}
