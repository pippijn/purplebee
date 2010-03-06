/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee.h"
#include "backend/uiops/xfer.h"
#include "common/perl/call.tcc"

#define OPS "UiOps::Xfer::"

namespace uiops
{
  void
  xfer::new_xfer (PurpleXfer* xfer)
  {
    return perl_call<void> (OPS "new_xfer", xfer);
  }

  void
  xfer::destroy (PurpleXfer* xfer)
  {
    return perl_call<void> (OPS "destroy", xfer);
  }

  void
  xfer::add_xfer (PurpleXfer* xfer)
  {
    return perl_call<void> (OPS "add_xfer", xfer);
  }

  void
  xfer::update_progress (PurpleXfer* xfer, double percent)
  {
    return perl_call<void> (OPS "update_progress", xfer, percent);
  }

  void
  xfer::cancel_local (PurpleXfer* xfer)
  {
    return perl_call<void> (OPS "cancel_local", xfer);
  }

  void
  xfer::cancel_remote (PurpleXfer* xfer)
  {
    return perl_call<void> (OPS "cancel_remote", xfer);
  }

  gssize
  xfer::ui_write (PurpleXfer* xfer, guchar const* buffer, gssize size)
  {
    return perl_call<gssize> (OPS "ui_write", xfer, buffer, size);
  }

  gssize
  xfer::ui_read (PurpleXfer* xfer, guchar** buffer, gssize size)
  {
    return perl_call<gssize> (OPS "ui_read", xfer, buffer, size);
  }

  void
  xfer::data_not_sent (PurpleXfer* xfer, const guchar* buffer, gsize size)
  {
    return perl_call<void> (OPS "data_not_sent", xfer, buffer, size);
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

      // reserved
      NULL,
    };
  }
}
