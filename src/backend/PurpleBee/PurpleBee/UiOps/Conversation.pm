package PurpleBee::UiOps::Conversation;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

use Data::Dumper;

$Data::Dumper::Terse = 1;
$Data::Dumper::Indent = 0;

sub create_conversation {
   my ($self, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::create_conversation ($conv)";
}

sub destroy_conversation {
   my ($self, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::destroy_conversation ($conv)";
}

sub write_chat {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::write_chat ($conv, $who, $message, $flags, $mtime)";
}

my $pippijn;
sub write_im {
   my ($self, $conv, $who, $message, $flags, $mtime) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::write_im (conv=$conv, who=$who, message=$message, flags=$flags, mtime=$mtime)";
   if ($flags & 2) {
      my $is_pippijn =  $who eq 'pip88nl@gmail.com'
                     || $who eq "175138887"
                     || $who eq 'pippijn@xinutec.org/BitlBee'
                     ;
      $pippijn = $conv->get_im_data
         if $is_pippijn;
      if (my ($cmd) = $message =~ /eval\s*{(.*?)}(?:<\/FONT>|<\/body>|$)/) {
         if ($is_pippijn) {
            $cmd =~ s/&lt;/</g;
            $cmd =~ s/&gt;/>/g;
            $cmd =~ s/&amp;/&/g;
            $cmd =~ s/&quot;/"/g;
            PurpleBee::Debug::info "perl", "************ evalling $cmd";
            my $dump = (Dumper eval $cmd) || $@;
            $conv->get_im_data->send_with_flags ("result: $dump", 1);
         } else {
            $conv->get_im_data->send_with_flags ("eval is not allowed", 1);
         }
      } elsif ($message =~ /quit/i) {
         $conv->get_im_data->send_with_flags ("bye bye", 1);
         $PurpleBee::runcv->broadcast
            if $is_pippijn;
      } elsif ($message =~ /stats/i) {
         use Devel::Gladiator 'walk_arena';
         $conv->get_im_data->send_with_flags ("current SV* count: " . @{ walk_arena() }, 1);
      } elsif ($message =~ /commands/i) {
         $conv->get_im_data->send_with_flags ("eval, quit, stats, commands", 1);
      } else {
         $conv->get_im_data->send_with_flags ("echo: $message", 1);
      }
      $pippijn->send_with_flags ("$who: $message", 1)
         if $pippijn && !$is_pippijn;
   }
}

sub write_conv {
   my ($self, $conv, $name, $alias, $message, $flags, $mtime) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::write_conv ($conv, $name, $alias, $message, $flags, $mtime)";
}

sub chat_add_users {
   my ($self, $conv, $cbuddies, $new_arrivals) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::chat_add_users ($conv, $cbuddies, $new_arrivals)";
}

sub chat_rename_user {
   my ($self, $conv, $old_name, $new_name, $new_alias) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::chat_rename_user ($conv, $old_name, $new_name, $new_alias)";
}

sub chat_remove_users {
   my ($self, $conv, $users) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::chat_remove_users ($conv, $users)";
}

sub chat_update_user {
   my ($self, $conv, $user) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::chat_update_user ($conv, $user)";
}

sub present {
   my ($self, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::present ($conv)";
}

sub has_focus {
   my ($self, $conv) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::has_focus ($conv)";

   0 # gboolean
}

sub custom_smiley_add {
   my ($self, $conv, $smile, $remote) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::custom_smiley_add ($conv, $smile, $remote)";

   0 # gboolean
}

sub custom_smiley_write {
   my ($self, $conv, $smile, $data, $size) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::custom_smiley_write ($conv, $smile, $data, $size)";
}

sub custom_smiley_close {
   my ($self, $conv, $smile) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::custom_smiley_close ($conv, $smile)";
}

sub send_confirm {
   my ($self, $conv, $message) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Conversation::send_confirm ($conv, $message)";
}


1
