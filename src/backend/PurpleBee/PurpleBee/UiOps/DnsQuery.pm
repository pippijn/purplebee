package PurpleBee::UiOps::DnsQuery;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub resolve_host {
   my ($self, $query_data, $resolved_cb, $failed_cb) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::DnsQuery::resolve_host ($query_data, $resolved_cb, $failed_cb)";

   0 # gboolean
}

sub destroy {
   my ($self, $query_data) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::DnsQuery::destroy ($query_data)";
}


1
