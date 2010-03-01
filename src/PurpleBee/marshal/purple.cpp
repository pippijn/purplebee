#include <tuple>

#include <boost/bimap.hpp>

#include "PurpleBee.h"
#include "perl/callback.h"
#include "util/xassert.h"

using boost::bimaps::set_of;

static boost::bimap<set_of<PurpleAccount*>, set_of<SV*>> accounts;

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (PurpleConversation* conv)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (PurpleMessageFlags flags)
{
  return newSViv (flags);
}

template<>
SV*
perl_interpreter::to_sv (PurpleInputCondition cond)
{
  return newSViv (cond);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleInputFunction, gpointer, int, PurpleInputCondition> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

template<>
SV*
perl_interpreter::to_sv (PurpleAccount* account)
{
  SV* sv;
  auto found = accounts.left.find (account);
  if (found == accounts.left.end ())
    {
      sv = newSVptr (account, newHV (), stash::PurpleBee_Account);
      accounts.left.insert (std::make_pair (account, sv));
    }
  else
    sv = found->second;
  return sv;
}


/*
 * SV* -> T
 */

template<>
PurpleAccount*
perl_interpreter::sv_to (SV* v)
{
  auto found = accounts.right.find (v);
  xassert (found != accounts.right.end ());
  return found->second;
}

// vim:ft=xs
