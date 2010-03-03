package PurpleBee::Ops::Roomlist;

use common::sense;

sub show_with_account {
   my ($self, $account) = @_;
   $self->print ("PurpleBee::Ops::Roomlist::show_with_account ($account)\n");
}

sub create {
   my ($self, $list) = @_;
   $self->print ("PurpleBee::Ops::Roomlist::create ($list)\n");
}

sub set_fields {
   my ($self, $list, $fields) = @_;
   $self->print ("PurpleBee::Ops::Roomlist::set_fields ($list, $fields)\n");
}

sub add_room {
   my ($self, $list, $room) = @_;
   $self->print ("PurpleBee::Ops::Roomlist::add_room ($list, $room)\n");
}

sub in_progress {
   my ($self, $list, $flag) = @_;
   $self->print ("PurpleBee::Ops::Roomlist::in_progress ($list, $flag)\n");
}

sub destroy {
   my ($self, $list) = @_;
   $self->print ("PurpleBee::Ops::Roomlist::destroy ($list)\n");
}


1
