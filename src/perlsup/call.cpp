#include "perl/eval_error.h"
#include "perl/interpreter.h"
#include "util/xassert.h"

#if 0
SV**
perl_interpreter::call_begin (size_t argc)
{
  dSP;
  ENTER;
  SAVETMPS;
  PUSHMARK (SP);
  EXTEND (SP, argc);
  return SP;
}

SV*
perl_interpreter::call_invoke (char const* method, int flags)
{
  xassert (method);
  char const* pkg = package ();
  xassert (pkg);
  char function[strlen (method) + strlen (pkg) + 2 + 1];
  sprintf (function, "%s::%s", pkg, method);

  PUTBACK;
  int count = call_pv (function, flags | G_EVAL);
  SPAGAIN;

  if (count)
    return POPs;
  return &PL_sv_undef;
}

void
perl_interpreter::call_finish ()
{
  PUTBACK;
  if (SvTRUE (ERRSV))
    throw eval_error (SvPVutf8_nolen (ERRSV));
  FREETMPS;
  LEAVE;
}
#endif
