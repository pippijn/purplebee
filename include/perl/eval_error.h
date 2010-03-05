/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <stdexcept>

struct eval_error
  : std::runtime_error
{
  eval_error (char const* msg)
    : std::runtime_error (msg)
  {
  }
};
