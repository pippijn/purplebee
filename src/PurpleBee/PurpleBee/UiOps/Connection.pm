package PurpleBee::UiOps::Connection;

use common::sense;

sub connect_progress {
   my ($self, $gc, $text, $step, $step_count) = @_;
   $self->print ("PurpleBee::UiOps::Connection::connect_progress ($gc, $text, $step, $step_count)\n");
}

sub connected {
   my ($self, $gc) = @_;
   $self->print ("PurpleBee::UiOps::Connection::connected ($gc)\n");
}

sub disconnected {
   my ($self, $gc) = @_;
   $self->print ("PurpleBee::UiOps::Connection::disconnected ($gc)\n");
}

sub notice {
   my ($self, $gc, $text) = @_;
   $self->print ("PurpleBee::UiOps::Connection::notice ($gc, $text)\n");
}

sub report_disconnect {
   my ($self, $gc, $text) = @_;
   $self->print ("PurpleBee::UiOps::Connection::report_disconnect ($gc, $text)\n");
}

sub network_connected {
   my ($self) = @_;
   $self->print ("PurpleBee::UiOps::Connection::network_connected ()\n");
}

sub network_disconnected {
   my ($self) = @_;
   $self->print ("PurpleBee::UiOps::Connection::network_disconnected ()\n");
}

sub report_disconnect_reason {
   my ($self, $gc, $reason, $text) = @_;
   $self->print ("PurpleBee::UiOps::Connection::report_disconnect_reason ($gc, $reason, $text)\n");
}


1
