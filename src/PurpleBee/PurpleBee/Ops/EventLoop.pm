package PurpleBee::Ops::EventLoop;

use common::sense;

use AnyEvent;

my @timeouts;
# TODO add a second array which contains removed indexes
# to optimise searching for free slots in @timeouts

#
# Creates a callback timer.
#
# The timer will repeat until the function returns @c FALSE. The
# first call will be at the end of the first interval.
#
# If the timer is in a multiple of seconds, use purple_timeout_add_seconds()
# instead as it allows UIs to group timers for power efficiency.
#
# @param interval      The time between calls of the function, in
#                      milliseconds.
# @param callback      The function closure to call.
# @return A handle to the timer which can be passed to
#         purple_timeout_remove() to remove the timer.
#

sub timeout_add {
   my ($self, $interval, $callback) = @_;
   print "PurpleBee::Ops::EventLoop::timeout_add ($interval, $callback)\n";

   for my $handle (0 .. @timeouts) { # find the next free @timeouts-index
      if (!$timeouts[$handle]) {
         $timeouts[$handle] = AnyEvent->timer (
            after       => $interval,
            interval    => $interval,
            cb          => sub { print "timeout $handle = $callback\n"; $callback->call },
         );

         print "timeout_add = $handle\n";
         return $handle
      }
   }

   die "didn't find free spot"
}

# Removes a timeout handler.
#
# @param handle The handle, as returned by purple_timeout_add().
#
# @return @c TRUE if the handler was successfully removed.
#

sub timeout_remove {
   my ($self, $handle) = @_;
   print "PurpleBee::Ops::EventLoop::timeout_remove ($handle)\n";

   if ($timeouts[$handle]) {
      undef $timeouts[$handle];
      return 1
   }

   0 # gboolean
}

# Creates a callback timer.
#
# The timer will repeat until the function returns @c FALSE. The
# first call will be at the end of the first interval.
#
# This function allows UIs to group timers for better power efficiency.  For
# this reason, @a interval may be rounded by up to a second.
#
# @param interval       The time between calls of the function, in
#                       seconds.
# @param callback       The function closure to call.
# @return A handle to the timer which can be passed to
#         purple_timeout_remove() to remove the timer.
#
# @since 2.1.0

sub timeout_add_seconds {
   my ($self, $interval, $callback) = @_;
   print "PurpleBee::Ops::EventLoop::timeout_add_seconds ($interval, $callback)\n";

   for my $handle (0 .. @timeouts) { # find the next free @timeouts-index
      if (!$timeouts[$handle]) {
         $timeouts[$handle] = AnyEvent->timer (
            after       => $interval,
            interval    => $interval,
            cb          => sub {
               print "timeout_seconds $handle = $callback\n";
               timeout_remove $handle
                  unless $callback->call
            },
         );

         print "timeout_add_seconds = $handle\n";
         return $handle
      }
   }

   die "didn't find free spot"
}


#### INPUT HANDLERS
my @inputhandlers;

use constant {
   IO_READ  => 1 << 0,
   IO_WRITE => 1 << 1,
};

# Adds an input handler.
#
# @param fd        The input file descriptor.
# @param cond      The condition type.
# @param func      The callback function for data.
# @param user_data User-specified data.
#
# @return The resulting handle (will be greater than 0).
# @see g_io_add_watch_full

sub input_add {
   my ($self, $fd, $cond, $callback) = @_;
   print "PurpleBee::Ops::EventLoop::input_add ($fd, $cond, $callback)\n";

   for my $handle (0 .. @inputhandlers) { # find the next free @inputhandlers-index
      if (!$inputhandlers[$handle]) {
         $inputhandlers[$handle]{read} = AnyEvent->io (
            fd   => $fd,
            poll => 'r',
            cb   => sub { print "input[r] $handle = $callback\n"; $callback->call }
         ) if $cond & IO_READ;

         $inputhandlers[$handle]{write} = AnyEvent->io (
            fd   => $fd,
            poll => 'w',
            cb   => sub { print "input[w] $handle = $callback\n"; $callback->call }
         ) if $cond & IO_WRITE;

         print "input_add = $handle\n";
         return $handle # guint
      }
   }

   die "didn't find free spot"
}

# Removes an input handler.
#
# @param handle The handle of the input handler. Note that this is the return
#               value from purple_input_add(), <i>not</i> the file descriptor.

sub input_remove {
   my ($self, $handle) = @_;
   print "PurpleBee::Ops::EventLoop::input_remove ($handle)\n";

   if ($inputhandlers[$handle]) {
      undef $inputhandlers[$handle];
      return 1
   }

   0 # gboolean
}

# Get the current error status for an input.
#
# The return value and error follow getsockopt() with a level of SOL_SOCKET and an
# option name of SO_ERROR, and this is how the error is determined if the UI does not
# implement the input_get_error UI op.
#
# @param fd        The input file descriptor.
# @param error     A pointer to an @c int which on return will have the error, or
#                  @c 0 if no error.
#
# @return @c 0 if there is no error; @c -1 if there is an error, in which case
#         @a errno will be set.

sub input_get_error {
   my ($self, $fd, $error) = @_;
   print "PurpleBee::Ops::EventLoop::input_get_error ($fd, $error)\n";

   0 # int
}

1
