/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <iostream>
#include <vector>

#include <cerrno>
#include <csignal>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <dlfcn.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>

#include "common/debug/backtrace.h"
#include "common/debug/signal.h"
#include "common/debug/trace.h"
#include "common/util/xassert.h"

typedef decltype (user_regs_struct::eflags) word_t;

word_t stack_end;

static pid_t child;

#if __WORDSIZE == 64
static word_t (user_regs_struct::*bp) = &user_regs_struct::rbp;
static word_t (user_regs_struct::*sp) = &user_regs_struct::rsp;
#else
static word_t (user_regs_struct::*bp) = &user_regs_struct::ebp;
static word_t (user_regs_struct::*sp) = &user_regs_struct::esp;
#endif

static void
checked (char const* file, int line, char const* operation, int retval)
{
  if (retval == -1)
    {
      fprintf (stderr, "%s:%d: %s failed: %d (%s)\n", file, line, operation, errno, strerror (errno));
      exit (EXIT_FAILURE);
    }
}

#define checked(op) checked (__FILE__, __LINE__, #op, op)

static void
kill_child ()
{
  if (child)
    {
      printf ("==%d== bringing down child (pid=%d)\n", getpid (), child);
      ptrace (PTRACE_KILL, child, 0, 0);
      child = 0;
    }
}

static void
handle_signal (int signum)
{
  printf ("==%d== caught signal %d\n", getpid (), signum);
  exit (EXIT_FAILURE);
}

struct layout
{
  layout* xbp;
  void* ret;
};

static bool
request_data (word_t& word, word_t addr)
{
  long retval = ptrace (PTRACE_PEEKDATA, child, addr, NULL);

  if (retval == -1 && errno != 0)
    return false;

  word = retval;
  return true;
}

static void
request_data (layout& bp, word_t addr)
{
  xassert (request_data ((word_t&)bp.xbp, addr + offsetof (layout, xbp)));
  xassert (request_data ((word_t&)bp.ret, addr + offsetof (layout, ret)));
}

static void
child_print_fn (char const* fmt)
{
  printf ("==%d==    %s\n", child, fmt);
}

static void
backtrace (word_t lastbp, word_t lastesp)
{
  layout bp;
  request_data (bp, lastbp);

  std::vector<void*> addrs;
  do
    {
      if (false
          or word_t (bp.xbp) < lastesp
          or word_t (bp.xbp) > stack_end
          or word_t (bp.xbp) & 3)
        break;

      addrs.push_back (bp.ret);
      request_data (bp, word_t (bp.xbp));
    }
  while (bp.xbp);

  if (addrs.empty ())
    printf ("==%d== stack trace is not available\n", child);
  else
    {
      printf ("==%d== stack trace:\n", child);
      frame* frames = backtrace_frames (&addrs[0], addrs.size ());
      print_frames (frames, child_print_fn);
      free (frames);
    }
}

#if 0
extern char const foo[6];
char const foo[] = "hello";

static void
end_stack ()
{
  while (true)
    {
      sleep (1);
      *(char*)foo = 0;
    }
}

static void
make_stack (int i = 10)
{
  if (i)
    make_stack (i - 1);
  end_stack ();
}
#endif

static void
print_value (std::istream& in)
{
  std::string location;
  if (!(in >> location))
    return;

  word_t addr = strtol (location.c_str (), 0, 0);

  if (!addr)
    {
      void* self = dlopen (NULL, 0);
      if (void* sym = dlsym (self, location.c_str ()))
        addr = word_t (sym);
      else
        {
          std::cout << "could not find symbol: " << location << ": " << dlerror () << '\n';
          return;
        }
    }

  word_t word;
  if (!request_data (word, addr))
    {
      std::cout << "unable to read address " << addr;
      return;
    }

  std::cout << "0x" << std::hex << word << '\n';
}

static void
print_address (std::istream& in)
{
  std::string location;
  if (!(in >> location))
    return;

  word_t addr;
  void* self = dlopen (NULL, 0);
  if (void* sym = dlsym (self, location.c_str ()))
    addr = word_t (sym);
  else
    {
      std::cout << "could not find symbol: " << location << ": " << dlerror () << '\n';
      return;
    }

  std::cout << location << " @ 0x" << std::hex << addr << '\n';
}

static void
print_resolved (std::istream& in)
{
  std::string location;
  if (!(in >> location))
    return;

  word_t addr = strtol (location.c_str (), 0, 0);
  if (!addr)
    {
      std::cout << "invalid address: " << location << '\n';
      return;
    }

  char* sym = resolve_symbol ((void*)addr);
  std::cout << sym << '\n';
  free (sym);
}

static void
run_gdb ()
{
  char pid[6];
  snprintf (pid, sizeof pid, "%d", child);
  checked (ptrace (PTRACE_DETACH, child, NULL, NULL));
  kill (child, SIGSTOP);
  checked (execlp ("gdb", "gdb", "-q", "-p", pid, NULL));
}

static bool
start_inspector ()
{
  if (!isatty (STDOUT_FILENO))
    return false;

  do
    {
      std::cout << "debug> " << std::flush;

      std::string command;
      if (std::cin >> command)
        {
          if (0) ;
          else if (command[0] == 'a') print_address (std::cin);
          else if (command[0] == 'p') print_value (std::cin);
          else if (command[0] == 'r') print_resolved (std::cin);
          else if (command[0] == 'g') run_gdb ();
          else if (command[0] == 'c') return true;
          else if (command[0] == 'q') return false;
          else
            {
              std::cout << "unknown command: " << command;
              if (std::getline (std::cin, command))
                std::cout << command << '\n';
            }
        }
    }
  while (std::cin);
  std::cout << '\n';

  return false;
}

bool
fork_trace ()
{
  return false;

  xassert (stack_end != 0);

  child = fork ();
  if (child == 0)
    {
      checked (ptrace (PTRACE_TRACEME, 0, NULL, NULL));
#if 0
      printf ("child pid = %d\n", getpid ());
      make_stack ();

      exit (EXIT_SUCCESS);
#endif
    }
  else
    {
      // if anything happens to us, we want to take our child down with us
      atexit (kill_child);
      signal (SIGABRT, handle_signal);
      signal (SIGBUS,  handle_signal);
      signal (SIGINT,  handle_signal);
      signal (SIGQUIT, handle_signal);
      signal (SIGSEGV, handle_signal);
      signal (SIGTERM, handle_signal);

      int status;
      do
        {
          checked (waitpid (child, &status, WCONTINUED));

#if 0
          if (WIFEXITED (status))
            printf ("exited:   %d\n", WEXITSTATUS (status));
          else if (WIFSIGNALED (status))
            printf ("signaled: %d\n", WTERMSIG (status));
          else if (WIFSTOPPED (status))
            printf ("stopped:  %d\n", WSTOPSIG (status));
          else
            {
              fprintf (stderr, "unhandled status: %d\n", status);
              exit (EXIT_FAILURE);
            }
#endif

          user_regs_struct regs;
          ptrace (PTRACE_GETREGS, child, NULL, &regs);

          siginfo_t info;
          ptrace (PTRACE_GETSIGINFO, child, NULL, &info);

          print_siginfo (&info, child);
          printf ("==%d==\n", child);
          backtrace (regs.*bp, regs.*sp);

          if (start_inspector ())
            checked (ptrace (PTRACE_CONT, child, NULL, NULL));
          else
            {
              kill_child ();
              checked (waitpid (child, &status, WCONTINUED));
            }
        }
      while (!WIFEXITED (status) && !WIFSIGNALED (status));

      exit (WEXITSTATUS (status));
    }

  return true;
}
