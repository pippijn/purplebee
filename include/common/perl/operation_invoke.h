/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/operation.h"
#include "common/util/invoke_closure.h"

template<typename R, typename... Args>
typename perl_operation<R, Args...>::return_type
perl_operation<R, Args...>::invoke (user_data_type& perl, closure_type const& closure)
{
  return perl.to_sv (invoke_closure (closure));
}

template<typename... Args>
typename perl_operation<void (*)(Args...), Args...>::return_type
perl_operation<void (*)(Args...), Args...>::invoke (user_data_type& perl, closure_type const& closure)
{
  PerlInterpreter* my_perl = perl.perl ();
  invoke_closure (closure);
  return &PL_sv_undef;
}
