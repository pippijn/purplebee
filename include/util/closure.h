#pragma once

#include <tuple>

template<int...>
struct int_pack
{
  typedef int_pack type;
};

template<typename, int>
struct int_pack_helper;

template<int... X, int N>
struct
int_pack_helper<int_pack<X...>, N>
  : int_pack<X..., N>
{
};

template<int N>
struct make_int_pack
  : int_pack_helper<typename make_int_pack<N - 1>::type, N - 1>
{
};

template<>
struct make_int_pack<0>
  : int_pack<>
{
};

template<typename Sig>
struct return_type;

template<typename R, typename... A>
struct return_type<R (*) (A...)>
{
  typedef R type;
};

template<typename F, typename... A, int... N>
typename return_type<F>::type
call_function (F function, std::tuple<F, A...> t, int_pack<N...>)
{
  return function (std::get<N + 1> (t)...);
}

template<typename F, typename... A>
typename return_type<F>::type
call_function (std::tuple<F, A...> closure)
{
  return call_function (std::get<0> (closure), closure, make_int_pack<sizeof ... (A)> ());
}

template<template<typename, typename...> class O, typename R, typename... Args>
struct typed_closure;

template<typename T, template<typename, typename...> class O>
struct closure
{
  virtual T operator () () = 0;

  template<typename R, typename... Args>
  static closure* create (typename O<R, Args...>::user_data_type& user_data,
                          std::tuple<R, Args...> const& closure)
  {
    return new typed_closure<O, R, Args...> (user_data, closure);
  }
};

template<template<typename, typename...> class O, typename R, typename... Args>
struct typed_closure_base
  : closure<typename O<R, Args...>::return_type, O>
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
