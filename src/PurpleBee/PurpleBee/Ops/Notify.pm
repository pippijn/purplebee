package PurpleBee::Ops::Notify;

use common::sense;

sub notify_message {
   my ($self, $type, $title, $primary, $secondary) = @_;
   print "PurpleBee::Ops::Notify::notify_message ($type, $title, $primary, $secondary)\n";

   undef # void*
}

sub notify_email {
   my ($self, $gc, $subject, $from, $to, $url) = @_;
   print "PurpleBee::Ops::Notify::notify_email ($gc, $subject, $from, $to, $url)\n";

   undef # void*
}

sub notify_emails {
   my ($self, $gc, $count, $detailed, $subjects, $froms, $tos, $urls) = @_;
   print "PurpleBee::Ops::Notify::notify_emails ($gc, $count, $detailed, $subjects, $froms, $tos, $urls)\n";

   undef # void*
}

sub notify_formatted {
   my ($self, $title, $primary, $secondary, $text) = @_;
   print "PurpleBee::Ops::Notify::notify_formatted ($title, $primary, $secondary, $text)\n";

   undef # void*
}

sub notify_searchresults {
   my ($self, $gc, $title, $primary, $secondary, $results, $user_data) = @_;
   print "PurpleBee::Ops::Notify::notify_searchresults ($gc, $title, $primary, $secondary, $results, $user_data)\n";

   undef # void*
}

sub notify_searchresults_new_rows {
   my ($self, $gc, $results, $data) = @_;
   print "PurpleBee::Ops::Notify::notify_searchresults_new_rows ($gc, $results, $data)\n";
}

sub notify_userinfo {
   my ($self, $gc, $who, $user_info) = @_;
   print "PurpleBee::Ops::Notify::notify_userinfo ($gc, $who, $user_info)\n";

   undef # void*
}

sub notify_uri {
   my ($self, $uri) = @_;
   print "PurpleBee::Ops::Notify::notify_uri ($uri)\n";

   undef # void*
}

sub close_notify {
   my ($self, $type, $ui_handle) = @_;
   print "PurpleBee::Ops::Notify::close_notify ($type, $ui_handle)\n";
}


1
