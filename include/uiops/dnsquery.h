#pragma once

#include <purple.h>

namespace uiops
{
  struct dnsquery
  {
    static gboolean resolve_host (PurpleDnsQueryData* query_data, PurpleDnsQueryResolvedCallback resolved_cb, PurpleDnsQueryFailedCallback failed_cb);
    static void destroy (PurpleDnsQueryData* query_data);

    static PurpleDnsQueryUiOps create ();
  };
}
