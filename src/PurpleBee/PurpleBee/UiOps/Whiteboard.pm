package PurpleBee::UiOps::Whiteboard;
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.

use common::sense;

sub create {
   my ($self, $wb) = @_;
   $self->print ("PurpleBee::UiOps::Whiteboard::create ($wb)\n");
}

sub destroy {
   my ($self, $wb) = @_;
   $self->print ("PurpleBee::UiOps::Whiteboard::destroy ($wb)\n");
}

sub set_dimensions {
   my ($self, $wb, $width, $height) = @_;
   $self->print ("PurpleBee::UiOps::Whiteboard::set_dimensions ($wb, $width, $height)\n");
}

sub set_brush {
   my ($self, $wb, $size, $color) = @_;
   $self->print ("PurpleBee::UiOps::Whiteboard::set_brush ($wb, $size, $color)\n");
}

sub draw_point {
   my ($self, $wb, $x, $y, $color, $size) = @_;
   $self->print ("PurpleBee::UiOps::Whiteboard::draw_point ($wb, $x, $y, $color, $size)\n");
}

sub draw_line {
   my ($self, $wb, $x1, $y1, $x2, $y2, $color, $size) = @_;
   $self->print ("PurpleBee::UiOps::Whiteboard::draw_line ($wb, $x1, $y1, $x2, $y2, $color, $size)\n");
}

sub clear {
   my ($self, $wb) = @_;
   $self->print ("PurpleBee::UiOps::Whiteboard::clear ($wb)\n");
}


1
