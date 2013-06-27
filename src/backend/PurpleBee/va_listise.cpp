#include "common/debug/purple.h"

namespace purple
{
  char const*
  va_listise (std::string&& str, std::string const& arg)
  {
    str = std::move (arg);
    return str.c_str ();
  }
}
