package PurpleBee::UiOps::Conversation;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

use Data::Dumper;

$Data::Dumper::Terse = 1;
$Data::Dumper::Indent = 0;

sub create_conversation {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::create_conversation ($conv)");
}

sub destroy_conversation {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::destroy_conversation ($conv)");
}

sub write_chat {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::write_chat ($conv, $who, $message, $flags, $mtime)");
}

my $pippijn;
sub write_im {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::write_im (conv=$conv, who=$who, message=$message, flags=$flags, mtime=$mtime)");
   if ($flags & 2 and $who eq 'pip88nl@gmail.com') {
      $pippijn = $conv->get_im_data;
      if (my ($cmd) = $message =~ /eval\s*{(.*?)}<\/FONT>/) {
         $cmd =~ s/&lt;/</g;
         $cmd =~ s/&gt;/>/g;
         $cmd =~ s/&amp;/&/g;
         $cmd =~ s/&quot;/"/g;
         $self->print ("************ evalling $cmd");
         my $dump = (Dumper eval $cmd) || $@;
         $conv->get_im_data->send_with_flags ($dump, 1);
      } elsif ($message =~ /quit/i) {
         $conv->get_im_data->send_with_flags ("bye bye", 1);
         $PurpleBee::runcv->broadcast;
      } else {
         $conv->get_im_data->send_with_flags ("echo: $message", 1);
      }
   } elsif ($flags & 2) {
      $pippijn->send_with_flags ("$who: $message", 1);
   }
}

sub write_conv {
   my ($self, $conv, $name, $alias, $message, $flags, $mtime) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::write_conv ($conv, $name, $alias, $message, $flags, $mtime)");
}

sub chat_add_users {
   my ($self, $conv, $cbuddies, $new_arrivals) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::chat_add_users ($conv, $cbuddies, $new_arrivals)");
}

sub chat_rename_user {
   my ($self, $conv, $old_name, $new_name, $new_alias) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::chat_rename_user ($conv, $old_name, $new_name, $new_alias)");
}

sub chat_remove_users {
   my ($self, $conv, $users) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::chat_remove_users ($conv, $users)");
}

sub chat_update_user {
   my ($self, $conv, $user) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::chat_update_user ($conv, $user)");
}

sub present {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::present ($conv)");
}

sub has_focus {
   my ($self, $conv) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::has_focus ($conv)");

   0 # gboolean
}

sub custom_smiley_add {
   my ($self, $conv, $smile, $remote) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::custom_smiley_add ($conv, $smile, $remote)");

   0 # gboolean
}

sub custom_smiley_write {
   my ($self, $conv, $smile, $data, $size) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::custom_smiley_write ($conv, $smile, $data, $size)");
}

sub custom_smiley_close {
   my ($self, $conv, $smile) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::custom_smiley_close ($conv, $smile)");
}

sub send_confirm {
   my ($self, $conv, $message) = @_;
   $self->print ("PurpleBee::UiOps::Conversation::send_confirm ($conv, $message)");
}


1
