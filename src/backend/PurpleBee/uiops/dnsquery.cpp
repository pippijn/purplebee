/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/dnsquery.h"
#include "common/util/make_closure.h"

#define OPS "UiOps::DnsQuery::"

namespace uiops
{
  gboolean
  dnsquery::resolve_host ( PurpleDnsQueryData* query_data
                         , PurpleDnsQueryResolvedCallback resolved_cb
                         , PurpleDnsQueryFailedCallback failed_cb
                         )
  {
    return perl_call<gboolean> ( OPS "resolve_host"
                                  , query_data
                                  , make_closure (resolved_cb, query_data, (GSList*)0)
                                  , std::make_tuple (failed_cb, query_data, (char const*)0)
                                  );
  }

  void
  dnsquery::destroy (PurpleDnsQueryData* query_data)
  {
    return perl_call<void> (OPS "destroy", query_data);
  }

  PurpleDnsQueryUiOps
  dnsquery::create ()
  {
    return {
      resolve_host,
      destroy,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }

  void
  dnsquery::destroy (G_GNUC_UNUSED PurpleDnsQueryUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying dnsquery callbacks");
  }
}
