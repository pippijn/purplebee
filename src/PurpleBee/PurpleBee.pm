package PurpleBee;

use common::sense;
use AnyEvent;

use PurpleBee::Ops::Conversation;
use PurpleBee::Ops::Core;
use PurpleBee::Ops::EventLoop;

our $runcb = AnyEvent->condvar;

sub main {
   #my $timer = AnyEvent->timer (after => 10, cb => sub { $runcb->broadcast });
   $runcb->wait
}

1
