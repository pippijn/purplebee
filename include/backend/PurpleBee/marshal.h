/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/util/output.h"
#include "common/util/unimplemented.h"

#define NO_CONV(value, package)         \
  do {                                  \
    std::cout << "cannot convert `";    \
    output (value);                     \
    std::cout << "' to " << package;    \
    UNIMPLEMENTED;                      \
  } while (0)
