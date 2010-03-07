/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/interpreter.h"

struct perl_operation_base
{
  frame const* get_frames ();
  void destroy_frames (frame const* frames);
};

// A policy template for closure<> that calls the stored closure and converts
// its return value to a perl scalar.
template<typename R, typename... Args>
struct perl_operation
  : perl_operation_base
{
  typedef R                                             function_type;
  typedef std::tuple<R, Args...>                        closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  return_type invoke (user_data_type& perl, closure_type const& closure);
};

// void-return specialisation returning undef to perl.
template<typename... Args>
struct perl_operation<void (*)(Args...), Args...>
  : perl_operation_base
{
  typedef void (*function_type)(Args...);
  typedef std::tuple<function_type, Args...>            closure_type;
  typedef perl_interpreter                              user_data_type;
  typedef SV*                                           return_type;

  return_type invoke (user_data_type& perl, closure_type const& closure);
};
