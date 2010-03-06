package PurpleBee::UiOps::Connection;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub connect_progress {
   my ($self, $gc, $text, $step, $step_count) = @_;
   $self->print ("PurpleBee::UiOps::Connection::connect_progress ($gc, $text, $step, $step_count)");
}

sub connected {
   my ($self, $gc) = @_;
   $self->print ("PurpleBee::UiOps::Connection::connected ($gc)");
}

sub disconnected {
   my ($self, $gc) = @_;
   $self->print ("PurpleBee::UiOps::Connection::disconnected ($gc)");
}

sub notice {
   my ($self, $gc, $text) = @_;
   $self->print ("PurpleBee::UiOps::Connection::notice ($gc, $text)");
}

sub report_disconnect {
   my ($self, $gc, $text) = @_;
   $self->print ("PurpleBee::UiOps::Connection::report_disconnect ($gc, $text)");
}

sub network_connected {
   my ($self) = @_;
   $self->print ("PurpleBee::UiOps::Connection::network_connected ()");
}

sub network_disconnected {
   my ($self) = @_;
   $self->print ("PurpleBee::UiOps::Connection::network_disconnected ()");
}

sub report_disconnect_reason {
   my ($self, $gc, $reason, $text) = @_;
   $self->print ("PurpleBee::UiOps::Connection::report_disconnect_reason ($gc, $reason, $text)");
}


1
