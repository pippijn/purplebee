/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

template<typename To, typename From>
static bool
force_assign (To& target, From source)
{
  return (target = reinterpret_cast<To> (source));
}
