#include <purple.h>

#include "common/debug/dout.h"

debug_stream dout;

debug_stream::transaction_base::transaction_base (debug_stream& dout)
  : dout (dout)
{
  dout.lock ();
}

debug_stream::transaction_base::~transaction_base ()
{
  dout.unlock ();
}


debug_stream::debug_stream ()
{
  pthread_mutex_init (&mtx, NULL);
}

debug_stream::~debug_stream ()
{
  pthread_mutex_destroy (&mtx);
}

void
debug_stream::acquire ()
{
  lock ();
}

int
debug_stream::lock ()
{
  volatile bool b = false;
  if (b)
    print_backtrace ();
  puts (">>>>>>>>>>>>>>>>>> lock");
  return pthread_mutex_lock (&mtx);
}

int
debug_stream::unlock ()
{
  puts ("<<<<<<<<<<<<<<<<<< unlock");
  return pthread_mutex_unlock (&mtx);
}

bool
debug_stream::is_locked ()
{
  // See if the mutex is lockable. If it is not, that means it is already
  // locked and pthread_mutex_trylock will return non-zero.
  bool locked = pthread_mutex_trylock (&mtx) == 0;

  // Unlock it, if we just locked it, since we don't need it.
  if (locked)
    unlock ();
  return locked;
}

#if 0
static void
debug_test_print (PurpleDebugLevel level, const char* category, const char* arg_s)
{
  printf ("%d: [%s] %s\n", level, category, arg_s);
}

static gboolean
debug_test_is_enabled (PurpleDebugLevel level, const char* category)
{
  return category + level != 0;
}

static bool
test_debug ()
{
  PurpleDebugUiOps ops { debug_test_print, debug_test_is_enabled, 0, 0, 0, 0 };
  purple_debug_set_ui_ops (&ops);
  purple_debug_init ();
  auto&& atom = dout.atomic (purple_debug_misc, "ffi");
  atom ("hello", "world");
  atom ("hello", "world");
  //dout.atomic (purple_debug_misc, "ffi") ("hello", "world");
  exit (0);
}

static bool b = test_debug ();
#endif
