#pragma once

#include <stdexcept>

struct init_error
  : std::runtime_error
{
  init_error (char const* msg)
    : std::runtime_error (msg)
  {
  }
};
