#pragma once

#include <stdexcept>

struct initialisation_error
  : std::runtime_error
{
  initialisation_error (char const* msg)
    : std::runtime_error (msg)
  {
  }
};
