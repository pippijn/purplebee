package PurpleBee::Ops::Debug;

use common::sense;

sub print {
   my ($self, $level, $category, $arg_s) = @_;
   print "PurpleBee::Ops::Debug::print ($level, $category, $arg_s)\n";
}

sub is_enabled {
   my ($self, $level, $category) = @_;
   print "PurpleBee::Ops::Debug::is_enabled ($level, $category)\n";

   0 # gboolean
}


1
