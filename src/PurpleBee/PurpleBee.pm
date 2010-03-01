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

our $runcb = AnyEvent->condvar;

sub main {
   my $timer = AnyEvent->timer (after => 10, cb => sub { $runcb->broadcast });
   printf "Running libpurple %s (single instance = %d)\n", purple_core_get_version, purple_core_ensure_single_instance;
   $runcb->wait;
}

1
