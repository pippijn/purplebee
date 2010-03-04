package PurpleBee::UiOps::Debug;

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
