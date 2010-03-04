package PurpleBee;

use common::sense;

use AnyEvent;

use PurpleBee::UiOps::Account;
use PurpleBee::UiOps::Blist;
use PurpleBee::UiOps::Connection;
use PurpleBee::UiOps::Conversation;
use PurpleBee::UiOps::Core;
use PurpleBee::UiOps::Debug;
use PurpleBee::UiOps::DnsQuery;
use PurpleBee::UiOps::EventLoop;
use PurpleBee::UiOps::Idle;
use PurpleBee::UiOps::Notify;
use PurpleBee::UiOps::Privacy;
use PurpleBee::UiOps::Request;
use PurpleBee::UiOps::Roomlist;
use PurpleBee::UiOps::Sound;
use PurpleBee::UiOps::Whiteboard;
use PurpleBee::UiOps::Xfer;

our $runcv = AnyEvent->condvar;

$|++;
open my $logfh, '>', 'perl.log'
   or die "Could not open log: $!";

sub print {
   my ($self, $msg) = @_;
   print $logfh $msg;
}

sub main {
   my ($self, $username, $password, $protocol) = @_;
   #my $timer = AnyEvent->timer (after => 60, cb => sub { $runcv->broadcast });
   printf "Running libpurple %s (single instance = %d)\n"
   	, PurpleBee::Core::get_version
        , PurpleBee::Core::ensure_single_instance
        ;
   my $account = PurpleBee::Account::new $username, $protocol
      or die;
   $account->set_password ($password);
   $account->set_enabled ($self->package, 1);
   my $status = PurpleBee::SavedStatus::new undef, 2
      or die;
   $status->activate;
   $runcv->wait;
}

1
