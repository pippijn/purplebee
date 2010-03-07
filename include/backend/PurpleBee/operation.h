/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/debug/backtrace.h"
#include "common/perl/operation.h"

template<typename F, typename... Args>
struct PurpleBee_operation
  : perl_operation<F, Args...>
{
  typedef perl_operation<F, Args...>                    base_type;
  typedef typename base_type::closure_type              closure_type;
  typedef typename base_type::return_type               return_type;
  typedef typename base_type::user_data_type            user_data_type;

  void pre_call  (user_data_type& perl, closure_type const& closure);
  void post_call (user_data_type& perl, closure_type const& closure, return_type const& RETVAL);
};
