/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

template<typename T>
struct placeholder
{
  T value;

  operator T () const { return value; }
};

template<typename T>
struct remove_placeholder
{
  typedef T type;
};

template<typename T>
struct remove_placeholder<placeholder<T>>
{
  typedef T type;
};
