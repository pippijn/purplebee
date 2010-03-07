/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/invoke_closure.h"
#include "common/perl/operation.h"

template<typename R, typename... Args>
typename perl_operation<R, Args...>::return_type
perl_operation<R, Args...>::operator () (user_data_type& perl, closure_type const& closure)
{
  this->pre_call  (perl, closure);
  return_type const& retval = perl.to_sv (invoke_closure (closure));
  this->post_call (perl, closure, retval);
  return retval;
}

template<typename... Args>
typename perl_operation<void (*)(Args...), Args...>::return_type
perl_operation<void (*)(Args...), Args...>::operator () (user_data_type& perl, closure_type const& closure)
{
  PerlInterpreter* my_perl = perl.perl ();
  this->pre_call  (perl, closure);
  invoke_closure (closure);
  return_type const& retval = &PL_sv_undef;
  this->post_call (perl, closure, retval);
  return retval;
}
