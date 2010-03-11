/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/closure.h"
#include "common/perl/operation.h"
#include "common/util/make_closure.h"
#include "common/util/type_traits/int_pack.h"

template<int... Curried, typename R, typename... Args>
perl_closure*
make_closure (typename perl_closure::user_data_type& user_data, R (*function)(Args...), Args... args)
{
  return perl_closure::create<int_pack<Curried...>> (user_data, make_closure_tuple (function, args...));
}
