#include <iostream>

#include "perl/interpreter.h"
#include "perl/eval_error.h"
#include "util/xassert.h"

PerlInterpreter* perl_interpreter::my_perl;

perl_interpreter::perl_interpreter (int argc, char* argv[], char* env[])
  : perl_object (perl_alloc ())
  , args { argc, argv, env }
{
  xassert (!my_perl);
  my_perl = perl_object::my_perl;
  xassert (my_perl);

  PERL_SYS_INIT3 (&args.argc, &args.argv, &args.env);
  perl_construct (my_perl);
  PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
}

perl_interpreter::~perl_interpreter ()
{
  perl_destruct (my_perl);
  perl_free (my_perl);
}


SV*
perl_interpreter::newSVptr (void* ptr, SV* sv, HV* stash)
{
  if (!ptr)
    return newSV (0);

  sv_magicext (sv, 0, PERL_MAGIC_ext, 0, (char*)ptr, 0);
  if (!SvROK (sv))
    sv = newRV_noinc (sv);
  if (stash)
    sv = sv_bless (sv, stash);
  return sv;
}

SV*
perl_interpreter::newSVptr (void* ptr, HV* hv, HV* stash)
{
  SV* sv = (SV*)hv;
  if (!ptr)
    return newSV (0);

  sv_magicext (sv, 0, PERL_MAGIC_ext, 0, (char*)ptr, 0);
  sv = newRV_noinc (sv);
  if (stash)
    sv = sv_bless (sv, stash);
  return sv;
}

SV*
perl_interpreter::newSVptr (void* ptr, AV* av, HV* stash)
{
  SV* sv = (SV*)av;
  if (!ptr)
    return newSV (0);

  sv_magicext (sv, 0, PERL_MAGIC_ext, 0, (char*)ptr, 0);
  sv = newRV_noinc (sv);
  if (stash)
    sv = sv_bless (sv, stash);
  return sv;
}


void*
perl_interpreter::SvPTR (SV* sv)
{
  sv = SvRV (sv);

  // very important shortcut
  if (SvMAGIC (sv) && SvMAGIC (sv)->mg_type == PERL_MAGIC_ext)
    return SvMAGIC (sv)->mg_ptr;

  if (MAGIC* mg = mg_find (sv, PERL_MAGIC_ext))
    return mg->mg_ptr;

  croak ("perl code used object, but C object is already destroyed, caught");
}


template<>
SV*
perl_interpreter::to_sv (perl_object* obj)
{
  if (!obj)
    return newSV (0);

  if (!obj->self)
    obj->self = newHV ();

  HV* stash = this->stash ();
  if (!SvOBJECT (obj->self))
    {
      sv_magicext ((SV *)obj->self, 0, PERL_MAGIC_ext, &perl_object::vtbl, (char *)obj, 0);

      // now bless the object _once_
      //TODO: create a class registry with c++ type<=>perl name<=>stash and use it here and elsewhere
      return sv_bless (newRV_inc ((SV *)obj->self), stash);
    }
  else
    {
      SV *sv = newRV_inc ((SV *)obj->self);

      if (Gv_AMG (stash)) // handle overload correctly, as the perl core does not
        SvAMAGIC_on (sv);

      return sv;
    }
}

template<>
SV*
perl_interpreter::to_sv (perl_interpreter* obj)
{
  return to_sv<perl_object*> (obj);
}


void
perl_interpreter::check_error ()
{
  if (SvTRUE (ERRSV))
    throw eval_error (SvPVutf8_nolen (ERRSV));
}

int
perl_interpreter::method_call (char const* method, int flags)
{
  xassert (method);
  char const* pkg = package ();
  xassert (pkg);
  char function[strlen (method) + strlen (pkg) + 2 + 1];
  sprintf (function, "%s::%s", pkg, method);

  return call_pv (function, flags);
}
