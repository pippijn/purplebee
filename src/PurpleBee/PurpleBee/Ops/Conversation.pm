package PurpleBee::Ops::Conversation;

use common::sense;

use Data::Dumper;

$Data::Dumper::Terse = 1;
$Data::Dumper::Indent = 0;

sub create_conversation {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::Ops::Conversation::create_conversation ($conv)\n");
}

sub destroy_conversation {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::Ops::Conversation::destroy_conversation ($conv)\n");
}

sub write_chat {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   $self->print ("PurpleBee::Ops::Conversation::write_chat ($conv, $who, $message, $flags, $mtime)\n");
}

sub write_im {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   $self->print ("PurpleBee::Ops::Conversation::write_im (conv=$conv, who=$who, message=$message, flags=$flags, mtime=$mtime)\n");
   if ($flags & 2) {
      if ($who eq 'pip88nl@gmail.com' and my ($cmd) = $message =~ /eval\s*{(.*?)}<\/FONT>/) {
         my $ret = eval $cmd;
         my $dump = Dumper $ret;
         $conv->get_im_data->send_with_flags ($dump, 1);
      } elsif ($message =~ /quit/i) {
         $conv->get_im_data->send_with_flags ("bye bye", 1);
         $PurpleBee::runcv->broadcast;
      } else {
         $conv->get_im_data->send_with_flags ("echo: $message", 1);
      }
   }
}

sub write_conv {
   my ($self, $conv, $name, $alias, $message, $flags, $mtime) = @_;
   $self->print ("PurpleBee::Ops::Conversation::write_conv ($conv, $name, $alias, $message, $flags, $mtime)\n");
}

sub chat_add_users {
   my ($self, $conv, $cbuddies, $new_arrivals) = @_;
   $self->print ("PurpleBee::Ops::Conversation::chat_add_users ($conv, $cbuddies, $new_arrivals)\n");
}

sub chat_rename_user {
   my ($self, $conv, $old_name, $new_name, $new_alias) = @_;
   $self->print ("PurpleBee::Ops::Conversation::chat_rename_user ($conv, $old_name, $new_name, $new_alias)\n");
}

sub chat_remove_users {
   my ($self, $conv, $users) = @_;
   $self->print ("PurpleBee::Ops::Conversation::chat_remove_users ($conv, $users)\n");
}

sub chat_update_user {
   my ($self, $conv, $user) = @_;
   $self->print ("PurpleBee::Ops::Conversation::chat_update_user ($conv, $user)\n");
}

sub present {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::Ops::Conversation::present ($conv)\n");
}

sub has_focus {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::Ops::Conversation::has_focus ($conv)\n");

   0 # gboolean
}

sub custom_smiley_add {
   my ($self, $conv, $smile, $remote) = @_;
   $self->print ("PurpleBee::Ops::Conversation::custom_smiley_add ($conv, $smile, $remote)\n");

   0 # gboolean
}

sub custom_smiley_write {
   my ($self, $conv, $smile, $data, $size) = @_;
   $self->print ("PurpleBee::Ops::Conversation::custom_smiley_write ($conv, $smile, $data, $size)\n");
}

sub custom_smiley_close {
   my ($self, $conv, $smile) = @_;
   $self->print ("PurpleBee::Ops::Conversation::custom_smiley_close ($conv, $smile)\n");
}

sub send_confirm {
   my ($self, $conv, $message) = @_;
   $self->print ("PurpleBee::Ops::Conversation::send_confirm ($conv, $message)\n");
}


1
