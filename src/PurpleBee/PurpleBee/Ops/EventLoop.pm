package PurpleBee::Ops::EventLoop;

use common::sense;

use AnyEvent;

my @timeouts;
# TODO add a second array which contains removed indexes
# to optimise searching for free slots in @timeouts

sub timeout_add {
   my ($interval, $callback) = @_;

   for my $handle (0 .. @timeouts - 1) { # find the next free @timeouts-index
      if (!$timeouts[$handle]) {
         $timeouts[$handle] = AnyEvent->timer (
            after => $interval,
            interval => $interval,
            cb => sub { $callback->call () }
         );
         return $handle
      }
   }
}

sub timeout_remove {
   my ($handle) = @_;
   if ($timeouts[$handle]) {
      undef $timeouts[$handle];
      return 1
   }

   0 # gboolean
}

sub input_add {
   my ($fd, $cond, $func, $user_data) = @_;
   print "PurpleBee::Ops::EventLoop::input_add\n";

   0 # guint
}

sub input_remove {
   my ($handle) = @_;
   print "PurpleBee::Ops::EventLoop::input_remove\n";

   0 # gboolean
}

sub input_get_error {
   my ($fd, $error) = @_;
   print "PurpleBee::Ops::EventLoop::input_get_error\n";

   0 # int
}

sub timeout_add_seconds {
   my ($interval, $function, $data) = @_;
   print "PurpleBee::Ops::EventLoop::timeout_add_seconds\n";

   for my $handle (0 .. @timeouts - 1) { # find the next free @timeouts-index
      if (!$timeouts[$handle]) {
         $timeouts[$handle] = AnyEvent->timer (
            after => $interval,
            interval => $interval,
            cb => sub {
               timeout_remove $handle
                  if ($function->call () == 0)
            }
         );
         return $handle # guint
      }
   }
}


1
