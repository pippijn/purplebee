/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/make_closure.h"
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/eventloop.h"

#define OPS "UiOps::EventLoop::"

namespace uiops
{
  guint
  eventloop::timeout_add (guint interval, GSourceFunc function, gpointer data)
  {
    return perl_call<guint> (OPS "timeout_add", interval, make_closure (function, data));
  }

  gboolean
  eventloop::timeout_remove (guint handle)
  {
    return perl_call<gboolean> (OPS "timeout_remove", handle);
  }

  guint
  eventloop::input_add (int fd, PurpleInputCondition cond, PurpleInputFunction func, gpointer user_data)
  {
    return perl_call<guint> (OPS "input_add", fd, cond, make_closure (func, user_data, fd, cond));
  }

  gboolean
  eventloop::input_remove (guint handle)
  {
    return perl_call<gboolean> (OPS "input_remove", handle);
  }

  int
  eventloop::input_get_error (int fd, int* error)
  {
    return perl_call<int> (OPS "input_get_error", fd, error);
  }

  guint
  eventloop::timeout_add_seconds (guint interval, GSourceFunc function, gpointer data)
  {
    return perl_call<guint> (OPS "timeout_add_seconds", interval, make_closure (function, data));
  }

  PurpleEventLoopUiOps
  eventloop::create ()
  {
    return {
      timeout_add,
      timeout_remove,
      input_add,
      input_remove,
      NULL,//input_get_error,
      timeout_add_seconds,

      // reserved
      NULL,
      NULL,
      NULL,
    };
  }

  void
  eventloop::destroy (G_GNUC_UNUSED PurpleEventLoopUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying eventloop callbacks");
  }
}
