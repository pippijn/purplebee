#include "PurpleBee.h"
#include "uiops/connection.h"

#define OPS "Ops::Connection::"

namespace uiops
{
  void
  connection::connect_progress (PurpleConnection* gc, const char* text, size_t step, size_t step_count)
  {
  }

  void
  connection::connected (PurpleConnection* gc)
  {
  }

  void
  connection::disconnected (PurpleConnection* gc)
  {
  }

  void
  connection::notice (PurpleConnection* gc, const char* text)
  {
  }

  void
  connection::report_disconnect (PurpleConnection* gc, const char* text)
  {
  }

  void
  connection::network_connected (void)
  {
  }

  void
  connection::network_disconnected (void)
  {
  }

  void
  connection::report_disconnect_reason (PurpleConnection* gc, PurpleConnectionError reason, const char* text)
  {
  }

  PurpleConnectionUiOps
  connection::create ()
  {
  }
}
