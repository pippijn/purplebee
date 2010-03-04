#pragma once

#include <EXTERN.h>
#include <perl.h>

template<typename T>
struct perl_package
{
  static HV*            stash;
  static char const*    name;
  static MGVTBL         vtbl;
};

// vim:ft=xs
