#include <map>

#include <purple.h>

#include "PurpleBee.h"
#include "PurpleBee/Closure.h"
#include "perl/interpreter.h"
#include "perl/package.h"
#include "util/xassert.h"

namespace
{
  struct sv_map
  {
    static std::map<void*, SV*> map;

    template<typename T>
    static T* fetch (perl_interpreter& perl, SV* sv)
    {
      return static_cast<T*> (perl.SvPTR (sv));
    }

    template<typename T>
    static SV* fetch (perl_interpreter& perl, T* ob)
    {
      PerlInterpreter* my_perl = perl.perl ();
      return perl.newSVptr (ob, newHV (), perl_package<T>::stash);

      auto found = map.find (ob);
      SV* sv;
      if (found != map.end ())
        {
          sv = static_cast<SV*> (found->second);
        }
      else
        {
          sv = perl.newSVptr (ob, newHV (), perl_package<T>::stash);
          map.insert (std::make_pair (ob, sv));
        }
      return sv;
    }

    template<typename T>
    static SV* fetch (perl_interpreter& perl, T const* ob)
    {
      return fetch (perl, const_cast<T*> (ob));
    }
  };

  std::map<void*, SV*> sv_map::map;
}


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
PASTE (Purple, T)*                                      \
perl_interpreter::sv_to (SV* v)                         \
{                                                       \
  return sv_map::fetch<PASTE (Purple, T)> (*this, v);   \
}

#include "PurpleBee/types.h"


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
PASTE (Purple, T) const*                                \
perl_interpreter::sv_to (SV* v)                         \
{                                                       \
  return sv_map::fetch<PASTE (Purple, T)> (*this, v);   \
}
#include "PurpleBee/types.h"


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
SV*                                                     \
perl_interpreter::to_sv (PASTE (Purple, T)* ob)         \
{                                                       \
  return sv_map::fetch (*this, ob);                     \
}
#include "PurpleBee/types.h"


#define OTYPE(T, P)
#define PTYPE(T, P)                                     \
template<>                                              \
SV*                                                     \
perl_interpreter::to_sv (PASTE (Purple, T) const* ob)   \
{                                                       \
  return sv_map::fetch (*this, ob);                     \
}
#include "PurpleBee/types.h"
