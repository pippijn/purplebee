/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <stdexcept>

struct unimplemented_operation
  : std::runtime_error
{
  unimplemented_operation (char const* file, int line, char const* func)
    : std::runtime_error (construct (file, line, func))
  {
  }

  std::string construct (char const* file, int line, char const* func);
};

#define UNIMPLEMENTED                           \
  throw unimplemented_operation (__FILE__,      \
                                 __LINE__,      \
                                 __func__)
