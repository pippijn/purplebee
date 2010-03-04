package PurpleBee::UiOps::DnsQuery;

use common::sense;

sub resolve_host {
   my ($self, $query_data, $resolved_cb, $failed_cb) = @_;
   $self->print ("PurpleBee::UiOps::DnsQuery::resolve_host ($query_data, $resolved_cb, $failed_cb)\n");

   0 # gboolean
}

sub destroy {
   my ($self, $query_data) = @_;
   $self->print ("PurpleBee::UiOps::DnsQuery::destroy ($query_data)\n");
}


1
