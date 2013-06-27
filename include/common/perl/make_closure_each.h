/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <boost/foreach.hpp>

#include "common/perl/make_closure.h"

template<int... Curried, typename FuncT, typename... Args>
std::vector<perl_closure*>
make_closure_each (typename perl_closure::user_data_type& user_data, std::vector<FuncT> const& funcs, Args const&... args)
{
  std::vector<perl_closure*> closures;

  BOOST_FOREACH (FuncT const& func, funcs)
    {
      closures.push_back (make_closure<Curried...> (user_data, func, args...));
    }

  return closures;
}
