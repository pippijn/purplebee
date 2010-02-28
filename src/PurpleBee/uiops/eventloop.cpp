#include "uiops/eventloop.h"
#include "PurpleBee.h"

#define OPS "Ops::EventLoop::"

namespace uiops
{
  guint
  eventloop::timeout_add (guint interval, GSourceFunc function, gpointer data)
  {
    return server->call<guint> (OPS "timeout_add", interval, function, data);
  }

  gboolean
  eventloop::timeout_remove (guint handle)
  {
    return server->call<gboolean> (OPS "timeout_remove", handle);
  }

  guint
  eventloop::input_add (int fd, PurpleInputCondition cond, PurpleInputFunction func, gpointer user_data)
  {
    return server->call<guint> (OPS "input_add", fd, cond, func, user_data);
  }

  gboolean
  eventloop::input_remove (guint handle)
  {
    return server->call<gboolean> (OPS "input_remove", handle);
  }

  int
  eventloop::input_get_error (int fd, int* error)
  {
    return server->call<int> (OPS "input_get_error", fd, error);
  }

  guint
  eventloop::timeout_add_seconds (guint interval, GSourceFunc function, gpointer data)
  {
    return server->call<guint> (OPS "timeout_add_seconds", interval, function, data);
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
