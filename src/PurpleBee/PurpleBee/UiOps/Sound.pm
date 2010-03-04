package PurpleBee::UiOps::Sound;

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
