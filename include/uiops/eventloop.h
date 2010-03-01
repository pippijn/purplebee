#pragma once

#include <purple.h>

namespace uiops
{
  struct eventloop
  {
    static guint timeout_add (guint interval, GSourceFunc function, gpointer data);
    static guint timeout_add_seconds (guint interval, GSourceFunc function, gpointer data);
    static gboolean timeout_remove (guint handle);
    static guint input_add (int fd, PurpleInputCondition cond, PurpleInputFunction func, gpointer user_data);
    static gboolean input_remove (guint handle);
    static int input_get_error (int fd, int* error);

    static PurpleEventLoopUiOps create ();
  };
}
