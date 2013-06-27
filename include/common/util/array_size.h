/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <cstddef>

// Creates a function declaration of a function returning a reference to an
// array of N chars. Its return value size is therefore N, which can be used
// in the array_size macro to ensure that it returns a compile-time constant.
template<typename T, size_t N>
char (&array_size (T const(&)[N]))[N];

#define array_size(array) (sizeof array_size (array))
