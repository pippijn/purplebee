/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/eval_error.h"
#include "common/perl/interpreter.h"
#include "common/util/xassert.h"

static int
count_strings (char* strings[])
{
  int i = 0;
  while (*strings++)
    ++i;
  return i;
}

perl_interpreter::perl_interpreter (int argc, char* argv[], char* env[])
  : args { argc, count_strings (env), argv, env }
  , my_perl (perl_alloc ())
{
  PERL_SYS_INIT3 (&args.argc, &args.argv, &args.env);
  perl_construct (my_perl);
  PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
}

perl_interpreter::~perl_interpreter ()
{
  xassert (my_perl);
  fprintf (stderr, "******************************** bye perl\n");
  perl_destruct (my_perl);
  perl_free (my_perl);
  my_perl = NULL;
}


template<>
SV*
perl_interpreter::newSVptr<void> (void* ptr, HV* stash, SV* self, MGVTBL* vtbl)
{
  if (!ptr)
    return &PL_sv_undef;

  sv_magicext (self, 0, PERL_MAGIC_ext, vtbl, (char*)ptr, 0);
  if (!SvROK (self))
    self = newRV_noinc (self);
  if (stash)
    self = sv_bless (self, stash);
  return self;
}

template<>
SV*
perl_interpreter::newSVobj<void> (void* obj, HV* stash, HV* self, MGVTBL* vtbl)
{
  xassert (obj);
  xassert (self);

  if (!SvOBJECT (self))
    {
      sv_magicext ((SV*)self, 0, PERL_MAGIC_ext, vtbl, (char *)obj, 0);

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

// vim:ft=xs
