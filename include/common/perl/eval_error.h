/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <stdexcept>

// Thrown when a perl method fails.
// XXX: this must be replaced with croak, later.
struct eval_error
  : std::runtime_error
{
  eval_error (char const* msg)
    : std::runtime_error (msg)
  {
  }
};
