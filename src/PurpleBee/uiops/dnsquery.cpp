#include "PurpleBee.h"
#include "perl/call.h"
#include "uiops/dnsquery.h"
#include "util/make_closure.h"

#define OPS "Ops::DnsQuery::"

namespace uiops
{
  gboolean
  dnsquery::resolve_host ( PurpleDnsQueryData* query_data
                         , PurpleDnsQueryResolvedCallback resolved_cb
                         , PurpleDnsQueryFailedCallback failed_cb
                         )
  {
    return server->call<gboolean> ( OPS "resolve_host"
                                  , query_data
                                  , make_closure (resolved_cb, query_data, (GSList*)0)
                                  , std::make_tuple (failed_cb, query_data, (char const*)0)
                                  );
  }

  void
  dnsquery::destroy (PurpleDnsQueryData* query_data)
  {
    return server->call<void> (OPS "destroy", query_data);
  }

  PurpleDnsQueryUiOps
  dnsquery::create ()
  {
    return {
      resolve_host,
      destroy,
    };
  }
}
