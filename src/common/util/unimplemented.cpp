/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <sstream>

#include "common/util/unimplemented.h"

std::string
unimplemented_operation::construct (char const* file, int line, char const* func)
{
  std::ostringstream s;

  s << "Unimplemented operation `" << func
    << "' at " << file << ':' << line;

  return s.str ();
}
