/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/operation.h"
#include "common/util/invoke_closure.h"
#include "common/util/xassert.h"

template<int N, typename T>
void
perl_operation_base::uncurry (arglist_type arglist, user_data_type& perl, T& element)
{
  PerlInterpreter* my_perl = perl.perl ();
  SV** item = av_fetch (arglist, N, 0);
  xassert (item);
  xassert (*item);
  element = perl.sv_to<T> (*item);
}

template<typename Curried, typename R, typename... Args>
typename perl_operation<Curried, R, Args...>::return_type
perl_operation<Curried, R, Args...>::invoke (user_data_type& perl, closure_type const& closure)
{
  return perl.to_sv (invoke_closure (closure));
}

template<typename Curried, typename... Args>
typename perl_operation<Curried, void (*)(Args...), Args...>::return_type
perl_operation<Curried, void (*)(Args...), Args...>::invoke (user_data_type& perl, closure_type const& closure)
{
  PerlInterpreter* my_perl = perl.perl ();
  invoke_closure (closure);
  return &PL_sv_undef;
}
