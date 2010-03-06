/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

// Calculates the return type of a function.
template<typename Sig>
struct return_type;

// Specialise for function types only, anything else
// will cause a hard failure.
template<typename R, typename... A>
struct return_type<R (A...)>
{
  typedef R type;
};

// We need a specialisation for variadic functions,
// because "..." is not a type.
template<typename R, typename... A>
struct return_type<R (A..., ...)>
{
  typedef R type;
};

// And a specialisation for function pointer types.
template<typename R, typename... A>
struct return_type<R (*) (A...)>
  : return_type<R (A...)>
{
};

// And one for pointers to variadic functions.
template<typename R, typename... A>
struct return_type<R (*) (A..., ...)>
  : return_type<R (A..., ...)>
{
};
