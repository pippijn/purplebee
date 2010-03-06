/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <tuple>

#include "common/util/type_traits/return_type.h"
#include "common/util/type_traits/int_pack.h"

// Encapsulates some information and metafunctions on closures.
template<typename TupleT>
struct closure_traits;

template<typename FuncT, typename... A>
struct closure_traits<std::tuple<FuncT, A...>>
{
  typedef make_int_pack<sizeof... (A)>          int_pack;
  typedef FuncT                                 function_type;
  typedef typename return_type<FuncT>::type     return_type;
};


template<int Skip, typename TupleT, typename... ExtraArgs, int... N>
typename closure_traits<TupleT>::return_type
invoke_closure_helper ( typename closure_traits<TupleT>::function_type function
                      , G_GNUC_UNUSED TupleT t
                      , G_GNUC_UNUSED int_pack<N...> ipack
                      , ExtraArgs const&... extra_args
                      )
{
  return function (std::get<N + Skip> (t)..., extra_args...);
}

template<typename TupleT, typename... ExtraArgs>
typename closure_traits<TupleT>::return_type
invoke_closure (TupleT const& closure, ExtraArgs const&... extra_args)
{
  return invoke_closure_helper<1> ( std::get<0> (closure)
                                  , closure
                                  , typename closure_traits<TupleT>::int_pack ()
                                  , extra_args...
                                  );
}
