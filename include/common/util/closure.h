/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>

#include <purple.h> // XXX: G_GNUC_UNUSED

#include "common/util/type_traits/int_pack.h"

// Forward declarations.
template<template<typename, typename, typename...> class O, typename Curried, typename R, typename... Args>
struct typed_closure;
struct frame;

template<template<typename, typename, typename...> class O>
struct closure
{
  closure () = default;
  closure (closure const& rhs) = delete;
  closure& operator = (closure const& rhs) = delete;

  typedef typename O<void, void ()>::return_type        return_type;
  typedef typename O<void, void ()>::arglist_type       arglist_type;
  typedef typename O<void, void ()>::user_data_type     user_data_type;

  virtual ~closure () { }

  virtual return_type  invoke  (arglist_type const& arglist) = 0;
  virtual return_type  invoke  () = 0;
  virtual void const*  symbol  () = 0;
  virtual frame const* frames  () = 0;
  virtual int          curried () = 0;

  template<typename Curried, typename R, typename... Args>
  static closure* create (typename O<Curried, R, Args...>::user_data_type& user_data,
                          std::tuple<R, Args...> const& closure)
  {
    return new typed_closure<O, Curried, R, Args...> (user_data, closure);
  }
};

template<template<typename, typename, typename...> class O, typename Curried, typename R, typename... Args>
class typed_closure_base
  : closure<O>
{
  friend class closure<O>;

protected:
  typedef std::tuple<R, Args...>                        closure_type;
  typedef O<Curried, R, Args...>                        operation_type;
  typedef typename operation_type::user_data_type       user_data_type;
  typedef typename operation_type::return_type          return_type;
  typedef typename operation_type::arglist_type         arglist_type;

  user_data_type& user_data;
  closure_type closure;
  frame const* stacktrace;

  typed_closure_base (user_data_type& data, closure_type const& clos)
    : user_data (data)
    , closure (clos)
    , stacktrace (NULL)
#if TRACE_CLOSURE
    , stacktrace (operation_type ().frames (this->user_data, this->closure))
#endif
  {
  }

  ~typed_closure_base ()
  {
#if TRACE_CLOSURE
    operation_type ().destroy_frames (this->stacktrace);
#endif
  }
};

template<typename Curried, int N = 0>
struct uncurry;

template<template<typename, typename, typename...> class O, typename Curried, typename R, typename... Args>
class typed_closure
  : typed_closure_base<O, Curried, R, Args...>
{
  friend class closure<O>;

  typedef typed_closure_base<O, Curried, R, Args...>    base_type;
  typedef typename base_type::closure_type              closure_type;
  typedef typename base_type::user_data_type            user_data_type;
  typedef typename base_type::return_type               return_type;
  typedef typename base_type::operation_type            operation_type;
  typedef typename base_type::arglist_type              arglist_type;

  typed_closure (user_data_type& data, closure_type const& clos)
    : base_type (data, clos)
  {
  }

  void const* symbol ()
  {
    return reinterpret_cast<void const*> (std::get<0> (this->closure));
  }

  frame const* frames ()
  {
    return this->stacktrace;
  }

  return_type invoke (arglist_type const& arglist)
  {
    operation_type op;
    uncurry<Curried> (op, arglist, this->user_data, this->closure);
    return op.invoke (this->user_data, this->closure);
  }

  return_type invoke ()
  {
    return operation_type ().invoke (this->user_data, this->closure);
  }

  int curried ()
  {
    return Curried::size;
  }
};

template<typename Curried, int N>
struct uncurry;

template<int N, int I, int... Rest>
struct uncurry<int_pack<I, Rest...>, N>
{
  template< typename operation_type
          , typename arglist_type
          , typename user_data_type
          , typename closure_type
          >
  uncurry ( operation_type& op
          , arglist_type const& arglist
          , user_data_type& user_data
          , closure_type& closure
          )
  {
    // XXX: gcc bug?
    //op.template uncurry<N> (arglist, user_data, std::get<I + 1> (closure));
    op.template uncurry1<N> (arglist, user_data, std::get<I + 1> (closure));
    uncurry<int_pack<Rest...>, N + 1> (op, arglist, user_data, closure);
  }
};

template<int N>
struct uncurry<int_pack<>, N>
{
  template< typename operation_type
          , typename arglist_type
          , typename user_data_type
          , typename closure_type
          >
  uncurry ( G_GNUC_UNUSED operation_type& op
          , G_GNUC_UNUSED arglist_type const& arglist
          , G_GNUC_UNUSED user_data_type& user_data
          , G_GNUC_UNUSED closure_type& closure
          )
  {
  }
};
