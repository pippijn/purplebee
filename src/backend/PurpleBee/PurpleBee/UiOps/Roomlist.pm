package PurpleBee::UiOps::Roomlist;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub show_with_account {
   my ($self, $account) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Roomlist::show_with_account ($account)";
}

sub create {
   my ($self, $list) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Roomlist::create ($list)";
}

sub set_fields {
   my ($self, $list, $fields) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Roomlist::set_fields ($list, $fields)";
}

sub add_room {
   my ($self, $list, $room) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Roomlist::add_room ($list, $room)";
}

sub in_progress {
   my ($self, $list, $flag) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Roomlist::in_progress ($list, $flag)";
}

sub destroy {
   my ($self, $list) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Roomlist::destroy ($list)";
}


1
