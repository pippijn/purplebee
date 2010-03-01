#pragma once

#include <purple.h>

namespace uiops
{
  struct xfer
  {
    static void new_xfer (PurpleXfer* xfer);
    static void destroy (PurpleXfer* xfer);
    static void add_xfer (PurpleXfer* xfer);
    static void update_progress (PurpleXfer* xfer, double percent);
    static void cancel_local (PurpleXfer* xfer);
    static void cancel_remote (PurpleXfer* xfer);
    static gssize ui_write (PurpleXfer* xfer, const guchar* buffer, gssize size);
    static gssize ui_read (PurpleXfer* xfer, guchar** buffer, gssize size);
    static void data_not_sent (PurpleXfer* xfer, const guchar* buffer, gsize size);

    static PurpleXferUiOps create ();
  };
}
