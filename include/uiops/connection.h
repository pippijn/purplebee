#pragma once

#include <purple.h>

namespace uiops
{
  struct connection
  {
    static void connect_progress (PurpleConnection* gc, const char* text, size_t step, size_t step_count);
    static void connected (PurpleConnection* gc);
    static void disconnected (PurpleConnection* gc);
    static void notice (PurpleConnection* gc, const char* text);
    static void report_disconnect (PurpleConnection* gc, const char* text);
    static void network_connected (void);
    static void network_disconnected (void);
    static void report_disconnect_reason (PurpleConnection* gc, PurpleConnectionError reason, const char* text);

    static PurpleConnectionUiOps create ();
  };
}
