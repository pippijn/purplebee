package PurpleBee::Ops::Conversation;

use common::sense;

sub create_conversation {
   my ($self, $conv) = @_;
   print "PurpleBee::Ops::Conversation::create_conversation\n";
}

sub destroy_conversation {
   my ($self, $conv) = @_;
   print "PurpleBee::Ops::Conversation::destroy_conversation\n";
}

sub write_chat {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   print "PurpleBee::Ops::Conversation::write_chat\n";
}

sub write_im {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   print "PurpleBee::Ops::Conversation::write_im\n";
}

sub write_conv {
   my ($self, $conv, $name, $alias, $message, $flags, $mtime) = @_;
   print "PurpleBee::Ops::Conversation::write_conv\n";
}

sub chat_add_users {
   my ($self, $conv, $cbuddies, $new_arrivals) = @_;
   print "PurpleBee::Ops::Conversation::chat_add_users\n";
}

sub chat_rename_user {
   my ($self, $conv, $old_name, $new_name, $new_alias) = @_;
   print "PurpleBee::Ops::Conversation::chat_rename_user\n";
}

sub chat_remove_users {
   my ($self, $conv, $users) = @_;
   print "PurpleBee::Ops::Conversation::chat_remove_users\n";
}

sub chat_update_user {
   my ($self, $conv, $user) = @_;
   print "PurpleBee::Ops::Conversation::chat_update_user\n";
}

sub present {
   my ($self, $conv) = @_;
   print "PurpleBee::Ops::Conversation::present\n";
}

sub has_focus {
   my ($self, $conv) = @_;
   print "PurpleBee::Ops::Conversation::has_focus\n";

   0 # gboolean
}

sub custom_smiley_add {
   my ($self, $conv, $smile, $remote) = @_;
   print "PurpleBee::Ops::Conversation::custom_smiley_add\n";

   0 # gboolean
}

sub custom_smiley_write {
   my ($self, $conv, $smile, $data, $size) = @_;
   print "PurpleBee::Ops::Conversation::custom_smiley_write\n";
}

sub custom_smiley_close {
   my ($self, $conv, $smile) = @_;
   print "PurpleBee::Ops::Conversation::custom_smiley_close\n";
}

sub send_confirm {
   my ($self, $conv, $message) = @_;
   print "PurpleBee::Ops::Conversation::send_confirm\n";
}


1
