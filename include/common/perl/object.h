/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <EXTERN.h>
#include <perl.h>

// Represents an intrusively perl-bound C++ object.
struct perl_object
{
  // The perl side of this object.
  HV* self;

  PerlInterpreter* perl () { return my_perl; }

protected:
  PerlInterpreter *my_perl;

  // Every perl object must have a package it is blessed into.
  virtual char const* package () const = 0;

  // This does nothing. It does not initialise self, because the perl
  // interpreter might not be there, yet.
  perl_object (PerlInterpreter* perl);
  // Destroys self if it wasn't already destroyed.
  virtual ~perl_object ();

  // Returns the perl package stash belonging to package().
  // It creates the stash if it isn't there, yet.
  HV* stash () const;

  // Destroys $self.
  void sever_self ();
};

// vim:ft=xs
