/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/object.h"
#include "common/perl/package.h"
#include "common/util/xassert.h"

perl_object::perl_object (PerlInterpreter* perl)
  : self (NULL)
  , my_perl (perl)
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
perl_object::sever_self ()
{
  if (HV* self = this->self)
    {
      // keep a refcount because sv_unmagic might call perl_object_free,
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
      xassert (sv == self);
      obj->self = 0;
      SvREFCNT_dec (self);
    }

  return 0;
}

template<>
MGVTBL perl_package<void>::vtbl = { 0, 0, 0, 0, 0, 0, 0, 0 };

template<>
MGVTBL perl_package<perl_object>::vtbl = {
  0, 0, 0, 0, perl_object_free, 0, 0, 0
#if 0
  perl_object::get,
  perl_object::set,
  perl_object::len,
  perl_object::clear,
  perl_object::destroy,

  perl_object::copy,
  perl_object::dup,
  perl_object::local,
#endif
};
