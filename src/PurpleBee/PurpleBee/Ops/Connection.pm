package PurpleBee::Ops::Connection;

use common::sense;

sub connect_progress {
   my ($self, $gc, $text, $step, $step_count) = @_;
   print "PurpleBee::Ops::Connection::connect_progress ($gc, $text, $step, $step_count)\n";
}

sub connected {
   my ($self, $gc) = @_;
   print "PurpleBee::Ops::Connection::connected ($gc)\n";
}

sub disconnected {
   my ($self, $gc) = @_;
   print "PurpleBee::Ops::Connection::disconnected ($gc)\n";
}

sub notice {
   my ($self, $gc, $text) = @_;
   print "PurpleBee::Ops::Connection::notice ($gc, $text)\n";
}

sub report_disconnect {
   my ($self, $gc, $text) = @_;
   print "PurpleBee::Ops::Connection::report_disconnect ($gc, $text)\n";
}

sub network_connected {
   my ($self) = @_;
   print "PurpleBee::Ops::Connection::network_connected ()\n";
}

sub network_disconnected {
   my ($self) = @_;
   print "PurpleBee::Ops::Connection::network_disconnected ()\n";
}

sub report_disconnect_reason {
   my ($self, $gc, $reason, $text) = @_;
   print "PurpleBee::Ops::Connection::report_disconnect_reason ($gc, $reason, $text)\n";
}


1
