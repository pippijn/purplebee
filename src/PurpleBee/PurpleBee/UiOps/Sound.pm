package PurpleBee::UiOps::Sound;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub init {
   my ($self) = @_;
   $self->print ("PurpleBee::UiOps::Sound::init ()\n");
}

sub uninit {
   my ($self) = @_;
   $self->print ("PurpleBee::UiOps::Sound::uninit ()\n");
}

sub play_file {
   my ($self, $filename) = @_;
   $self->print ("PurpleBee::UiOps::Sound::play_file ($filename)\n");
}

sub play_event {
   my ($self, $event) = @_;
   $self->print ("PurpleBee::UiOps::Sound::play_event ($event)\n");
}


1
