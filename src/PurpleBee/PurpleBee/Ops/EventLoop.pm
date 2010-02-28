package PurpleBee::Ops::EventLoop;

use common::sense;

sub timeout_add {
   my ($interval, $function, $data) = @_;
   print "PurpleBee::Ops::EventLoop::timeout_add\n";

   0 # guint
}

sub timeout_remove {
   my ($handle) = @_;
   print "PurpleBee::Ops::EventLoop::timeout_remove\n";

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

   0 # guint
}


1
