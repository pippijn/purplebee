#include "PurpleBee.h"
#include "uiops/eventloop.h"
#include "util/make_closure.h"

#define OPS "Ops::EventLoop::"

#define PURPLE_GLIB_READ_COND  (G_IO_IN | G_IO_HUP | G_IO_ERR)
#define PURPLE_GLIB_WRITE_COND (G_IO_OUT | G_IO_HUP | G_IO_ERR | G_IO_NVAL)

struct PurpleGLibIOClosure
{
  PurpleInputFunction function;
  guint result;
  gpointer data;
};

static void
purple_glib_io_destroy (gpointer data)
{
  g_free (data);
}

static gboolean
purple_glib_io_invoke (GIOChannel* source, GIOCondition condition, gpointer data)
{
  PurpleGLibIOClosure* closure = (PurpleGLibIOClosure*)data;
  int purple_cond = 0;

  if (condition & PURPLE_GLIB_READ_COND)
    purple_cond |= PURPLE_INPUT_READ;
  if (condition & PURPLE_GLIB_WRITE_COND)
    purple_cond |= PURPLE_INPUT_WRITE;

  closure->function (closure->data, g_io_channel_unix_get_fd (source),
                     PurpleInputCondition (purple_cond));

  return TRUE;
}

static guint
glib_input_add (gint fd, PurpleInputCondition condition, PurpleInputFunction function, gpointer data)
{
  PurpleGLibIOClosure* closure = g_new0 (PurpleGLibIOClosure, 1);
  GIOChannel* channel;
  int cond = 0;

  closure->function = function;
  closure->data = data;

  if (condition & PURPLE_INPUT_READ)
    cond |= PURPLE_GLIB_READ_COND;
  if (condition & PURPLE_INPUT_WRITE)
    cond |= PURPLE_GLIB_WRITE_COND;

  channel = g_io_channel_unix_new (fd);
  closure->result = g_io_add_watch_full (channel, G_PRIORITY_DEFAULT, GIOCondition (cond),
                                         purple_glib_io_invoke, closure, purple_glib_io_destroy);

  g_io_channel_unref (channel);
  return closure->result;
}

namespace uiops
{
  guint
  eventloop::timeout_add (guint interval, GSourceFunc function, gpointer data)
  {
    //printf ("eventloop::timeout_add (%d, %p, %p)\n", interval, function, data);
    return server->call<guint> (OPS "timeout_add", interval, make_closure (function, data));
  }

  gboolean
  eventloop::timeout_remove (guint handle)
  {
    return server->call<gboolean> (OPS "timeout_remove", handle);
  }

  guint
  eventloop::input_add (int fd, PurpleInputCondition cond, PurpleInputFunction func, gpointer user_data)
  {
    return server->call<guint> (OPS "input_add", fd, cond, make_closure (func, user_data, fd, cond));
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
    return server->call<guint> (OPS "timeout_add_seconds", interval, make_closure (function, data));
  }

  PurpleEventLoopUiOps
  eventloop::create ()
  {
    return {
      g_timeout_add,
       g_source_remove,
       glib_input_add,
       g_source_remove,
       NULL,
       g_timeout_add_seconds,
    };
    return {
      timeout_add,
      timeout_remove,
      input_add,
      input_remove,
      NULL,//input_get_error,
      timeout_add_seconds,
    };
  }
}
