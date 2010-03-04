#include <iostream>

#include "perl/eval_error.h"
#include "perl/interpreter.h"
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
perl_interpreter::newSVptr (void* ptr, HV* stash, SV* self)
{
  if (!ptr)
    return &PL_sv_undef;

  sv_magicext (self, 0, PERL_MAGIC_ext, NULL, (char*)ptr, 0);
  if (!SvROK (self))
    self = newRV_noinc (self);
  if (stash)
    self = sv_bless (self, stash);
  return self;
}


void*
perl_interpreter::SvPTR (SV* sv)
{
  if (sv == &PL_sv_undef)
    return NULL;

  if (!SvROK (sv))
    return NULL;

  sv = SvRV (sv);

  // very important shortcut
  if (SvMAGIC (sv) && SvMAGIC (sv)->mg_type == PERL_MAGIC_ext)
    return SvMAGIC (sv)->mg_ptr;

  if (MAGIC* mg = mg_find (sv, PERL_MAGIC_ext))
    return mg->mg_ptr;

  croak ("perl code used object, but C object is already destroyed, caught");
}

SV*
perl_interpreter::newSVobj (void* obj, HV* stash, HV* self)
{
  xassert (obj);
  xassert (self);

  if (!SvOBJECT (self))
    {
      sv_magicext ((SV*)self, 0, PERL_MAGIC_ext, NULL, (char *)obj, 0);

      // now bless the object _once_
      //TODO: create a class registry with c++ type<=>perl name<=>stash and use it here and elsewhere
      return sv_bless (newRV_inc ((SV*)self), stash);
    }
  else
    {
      SV *sv = newRV_inc ((SV*)self);

      if (Gv_AMG (stash)) // handle overload correctly, as the perl core does not
        SvAMAGIC_on (sv);

      return sv;
    }
}

template<>
SV*
perl_interpreter::to_sv (perl_interpreter* obj)
{
  if (!obj)
    return &PL_sv_undef;

  if (!obj->self)
    obj->self = newHV ();

  return newSVobj (obj, obj->stash (), obj->self);
}

template<>
perl_interpreter*
perl_interpreter::sv_to (SV* sv)
{
  return static_cast<perl_interpreter*> (SvPTR (sv));
}
