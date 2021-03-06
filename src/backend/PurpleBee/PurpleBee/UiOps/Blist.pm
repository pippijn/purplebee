package PurpleBee::UiOps::Blist;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub new_list {
   my ($self, $list) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::new_list ($list)";
}

sub new_node {
   my ($self, $node) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::new_node ($node)";
}

sub show {
   my ($self, $list) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::show ($list)";
}

sub update {
   my ($self, $list, $node) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::update ($list, $node)";
}

sub remove {
   my ($self, $list, $node) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::remove ($list, $node)";
}

sub destroy {
   my ($self, $list) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::destroy ($list)";
}

sub set_visible {
   my ($self, $list, $show) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::set_visible ($list, $show)";
}

sub request_add_buddy {
   my ($self, $account, $username, $group, $alias) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::request_add_buddy ($account, $username, $group, $alias)";
}

sub request_add_chat {
   my ($self, $account, $group, $alias, $name) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::request_add_chat ($account, $group, $alias, $name)";
}

sub request_add_group {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::request_add_group ()";
}

sub save_node {
   my ($self, $node) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::save_node ($node)";
}

sub remove_node {
   my ($self, $node) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::remove_node ($node)";
}

sub save_account {
   my ($self, $account) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Blist::save_account ($account)";
}


1
