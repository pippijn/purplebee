/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "perl/interpreter.h"
#include "util/closure.h"

template<typename R, typename... Args>
struct perl_operation
{
  typedef std::tuple<R, Args...>                        closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  return_type operator () (user_data_type& perl, closure_type const& closure)
  {
    return perl.to_sv (call_function (closure));
  }
};

template<typename... Args>
struct perl_operation<void (*)(Args...), Args...>
{
  typedef std::tuple<void (*)(Args...), Args...>        closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  return_type operator () (user_data_type& perl, closure_type const& closure)
  {
    call_function (closure);
    PerlInterpreter* my_perl = perl.perl ();
    return &PL_sv_undef;
  }
};

typedef closure<SV*, perl_operation> perl_closure;
