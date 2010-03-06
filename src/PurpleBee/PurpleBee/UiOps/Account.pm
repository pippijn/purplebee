package PurpleBee::UiOps::Account;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub notify_added {
   my ($self, $account, $remote_user, $id, $alias, $message) = @_;
   $self->print ("PurpleBee::UiOps::Account::notify_added ($account, $remote_user, $id, $alias, $message)");
}

sub status_changed {
   my ($self, $account, $status) = @_;
   $self->print ("PurpleBee::UiOps::Account::status_changed ($account, $status)");
}

sub request_add {
   my ($self, $account, $remote_user, $id, $alias, $message) = @_;
   $self->print ("PurpleBee::UiOps::Account::request_add ($account, $remote_user, $id, $alias, $message)");
}

sub request_authorize {
   my ($self, $account, $remote_user, $id, $alias, $message, $on_list, $authorize_cb, $deny_cb) = @_;
   $self->print ("PurpleBee::UiOps::Account::request_authorize ($account, $remote_user, $id, $alias, $message, $on_list, $authorize_cb, $deny_cb)");

   undef # void*
}

sub close_account_request {
   my ($self, $ui_handle) = @_;
   $self->print ("PurpleBee::UiOps::Account::close_account_request ($ui_handle)");
}


1
