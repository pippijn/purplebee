package PurpleBee::UiOps::Xfer;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub new_xfer {
   my ($self, $xfer) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::new_xfer ($xfer)";
}

sub destroy {
   my ($self, $xfer) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::destroy ($xfer)";
}

sub add_xfer {
   my ($self, $xfer) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::add_xfer ($xfer)";
}

sub update_progress {
   my ($self, $xfer, $percent) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::update_progress ($xfer, $percent)";
}

sub cancel_local {
   my ($self, $xfer) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::cancel_local ($xfer)";
}

sub cancel_remote {
   my ($self, $xfer) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::cancel_remote ($xfer)";
}

sub ui_write {
   my ($self, $xfer, $buffer, $size) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::ui_write ($xfer, $buffer, $size)";

   0 # gssize
}

sub ui_read {
   my ($self, $xfer, $buffer, $size) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::ui_read ($xfer, $buffer, $size)";

   0 # gssize
}

sub data_not_sent {
   my ($self, $xfer, $buffer, $size) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Xfer::data_not_sent ($xfer, $buffer, $size)";
}


1
