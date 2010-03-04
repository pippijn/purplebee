#pragma once

#include "util/output.h"
#include "util/unimplemented.h"

#define NO_CONV(value, package)         \
  do {                                  \
    std::cout << "cannot convert `";    \
    output (value);                     \
    std::cout << "' to " << package;    \
    UNIMPLEMENTED;                      \
  } while (0)
