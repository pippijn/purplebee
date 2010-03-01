#include "perl/object.h"
#include "util/xassert.h"

perl_object::perl_object (PerlInterpreter* perl)
  : my_perl (perl)
{
}

perl_object::~perl_object ()
{
  sever_self ();
}

HV*
perl_object::stash () const
{
  return gv_stashpv (package (), 1);
}

void
perl_object::init_self ()
{
  HV* stash = this->stash ();
  xassert (stash);
  self = newHV ();
}

void
perl_object::sever_self ()
{
  if (HV* self = this->self)
    {
      // keep a refcount because sv_unmagic might call attachable_free,
      // which might clear self, causing sv_unmagic to crash on a now
      // invalid object.
      SvREFCNT_inc (self);
      hv_clear (self);
      sv_unmagic ((SV*)self, PERL_MAGIC_ext);
      SvREFCNT_dec (self);

      // self *must* be null now because that's sv_unmagic's job.
      xassert (!this->self);
    }
}

static int
perl_object_free (pTHX_ SV *sv, MAGIC *mg)
{
  perl_object *obj = (perl_object*)mg->mg_ptr;

  //TODO: check if transaction behaviour is really required here
  if (SV *self = (SV *)obj->self)
    {
      obj->self = 0;
      SvREFCNT_dec (self);
    }

  return 0;
}

MGVTBL perl_object::vtbl = {0, 0, 0, 0, perl_object_free};
