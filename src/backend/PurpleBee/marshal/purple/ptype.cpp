/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <map>

#include <purple.h>

#include "common/perl/interpreter.h"
#include "common/perl/package.h"
#include "common/util/xassert.h"

#include "backend/PurpleBee.h"

namespace
{
  // XXX: this leaks HV*s
  // TODO: when a C++ object dies, decrease the refcount on its perl object
  template<typename T>
  struct sv_map
  {
    static std::map<void*, HV*> map;

    static T* fetch (perl_interpreter& perl, SV* sv)
    {
      return static_cast<T*> (perl.SvPTR (sv));
    }

    static SV* fetch (perl_interpreter& perl, T* ob)
    {
      PerlInterpreter* my_perl = perl.perl ();

      if (!ob)
        return &PL_sv_undef;

      auto found = map.find (ob);
      HV* self;
      if (found != map.end ())
        {
          self = static_cast<HV*> (found->second);
        }
      else
        {
          self = newHV ();
          map.insert (std::make_pair (ob, self));
        }
      xassert (self);

      return perl.newSVobj (ob, perl_package<T>::stash, self);
    }

    static SV* fetch (perl_interpreter& perl, T const* ob)
    {
      return fetch (perl, const_cast<T*> (ob));
    }
  };

  template<typename T>
  std::map<void*, HV*> sv_map<T>::map;
}


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
PASTE (Purple, T)*                                      \
perl_interpreter::sv_to (SV* v)                         \
{                                                       \
  return sv_map<PASTE (Purple, T)>::fetch (*this, v);   \
}

#include "backend/PurpleBee/types.h"


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
PASTE (Purple, T) const*                                \
perl_interpreter::sv_to (SV* v)                         \
{                                                       \
  return sv_map<PASTE (Purple, T)>::fetch (*this, v);   \
}
#include "backend/PurpleBee/types.h"


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
SV*                                                     \
perl_interpreter::to_sv (PASTE (Purple, T)* ob)         \
{                                                       \
  return sv_map<PASTE (Purple, T)>::fetch (*this, ob);  \
}
#include "backend/PurpleBee/types.h"


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
SV*                                                     \
perl_interpreter::to_sv (PASTE (Purple, T) const* ob)   \
{                                                       \
  return sv_map<PASTE (Purple, T)>::fetch (*this, ob);  \
}
#include "backend/PurpleBee/types.h"
