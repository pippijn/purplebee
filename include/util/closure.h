/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>

// Forward declaration.
template<template<typename, typename...> class O, typename R, typename... Args>
struct typed_closure;

template<template<typename, typename...> class O>
struct closure
{
  typedef typename O<void ()>::return_type return_type;

  virtual ~closure () { }

  virtual return_type operator () () = 0;
  return_type call () { return (*this) (); }

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

  typed_closure_base (user_data_type& data, closure_type const& clos)
    : user_data (data)
    , closure (clos)
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
  }

  return_type operator () ()
  {
    return operation_type () (this->user_data, this->closure);
  }
};
