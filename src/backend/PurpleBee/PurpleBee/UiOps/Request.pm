package PurpleBee::UiOps::Request;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

my %requests;

sub close_request {
   my ($self, $type, $ui_handle) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::close_request ($type, $ui_handle)";

   undef $requests{$type}[$ui_handle]
}

sub add_request {
   my ($self, $type, $request) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::add_request ($type, $request)";

   for my $ui_handle (0 .. @{ $requests{$type} }) {
      # If $ui_handle is currently free,
      if (!$requests{$type}[$ui_handle]) {
         # put the request into the array
         $requests{$type}[$ui_handle] = $request;
         PurpleBee::Debug::info "perl", "added request at $ui_handle";

         return $ui_handle
      }
   }

   die "impossible"
}

sub request_input {
   my ( $self, $title, $primary, $secondary, $default_value
      , $multiline, $masked, $hint, $ok_text, $ok_cb
      , $cancel_text, $cancel_cb, $account, $who, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::request_input ($title, $primary, $secondary, $default_value, $multiline, $masked, $hint, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv)";

   undef # void*
}

sub request_choice {
   my ( $self, $title, $primary, $secondary, $default_value
      , $ok_text, $ok_cb, $cancel_text, $cancel_cb
      , $account, $who, $conv, $choices) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::request_choice ($title, $primary, $secondary, $default_value, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv, $choices)";

   undef # void*
}

sub request_action {
   my ( $self, $title, $primary, $secondary, $default_action
      , $account, $who, $conv, $texts, $actions) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::request_action ($title, $primary, $secondary, $default_action, $account, $who, $conv, $texts, $actions)";

   # TODO: hardcoded default taking choice 0
   my $ui_handle;
   $ui_handle = add_request $self, PurpleBee::Request::Type::ACTION, AnyEvent->timer (
      after => 2,
      cb => sub {
         PurpleBee::Debug::info "perl", "executing action $ui_handle";
         $actions->[0]->invoke (0);
         close_request $self, PurpleBee::Request::Type::ACTION, $ui_handle
      },
   );

   $ui_handle
}

sub request_fields {
   my ( $self, $title, $primary, $secondary, $fields, $ok_text
      , $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::request_fields ($title, $primary, $secondary, $fields, $ok_text, $ok_cb, $cancel_text, $cancel_cb, $account, $who, $conv)";

   undef # void*
}

sub request_file {
   my ( $self, $title, $filename, $savedialog, $ok_cb
      , $cancel_cb, $account, $who, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::request_file ($title, $filename, $savedialog, $ok_cb, $cancel_cb, $account, $who, $conv)";

   undef # void*
}

sub request_folder {
   my ($self, $title, $dirname, $ok_cb, $cancel_cb, $account, $who, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Request::request_folder ($title, $dirname, $ok_cb, $cancel_cb, $account, $who, $conv)";

   undef # void*
}


1
