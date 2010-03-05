package PurpleBee::UiOps::Debug;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub print {
   my ($self, $level, $category, $arg_s) = @_;
   $self->print ("PurpleBee::UiOps::Debug::print ($level, $category, $arg_s)\n");
}

sub is_enabled {
   my ($self, $level, $category) = @_;
   $self->print ("PurpleBee::UiOps::Debug::is_enabled ($level, $category)\n");

   0 # gboolean
}


1
