package PurpleBee::Ops::Conversation;

use common::sense;

sub create_conversation {
   my ($conv) = @_;
   print "PurpleBee::Ops::Conversation::create_conversation\n";
}

sub destroy_conversation {
   my ($conv) = @_;
   print "PurpleBee::Ops::Conversation::destroy_conversation\n";
}

sub write_chat {
   my ($conv, $who, $message, $flags, $mtime) = @_;
   print "PurpleBee::Ops::Conversation::write_chat\n";
}

sub write_im {
   my ($conv, $who, $message, $flags, $mtime) = @_;
   print "PurpleBee::Ops::Conversation::write_im\n";
}

sub write_conv {
   my ($conv, $name, $alias, $message, $flags, $mtime) = @_;
   print "PurpleBee::Ops::Conversation::write_conv\n";
}

sub chat_add_users {
   my ($conv, $cbuddies, $new_arrivals) = @_;
   print "PurpleBee::Ops::Conversation::chat_add_users\n";
}

sub chat_rename_user {
   my ($conv, $old_name, $new_name, $new_alias) = @_;
   print "PurpleBee::Ops::Conversation::chat_rename_user\n";
}

sub chat_remove_users {
   my ($conv, $users) = @_;
   print "PurpleBee::Ops::Conversation::chat_remove_users\n";
}

sub chat_update_user {
   my ($conv, $user) = @_;
   print "PurpleBee::Ops::Conversation::chat_update_user\n";
}

sub present {
   my ($conv) = @_;
   print "PurpleBee::Ops::Conversation::present\n";
}

sub has_focus {
   my ($conv) = @_;
   print "PurpleBee::Ops::Conversation::has_focus\n";

   0 # gboolean
}

sub custom_smiley_add {
   my ($conv, $smile, $remote) = @_;
   print "PurpleBee::Ops::Conversation::custom_smiley_add\n";

   0 # gboolean
}

sub custom_smiley_write {
   my ($conv, $smile, $data, $size) = @_;
   print "PurpleBee::Ops::Conversation::custom_smiley_write\n";
}

sub custom_smiley_close {
   my ($conv, $smile) = @_;
   print "PurpleBee::Ops::Conversation::custom_smiley_close\n";
}

sub send_confirm {
   my ($conv, $message) = @_;
   print "PurpleBee::Ops::Conversation::send_confirm\n";
}


1
