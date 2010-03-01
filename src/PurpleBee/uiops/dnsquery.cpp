#include "PurpleBee.h"
#include "uiops/dnsquery.h"

#define OPS "Ops::DnsQuery::"

namespace uiops
{
  gboolean
  dnsquery::resolve_host (PurpleDnsQueryData* query_data, PurpleDnsQueryResolvedCallback resolved_cb, PurpleDnsQueryFailedCallback failed_cb)
  {
  }

  void
  dnsquery::destroy (PurpleDnsQueryData* query_data)
  {
  }

  PurpleDnsQueryUiOps
  dnsquery::create ()
  {
  }
}
