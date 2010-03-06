/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/debug/backtrace.h"
#include "common/perl/interpreter.h"
#include "common/util/closure.h"
#include "common/util/funcall.h"

// A policy template for closure<> that calls the stored closure and converts
// its return value to a perl scalar.
template<typename R, typename... Args>
struct perl_operation
{
  typedef std::tuple<R, Args...>                        closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  return_type operator () (user_data_type& perl, closure_type const& closure)
  {
    return perl.to_sv (invoke_closure (closure));
  }
};

// void-return specialisation returning undef to perl.
template<typename... Args>
struct perl_operation<void (*)(Args...), Args...>
{
  typedef void (*function_type)(Args...);
  typedef std::tuple<function_type, Args...>            closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  return_type operator () (user_data_type& perl, closure_type const& closure)
  {
    PerlInterpreter* my_perl = perl.perl ();
    invoke_closure (closure);
    return &PL_sv_undef;
  }
};

typedef closure<perl_operation> perl_closure;
