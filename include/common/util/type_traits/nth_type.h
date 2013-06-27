/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

template<int N, typename... Args>
struct nth_type;

template<int N, typename T, typename... Args>
struct nth_type<N, T, Args...>
{
  typedef typename nth_type<N - 1, Args...>::type type;
};

template<typename T, typename... Args>
struct nth_type<0, T, Args...>
{
  typedef T type;
};
