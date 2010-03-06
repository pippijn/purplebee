package PurpleBee::UiOps::EventLoop;
# Copyright © 2010 Pippijn van Steenhoven, Moritz Wilhelmy
# See COPYING.AGPL for licence information.

use common::sense;

use AnyEvent;
use Carp;

my @timeouts;
# TODO add a second array which contains removed indexes
# to optimise searching for free slots in @timeouts

=item timeout_remove($handle)

Removes a timeout handler.

$handle is a handle as returned by purple_timeout_add().

If the timer did not exist, this returns false. Otherwise, it returns true,
signifying that the timer was successfully removed.

=cut

sub timeout_remove {
   my ($self, $handle) = @_;
   $self->print ("PurpleBee::UiOps::EventLoop::timeout_remove ($handle)");

   if ($timeouts[$handle]) {
      undef $timeouts[$handle];
      return 1
   }

   0 # gboolean
}

=item timeout_add_seconds($self, $interval, $closure)

Creates a callback timer.

The timer will repeat until the function returns C<FALSE>. The
first call will be at the end of the first interval.

$interval is the time between calls of the function in seconds,
$closure the function closure to call.

This function returns a handle or event ID which can be passed to
purple_timeout_remove() to remove the timer.

=cut

sub timeout_add_seconds {
   my ($self, $interval, $closure) = @_;
   $self->print ("PurpleBee::UiOps::EventLoop::timeout_add_seconds ($interval, $closure)");

   # Find the next free @timeouts-index.
   # This loop will loop until @timeouts, which is one index after the last
   # one.  Thus, if there is no free spot, it will simply push the timer onto
   # the array.
   for my $handle (0 .. @timeouts) {
      # If $handle is currently free,
      if (!$timeouts[$handle]) {
         # create a new timer and put it into the array
         $timeouts[$handle] = AnyEvent->timer (
            after       => $interval,
            interval    => $interval,
            cb          => sub {
               $self->print ("timeout_seconds $handle = $closure");
               timeout_remove $self, $handle
                  unless $closure->call
            },
         );

         $self->print ("timeout_add_seconds = $handle");
         return $handle
      }
   }

   die "IMPOSSIBLE: didn't find free spot"
}

=item timeout_add($interval, $closure)

The same as timeout_add_seconds except that the interval is in milliseconds.

=cut

sub timeout_add {
   my ($self, $interval, $closure) = @_;
   $self->print ("PurpleBee::UiOps::EventLoop::timeout_add ($interval, $closure)");

   timeout_add_seconds $self, $interval / 1000, $closure
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
   my ($self, $fd, $cond, $closure) = @_;
   $self->print ("PurpleBee::UiOps::EventLoop::input_add ($fd, $cond, $closure)");

   for my $handle (0 .. @inputhandlers) { # find the next free @inputhandlers-index
      if (!$inputhandlers[$handle]) {
         $inputhandlers[$handle]{read} = AnyEvent->io (
            fh   => $fd,
            poll => 'r',
            cb   => sub { $self->print ("input[r] $handle (fd=$fd) = $closure"); $closure->call }
         ) if $cond & IO_READ;

         $inputhandlers[$handle]{write} = AnyEvent->io (
            fh   => $fd,
            poll => 'w',
            cb   => sub { $self->print ("input[w] $handle (fd=$fd) = $closure"); $closure->call }
         ) if $cond & IO_WRITE;

         $self->print ("input_add = $handle");

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
   $self->print ("PurpleBee::UiOps::EventLoop::input_remove ($handle)");

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
   $self->print ("PurpleBee::UiOps::EventLoop::input_get_error ($fd, $error)");

   0 # int
}

1
