#include "uiops/eventloop.h"

namespace uiops
{
  guint
  eventloop::timeout_add (guint interval, GSourceFunc function, gpointer data)
  {
    return 0;
  }

  gboolean
  eventloop::timeout_remove (guint handle)
  {
    return false;
  }

  guint
  eventloop::input_add (int fd, PurpleInputCondition cond, PurpleInputFunction func, gpointer user_data)
  {
    return 0;
  }

  gboolean
  eventloop::input_remove (guint handle)
  {
    return false;
  }

  int
  eventloop::input_get_error (int fd, int* error)
  {
    return 0;
  }

  guint
  eventloop::timeout_add_seconds (guint interval, GSourceFunc function, gpointer data)
  {
    return 0;
  }

  PurpleEventLoopUiOps
  eventloop::create ()
  {
    return {
      timeout_add,
      timeout_remove,
      input_add,
      input_remove,
      input_get_error,
      timeout_add_seconds,
    };
  }
}
