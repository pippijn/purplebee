#include <cstdlib>
#include <cstdio>
#include <csignal>

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>

#include "common/debug/signal.h"

static pid_t child;

static void
handle_signal (int signum)
{
  ptrace (PTRACE_KILL, child, 0, 0);
  signal (signum, SIG_DFL);
  raise (signum);
}

bool
fork_trace ()
{
  return false;

  child = fork ();
  if (!child)
    {
      ptrace (PTRACE_TRACEME, 0, NULL, NULL);
      printf ("my pid = %d\n", getpid ());
      sleep (40);
    }
  else
    {
      signal (SIGTERM, handle_signal);
      signal (SIGINT, handle_signal);
      int status;
      do
        {
          wait (&status);

          printf ("%d\n", status);
          printf ("%d\n", WSTOPSIG (status));
          ptrace (PTRACE_CONT, child, NULL, NULL);
        }
      while (!WIFEXITED (status) && !WSTOPSIG (status) == SIGKILL);

      exit (EXIT_SUCCESS);
    }

  return true;
}
