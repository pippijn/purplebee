# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.
package PurpleBee;

use common::sense;

BEGIN {
   eval {
      require EV;
      $EV::DIED = sub { PurpleBee::Debug::fatal "event", "error in event: $@"; exit };
   }
}

#sub boot_all {
   #my ($pkg) = @_;
   #$pkg =~ /::/ and $pkg->bootstrap;
   #print "booting $pkg\n";
   #my $symtab = \%{$pkg . '::'};
   #for my $sym (grep { /::$/ } keys %$symtab) {
      #my ($subpkg) = $sym =~ /(.*)::$/;
      #boot_all ("${pkg}::$subpkg");
   #}
#}

#boot_all "PurpleBee";
#kill 'TERM', $$;

use AnyEvent;
#use AnyEvent::MP;

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

#configure;

our $runcv = AnyEvent->condvar;

$SIG{INT} = sub { $runcv->broadcast };

sub main {
   my ($self) = @_;

   #my $timer = AnyEvent->timer (after => 60, cb => sub { $runcv->broadcast });
   PurpleBee::Debug::info "perl",
   sprintf ( "Running libpurple %s (single instance = %d)"
      , PurpleBee::Core::get_version
      , PurpleBee::Core::ensure_single_instance
   );
   for (
      ['purplebee-test@xinutec.org', 'purplebee-test', 'prpl-jabber'],
      ['621180987', 'B1neMaya', 'prpl-icq'],
   ) {
      my ($username, $password, $protocol) = @$_;
      my $account = PurpleBee::Account::new $username, $protocol
         or die;
      $account->set_bool ("use_clientlogin", 0);
      $account->set_password ($password);
      $account->set_enabled ($self->package, 1);
      PurpleBee::Accounts::add $account;
   }
   my $status = PurpleBee::SavedStatus::new undef, 2
      or die;
   $status->activate;
   $runcv->wait;
}

1
