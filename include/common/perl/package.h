/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <EXTERN.h>
#include <perl.h>

// Holds some global information on each perl package.
template<typename T>
struct perl_package
{
  static HV*            stash;
  static char const*    name;
  static MGVTBL         vtbl;
};

// vim:ft=xs
