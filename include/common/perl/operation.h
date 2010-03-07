/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/interpreter.h"

// A policy template for closure<> that calls the stored closure and converts
// its return value to a perl scalar.
template<typename R, typename... Args>
struct perl_operation
{
  typedef R                                             function_type;
  typedef std::tuple<R, Args...>                        closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  virtual void pre_call  (user_data_type& perl, closure_type const& function) { }
  virtual void post_call (user_data_type& perl, closure_type const& function, return_type const& RETVAL) { }

  void const* symbol (user_data_type& perl, closure_type const& closure);
  return_type invoke (user_data_type& perl, closure_type const& closure);
};

// void-return specialisation returning undef to perl.
template<typename... Args>
struct perl_operation<void (*)(Args...), Args...>
{
  typedef void (*function_type)(Args...);
  typedef std::tuple<function_type, Args...>            closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  virtual void pre_call  (user_data_type& perl, closure_type const& function) { }
  virtual void post_call (user_data_type& perl, closure_type const& function, return_type const& RETVAL) { }

  void const* symbol (user_data_type& perl, closure_type const& closure);
  return_type invoke (user_data_type& perl, closure_type const& closure);
};
