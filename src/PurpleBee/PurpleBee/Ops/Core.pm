package PurpleBee::Ops::Core;

use common::sense;

sub ui_prefs_init {
   my ($self) = @_;
   print "PurpleBee::Ops::Core::ui_prefs_init\n";
}

sub debug_ui_init {
   my ($self) = @_;
   print "PurpleBee::Ops::Core::debug_ui_init\n";
}

sub ui_init {
   my ($self) = @_;
   print "PurpleBee::Ops::Core::ui_init\n";
}

sub quit {
   my ($self) = @_;
   print "PurpleBee::Ops::Core::quit\n";
}

sub get_ui_info {
   my ($self) = @_;
   print "PurpleBee::Ops::Core::get_ui_info\n";

   undef # GHashTable*
}


1
