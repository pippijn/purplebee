/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>

// Forward declarations.
template<template<typename, typename...> class O, typename R, typename... Args>
struct typed_closure;
struct frame;

template<template<typename, typename...> class O>
struct closure
{
  typedef typename O<void ()>::return_type return_type;

  virtual ~closure () { }

  virtual return_type  invoke () = 0;
  virtual void const*  symbol () = 0;
  virtual frame const* frames () = 0;

  template<typename R, typename... Args>
  static closure* create (typename O<R, Args...>::user_data_type& user_data,
                          std::tuple<R, Args...> const& closure)
  {
    return new typed_closure<O, R, Args...> (user_data, closure);
  }
};

template<template<typename, typename...> class O, typename R, typename... Args>
struct typed_closure_base
  : closure<O>
{
  typedef std::tuple<R, Args...>                        closure_type;
  typedef O<R, Args...>                                 operation_type;
  typedef typename operation_type::user_data_type       user_data_type;
  typedef typename operation_type::return_type          return_type;

  user_data_type& user_data;
  closure_type closure;
  frame const* stacktrace;

  typed_closure_base (user_data_type& data, closure_type const& clos)
    : user_data (data)
    , closure (clos)
    , stacktrace (NULL)
  {
  }
};

template<template<typename, typename...> class O, typename R, typename... Args>
struct typed_closure
  : typed_closure_base<O, R, Args...>
{
  typedef typed_closure_base<O, R, Args...>             base_type;
  typedef typename base_type::closure_type              closure_type;
  typedef typename base_type::user_data_type            user_data_type;
  typedef typename base_type::return_type               return_type;
  typedef typename base_type::operation_type            operation_type;

  typed_closure (user_data_type& data, closure_type const& clos)
    : base_type (data, clos)
  {
#if TRACE_CLOSURE
    this->stacktrace = operation_type ().frames (this->user_data, this->closure);
#endif
  }

  ~typed_closure ()
  {
#if TRACE_CLOSURE
    operation_type ().destroy_frames (this->stacktrace);
#endif
  }

  void const* symbol ()
  {
    return reinterpret_cast<void const*> (std::get<0> (this->closure));
  }

  frame const* frames ()
  {
    return this->stacktrace;
  }

  return_type invoke ()
  {
    return operation_type ().invoke (this->user_data, this->closure);
  }
};
