package PurpleBee::UiOps::Notify;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub notify_message {
   my ($self, $type, $title, $primary, $secondary) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_message ($type, $title, $primary, $secondary)";

   undef # void*
}

sub notify_email {
   my ($self, $gc, $subject, $from, $to, $url) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_email ($gc, $subject, $from, $to, $url)";

   undef # void*
}

sub notify_emails {
   my ($self, $gc, $count, $detailed, $subjects, $froms, $tos, $urls) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_emails ($gc, $count, $detailed, $subjects, $froms, $tos, $urls)";

   undef # void*
}

sub notify_formatted {
   my ($self, $title, $primary, $secondary, $text) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_formatted ($title, $primary, $secondary, $text)";

   undef # void*
}

sub notify_searchresults {
   my ($self, $gc, $title, $primary, $secondary, $results, $user_data) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_searchresults ($gc, $title, $primary, $secondary, $results, $user_data)";

   undef # void*
}

sub notify_searchresults_new_rows {
   my ($self, $gc, $results, $data) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_searchresults_new_rows ($gc, $results, $data)";
}

sub notify_userinfo {
   my ($self, $gc, $who, $user_info) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_userinfo ($gc, $who, $user_info)";

   undef # void*
}

sub notify_uri {
   my ($self, $uri) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::notify_uri ($uri)";

   undef # void*
}

sub close_notify {
   my ($self, $type, $ui_handle) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Notify::close_notify ($type, $ui_handle)";
}


1
