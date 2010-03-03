package PurpleBee::Ops::Account;

use common::sense;

sub notify_added {
   my ($self, $account, $remote_user, $id, $alias, $message) = @_;
   $self->print ("PurpleBee::Ops::Account::notify_added ($account, $remote_user, $id, $alias, $message)\n");
}

sub status_changed {
   my ($self, $account, $status) = @_;
   $self->print ("PurpleBee::Ops::Account::status_changed ($account, $status)\n");
}

sub request_add {
   my ($self, $account, $remote_user, $id, $alias, $message) = @_;
   $self->print ("PurpleBee::Ops::Account::request_add ($account, $remote_user, $id, $alias, $message)\n");
}

sub request_authorize {
   my ($self, $account, $remote_user, $id, $alias, $message, $on_list, $authorize_cb, $deny_cb) = @_;
   $self->print ("PurpleBee::Ops::Account::request_authorize ($account, $remote_user, $id, $alias, $message, $on_list, $authorize_cb, $deny_cb)\n");

   undef # void*
}

sub close_account_request {
   my ($self, $ui_handle) = @_;
   $self->print ("PurpleBee::Ops::Account::close_account_request ($ui_handle)\n");
}


1
