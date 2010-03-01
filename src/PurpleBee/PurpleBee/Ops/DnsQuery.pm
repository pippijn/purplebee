package PurpleBee::Ops::DnsQuery;

use common::sense;

sub resolve_host {
   my ($self, $query_data, $resolved_cb, $failed_cb) = @_;
   print "PurpleBee::Ops::DnsQuery::resolve_host ($query_data, $resolved_cb, $failed_cb)\n";

   0 # gboolean
}

sub destroy {
   my ($self, $query_data) = @_;
   print "PurpleBee::Ops::DnsQuery::destroy ($query_data)\n";
}


1
