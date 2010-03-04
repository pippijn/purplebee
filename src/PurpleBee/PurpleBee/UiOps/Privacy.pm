package PurpleBee::UiOps::Privacy;

use common::sense;

sub permit_added {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::UiOps::Privacy::permit_added ($account, $name)\n");
}

sub permit_removed {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::UiOps::Privacy::permit_removed ($account, $name)\n");
}

sub deny_added {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::UiOps::Privacy::deny_added ($account, $name)\n");
}

sub deny_removed {
   my ($self, $account, $name) = @_;
   $self->print ("PurpleBee::UiOps::Privacy::deny_removed ($account, $name)\n");
}


1
