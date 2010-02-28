#include <sstream>

#include "util/xassert.h"

std::string
assertion_failure::construct (char const* msg, char const* file, int line, char const* func)
{
  std::ostringstream s;

  s << "Assertion `" << msg
    << "' failed at " << file << ':' << line
    << " in " << func;

  return s.str ();
}
