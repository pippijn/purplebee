package PurpleBee;

use common::sense;

use AnyEvent;

use PurpleBee::Ops::Account;
use PurpleBee::Ops::Blist;
use PurpleBee::Ops::Connection;
use PurpleBee::Ops::Conversation;
use PurpleBee::Ops::Core;
use PurpleBee::Ops::Debug;
use PurpleBee::Ops::DnsQuery;
use PurpleBee::Ops::EventLoop;
use PurpleBee::Ops::Idle;
use PurpleBee::Ops::Notify;
use PurpleBee::Ops::Privacy;
use PurpleBee::Ops::Request;
use PurpleBee::Ops::Roomlist;
use PurpleBee::Ops::Sound;
use PurpleBee::Ops::Whiteboard;
use PurpleBee::Ops::Xfer;

our $runcv = AnyEvent->condvar;

sub main {
   my ($self, $username, $password, $protocol) = @_;
   my $timer = AnyEvent->timer (after => 60, cb => sub { $runcv->broadcast });
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
