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
    UNIMPLEMENTED;                      \
  } while (0)
