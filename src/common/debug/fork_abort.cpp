
void
fork_abort (const char *msg)
{
  if (!fork ())
    {
      signal (SIGINT , SIG_IGN);
      signal (SIGTERM, SIG_IGN);
      signal (SIGABRT, SIG_IGN);

      signal (SIGSEGV, SIG_DFL);
      signal (SIGBUS , SIG_DFL);
      signal (SIGILL , SIG_DFL);
      signal (SIGTRAP, SIG_DFL);

      // try to put corefiles into a subdirectory, if existing, to allow
      // an administrator to reduce the I/O load.
      chdir ("cores");

      // try to detach us from as many external dependencies as possible
      // as coredumping can take time by closing all fd's.
      {
        struct rlimit lim;

        if (getrlimit (RLIMIT_NOFILE, &lim))
          lim.rlim_cur = 1024;

        for (int i = 0; i < lim.rlim_cur; ++i)
          close (i);
      }

      {
        sigset_t empty;
        sigemptyset (&empty);
        sigprocmask (SIG_SETMASK, &empty, 0);
      }

      // try to coredump with SIGTRAP
      kill (getpid (), SIGTRAP);
      abort ();
    }

  LOG (llevError, "fork abort: %s\n", msg);
}

