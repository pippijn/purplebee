#include "PurpleBee.h"
#include "uiops/connection.h"

#define OPS "Ops::Connection::"

namespace uiops
{
  void
  connection::connect_progress (PurpleConnection* gc, const char* text, size_t step, size_t step_count)
  {
    return server->call<void> (OPS "connect_progress", gc, text, step, step_count);
  }

  void
  connection::connected (PurpleConnection* gc)
  {
    return server->call<void> (OPS "connected", gc);
  }

  void
  connection::disconnected (PurpleConnection* gc)
  {
    return server->call<void> (OPS "disconnected", gc);
  }

  void
  connection::notice (PurpleConnection* gc, const char* text)
  {
    return server->call<void> (OPS "notice", gc, text);
  }

  void
  connection::report_disconnect (PurpleConnection* gc, const char* text)
  {
    return server->call<void> (OPS "report_disconnect", gc, text);
  }

  void
  connection::network_connected (void)
  {
    return server->call<void> (OPS "network_connected");
  }

  void
  connection::network_disconnected (void)
  {
    return server->call<void> (OPS "network_disconnected");
  }

  void
  connection::report_disconnect_reason (PurpleConnection* gc, PurpleConnectionError reason, const char* text)
  {
    return server->call<void> (OPS "report_disconnect_reason", gc, reason, text);
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
    };
  }
}
