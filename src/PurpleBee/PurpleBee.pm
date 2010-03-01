package PurpleBee;

use common::sense;
use AnyEvent;

use PurpleBee::Ops::Conversation;
use PurpleBee::Ops::Core;
use PurpleBee::Ops::EventLoop;

our $runcb = AnyEvent->condvar;

sub main {
   $runcb->wait
}

1
