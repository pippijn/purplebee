#include "PurpleBee.h"
#include "uiops/xfer.h"

#define OPS "Ops::Xfer::"

namespace uiops
{
  void
  xfer::new_xfer (PurpleXfer* xfer)
  {
  }

  void
  xfer::destroy (PurpleXfer* xfer)
  {
  }

  void
  xfer::add_xfer (PurpleXfer* xfer)
  {
  }

  void
  xfer::update_progress (PurpleXfer* xfer, double percent)
  {
  }

  void
  xfer::cancel_local (PurpleXfer* xfer)
  {
  }

  void
  xfer::cancel_remote (PurpleXfer* xfer)
  {
  }

  gssize
  xfer::ui_write (PurpleXfer* xfer, const guchar* buffer, gssize size)
  {
  }

  gssize
  xfer::ui_read (PurpleXfer* xfer, guchar** buffer, gssize size)
  {
  }

  void
  xfer::data_not_sent (PurpleXfer* xfer, const guchar* buffer, gsize size)
  {
  }

  PurpleXferUiOps
  xfer::create ()
  {
  }
}
