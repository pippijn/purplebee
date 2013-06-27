/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

template<int... Pack>
struct int_pack
{
  typedef int_pack type;
  static int const size = sizeof... (Pack);
};

template<typename, int>
struct int_pack_helper;

template<int... X, int N>
struct
int_pack_helper<int_pack<X...>, N>
  : int_pack<X..., N>
{
};

// Makes an int_pack with N ascending elements.
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
