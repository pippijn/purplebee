package PurpleBee::UiOps::Debug;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

use Time::HiRes 'time';

my @names = qw(ALL MISC INFO WARNING ERROR FATAL);

my $start = time;

sub print {
   my ($self, $level, $category, $arg_s) = @_;
   printf "%.4f %s [%s]: %s", time - $start, $names[$level], $category, $arg_s;
}

sub is_enabled {
   my ($self, $level, $category) = @_;

   $category eq "ffi"
      or $category eq "closure"
      or $category eq "closure-trace"
      or $category eq "event"
      or $category eq "perl"
}


1
