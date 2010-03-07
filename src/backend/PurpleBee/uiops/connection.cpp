/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/connection.h"

#define OPS "UiOps::Connection::"

namespace uiops
{
  void
  connection::connect_progress (PurpleConnection* gc, const char* text, size_t step, size_t step_count)
  {
    return perl_call<void> (OPS "connect_progress", gc, text, step, step_count);
  }

  void
  connection::connected (PurpleConnection* gc)
  {
    return perl_call<void> (OPS "connected", gc);
  }

  void
  connection::disconnected (PurpleConnection* gc)
  {
    return perl_call<void> (OPS "disconnected", gc);
  }

  void
  connection::notice (PurpleConnection* gc, const char* text)
  {
    return perl_call<void> (OPS "notice", gc, text);
  }

  void
  connection::report_disconnect (PurpleConnection* gc, const char* text)
  {
    return perl_call<void> (OPS "report_disconnect", gc, text);
  }

  void
  connection::network_connected (void)
  {
    return perl_call<void> (OPS "network_connected");
  }

  void
  connection::network_disconnected (void)
  {
    return perl_call<void> (OPS "network_disconnected");
  }

  void
  connection::report_disconnect_reason (PurpleConnection* gc, PurpleConnectionError reason, const char* text)
  {
    return perl_call<void> (OPS "report_disconnect_reason", gc, reason, text);
  }

  PurpleConnectionUiOps
  connection::create ()
  {
    return {
      connect_progress,
      connected,
      disconnected,
      notice,
      report_disconnect,
      network_connected,
      network_disconnected,
      report_disconnect_reason,

      // reserved
      NULL,
      NULL,
      NULL,
    };
  }

  void
  connection::destroy (PurpleConnectionUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying connection callbacks");
  }
}
