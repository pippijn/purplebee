package PurpleBee::Ops::Blist;

use common::sense;

sub new_list {
   my ($self, $list) = @_;
   $self->print ("PurpleBee::Ops::Blist::new_list ($list)\n");
}

sub new_node {
   my ($self, $node) = @_;
   $self->print ("PurpleBee::Ops::Blist::new_node ($node)\n");
}

sub show {
   my ($self, $list) = @_;
   $self->print ("PurpleBee::Ops::Blist::show ($list)\n");
}

sub update {
   my ($self, $list, $node) = @_;
   $self->print ("PurpleBee::Ops::Blist::update ($list, $node)\n");
}

sub remove {
   my ($self, $list, $node) = @_;
   $self->print ("PurpleBee::Ops::Blist::remove ($list, $node)\n");
}

sub destroy {
   my ($self, $list) = @_;
   $self->print ("PurpleBee::Ops::Blist::destroy ($list)\n");
}

sub set_visible {
   my ($self, $list, $show) = @_;
   $self->print ("PurpleBee::Ops::Blist::set_visible ($list, $show)\n");
}

sub request_add_buddy {
   my ($self, $account, $username, $group, $alias) = @_;
   $self->print ("PurpleBee::Ops::Blist::request_add_buddy ($account, $username, $group, $alias)\n");
}

sub request_add_chat {
   my ($self, $account, $group, $alias, $name) = @_;
   $self->print ("PurpleBee::Ops::Blist::request_add_chat ($account, $group, $alias, $name)\n");
}

sub request_add_group {
   my ($self) = @_;
   $self->print ("PurpleBee::Ops::Blist::request_add_group ()\n");
}

sub save_node {
   my ($self, $node) = @_;
   $self->print ("PurpleBee::Ops::Blist::save_node ($node)\n");
}

sub remove_node {
   my ($self, $node) = @_;
   $self->print ("PurpleBee::Ops::Blist::remove_node ($node)\n");
}

sub save_account {
   my ($self, $account) = @_;
   $self->print ("PurpleBee::Ops::Blist::save_account ($account)\n");
}


1
