package PurpleBee::UiOps::Request;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub request_input {
   my ($self, $title, $primary, $secondary, $default_value, $multiline, $masked, $hint, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv, $user_data) = @_;
   $self->print ("PurpleBee::UiOps::Request::request_input ($title, $primary, $secondary, $default_value, $multiline, $masked, $hint, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv, $user_data)\n");

   undef # void*
}

sub request_choice {
   my ($self, $title, $primary, $secondary, $default_value, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv, $user_data, $choices) = @_;
   $self->print ("PurpleBee::UiOps::Request::request_choice ($title, $primary, $secondary, $default_value, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv, $user_data, $choices)\n");

   undef # void*
}

sub request_action {
   my ($self, $title, $primary, $secondary, $default_action, $account, $who, $conv, $user_data, $action_count, $actions) = @_;
   $self->print ("PurpleBee::UiOps::Request::request_action ($title, $primary, $secondary, $default_action, $account, $who, $conv, $user_data, $action_count, $actions)\n");

   undef # void*
}

sub request_fields {
   my ($self, $title, $primary, $secondary, $fields, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv, $user_data) = @_;
   $self->print ("PurpleBee::UiOps::Request::request_fields ($title, $primary, $secondary, $fields, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv, $user_data)\n");

   undef # void*
}

sub request_file {
   my ($self, $title, $filename, $savedialog, $ok_cb, $cancel_cb, $account, $who, $conv, $user_data) = @_;
   $self->print ("PurpleBee::UiOps::Request::request_file ($title, $filename, $savedialog, $ok_cb, $cancel_cb, $account, $who, $conv, $user_data)\n");

   undef # void*
}

sub close_request {
   my ($self, $type, $ui_handle) = @_;
   $self->print ("PurpleBee::UiOps::Request::close_request ($type, $ui_handle)\n");
}

sub request_folder {
   my ($self, $title, $dirname, $ok_cb, $cancel_cb, $account, $who, $conv, $user_data) = @_;
   $self->print ("PurpleBee::UiOps::Request::request_folder ($title, $dirname, $ok_cb, $cancel_cb, $account, $who, $conv, $user_data)\n");

   undef # void*
}


1
