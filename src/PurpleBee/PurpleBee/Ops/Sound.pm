package PurpleBee::Ops::Sound;

use common::sense;

sub init {
   my ($self) = @_;
   print "PurpleBee::Ops::Sound::init ()\n";
}

sub uninit {
   my ($self) = @_;
   print "PurpleBee::Ops::Sound::uninit ()\n";
}

sub play_file {
   my ($self, $filename) = @_;
   print "PurpleBee::Ops::Sound::play_file ($filename)\n";
}

sub play_event {
   my ($self, $event) = @_;
   print "PurpleBee::Ops::Sound::play_event ($event)\n";
}


1
