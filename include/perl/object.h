#pragma once

#include <EXTERN.h>
#include <perl.h>

struct perl_object
{
  HV* self;

protected:
  PerlInterpreter *my_perl;

  virtual char const* package () const = 0;

  perl_object (PerlInterpreter* perl);
  ~perl_object ();

  HV* stash () const;

  void init_self ();
  void sever_self ();

  static MGVTBL vtbl;
};
