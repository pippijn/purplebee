package PurpleBee::Ops::Privacy;

use common::sense;

sub permit_added {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::Ops::Privacy::permit_added ($account, $name)\n");
}

sub permit_removed {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::Ops::Privacy::permit_removed ($account, $name)\n");
}

sub deny_added {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::Ops::Privacy::deny_added ($account, $name)\n");
}

sub deny_removed {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::Ops::Privacy::deny_removed ($account, $name)\n");
}


1
