/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <iostream>

#include "common/util/output.h"
#include "common/util/unimplemented.h"

#define NO_CONV(value, package)         \
  do {                                  \
    std::cerr << "cannot convert `";    \
    output (value, std::cerr);          \
    std::cerr << "' to " << package;    \
    std::cerr << '\n';                  \
    croak ("unimplemented operation"    \
           " `%s' at %s:%d"             \
           , __func__                   \
           , __FILE__                   \
           , __LINE__);                 \
  } while (0)

struct handle
{
  handle (void* ptr)
    : ptr (uintptr_t (ptr))
  {
  }

  handle (uintptr_t ptr)
    : ptr (ptr)
  {
  }

  operator void* () { return (void*)ptr; }

  uintptr_t ptr;
};

std::ostream& operator << (std::ostream& os, handle hnd);
