package PurpleBee::UiOps::Sound;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub init {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Sound::init ()";
}

sub uninit {
   my ($self) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Sound::uninit ()";
}

sub play_file {
   my ($self, $filename) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Sound::play_file ($filename)";
}

sub play_event {
   my ($self, $event) = @_;
   PurpleBee::Debug::info "perl", "PurpleBee::UiOps::Sound::play_event ($event)";
}


1
