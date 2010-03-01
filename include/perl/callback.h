#pragma once

#include <tuple>

#include <EXTERN.h>
#include <perl.h>

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

template<typename R, typename... Args>
struct typed_callback;

struct perl_callback
{
  virtual SV* operator () () = 0;

  template<typename R, typename... Args>
  static typed_callback<R, Args...>* create (perl_interpreter& perl, std::tuple<R, Args...> closure)
  {
    return new typed_callback<R, Args...> (perl, closure);
  }
};

template<typename R, typename... Args>
struct typed_callback_base
  : perl_callback
{
  typedef std::tuple<R, Args...> closure_type;

  perl_interpreter& perl;
  std::tuple<R, Args...> closure;

  typed_callback_base (perl_interpreter& perl, std::tuple<R, Args...> clos)
    : perl (perl)
    , closure (clos)
  {
  }
};

template<typename R, typename... Args>
struct typed_callback
  : typed_callback_base<R, Args...>
{
  typedef typed_callback_base<R, Args...> base;

  typed_callback (perl_interpreter& perl, typename base::closure_type const& clos)
    : base (perl, clos)
  {
  }

  SV* operator () ()
  {
    return this->perl.to_sv (call_function (this->closure));
  }
};

template<typename... Args>
struct typed_callback<void (*)(Args...), Args...>
  : typed_callback_base<void (*)(Args...), Args...>
{
  typedef typed_callback_base<void (*)(Args...), Args...> base;

  typed_callback (perl_interpreter& perl, typename base::closure_type const& clos)
    : base (perl, clos)
  {
  }

  SV* operator () ()
  {
    call_function (this->closure);
    PerlInterpreter* my_perl = this->perl.get_perl ();
    return &PL_sv_undef;
  }
};
