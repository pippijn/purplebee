#include "PurpleBee.h"
#include "perl/call.h"
#include "uiops/xfer.h"

#define OPS "Ops::Xfer::"

namespace uiops
{
  void
  xfer::new_xfer (PurpleXfer* xfer)
  {
    return server->call<void> (OPS "new_xfer", xfer);
  }

  void
  xfer::destroy (PurpleXfer* xfer)
  {
    return server->call<void> (OPS "destroy", xfer);
  }

  void
  xfer::add_xfer (PurpleXfer* xfer)
  {
    return server->call<void> (OPS "add_xfer", xfer);
  }

  void
  xfer::update_progress (PurpleXfer* xfer, double percent)
  {
    return server->call<void> (OPS "update_progress", xfer, percent);
  }

  void
  xfer::cancel_local (PurpleXfer* xfer)
  {
    return server->call<void> (OPS "cancel_local", xfer);
  }

  void
  xfer::cancel_remote (PurpleXfer* xfer)
  {
    return server->call<void> (OPS "cancel_remote", xfer);
  }

  gssize
  xfer::ui_write (PurpleXfer* xfer, const guchar* buffer, gssize size)
  {
    return server->call<gssize> (OPS "ui_write", xfer, buffer, size);
  }

  gssize
  xfer::ui_read (PurpleXfer* xfer, guchar** buffer, gssize size)
  {
    return server->call<gssize> (OPS "ui_read", xfer, buffer, size);
  }

  void
  xfer::data_not_sent (PurpleXfer* xfer, const guchar* buffer, gsize size)
  {
    return server->call<void> (OPS "data_not_sent", xfer, buffer, size);
  }

  PurpleXferUiOps
  xfer::create ()
  {
    return {
      new_xfer,
      destroy,
      add_xfer,
      update_progress,
      cancel_local,
      cancel_remote,
      ui_write,
      ui_read,
      data_not_sent,
    };
  }
}
