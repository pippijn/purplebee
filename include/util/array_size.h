/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <cstddef>

template<typename T, size_t N>
char (&array_size (T const(&)[N]))[N];

#define array_size(array) (sizeof array_size (array))
