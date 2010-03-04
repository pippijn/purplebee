package PurpleBee::UiOps::Xfer;

use common::sense;

sub new_xfer {
   my ($self, $xfer) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::new_xfer ($xfer)\n");
}

sub destroy {
   my ($self, $xfer) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::destroy ($xfer)\n");
}

sub add_xfer {
   my ($self, $xfer) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::add_xfer ($xfer)\n");
}

sub update_progress {
   my ($self, $xfer, $percent) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::update_progress ($xfer, $percent)\n");
}

sub cancel_local {
   my ($self, $xfer) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::cancel_local ($xfer)\n");
}

sub cancel_remote {
   my ($self, $xfer) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::cancel_remote ($xfer)\n");
}

sub ui_write {
   my ($self, $xfer, $buffer, $size) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::ui_write ($xfer, $buffer, $size)\n");

   0 # gssize
}

sub ui_read {
   my ($self, $xfer, $buffer, $size) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::ui_read ($xfer, $buffer, $size)\n");

   0 # gssize
}

sub data_not_sent {
   my ($self, $xfer, $buffer, $size) = @_;
   $self->print ("PurpleBee::UiOps::Xfer::data_not_sent ($xfer, $buffer, $size)\n");
}


1
