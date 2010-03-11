/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/marshal.h"
#include "common/perl/interpreter.h"
#include "common/util/xassert.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (handle v)
{
  return to_sv (v.ptr);
}

template<>
SV*
perl_interpreter::to_sv (void* v)
{
  NO_CONV (v, "void*");
}

template<>
SV*
perl_interpreter::to_sv (unsigned char* v)
{
  NO_CONV (v, "unsigned char*");
}

template<>
SV*
perl_interpreter::to_sv (void const* v)
{
  NO_CONV (v, "void const*");
}

template<>
SV*
perl_interpreter::to_sv (int* v)
{
  NO_CONV (v, "int*");
}

template<>
SV*
perl_interpreter::to_sv (char const* v)
{
  STRLEN len = 0;
  return newSVpv (v, len);
}

template<>
SV*
perl_interpreter::to_sv (char* v)
{
  return to_sv<char const*> (v);
}

template<>
SV*
perl_interpreter::to_sv (unsigned char const* v)
{
  return to_sv (reinterpret_cast<char const*> (v));
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<size_t, char const**> v)
{
  NO_CONV (v, "char const*[]");
}

template<>
SV*
perl_interpreter::to_sv (unsigned char** v)
{
  NO_CONV (v, "unsigned char**");
}

/*
 * SV* -> T
 */

template<>
char const*
perl_interpreter::sv_to (SV* sv)
{
  if (sv == &PL_sv_undef)
    return NULL;
  return SvPV_nolen (sv);
}

template<>
unsigned char const*
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "unsigned char const*");
}

template<>
unsigned char*
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "unsigned char*");
}

template<>
handle
perl_interpreter::sv_to (SV* sv)
{
  return handle (sv_to<uintptr_t> (sv));
}

template<>
void*
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "void*");
}

template<>
void const*
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "void const*");
}

template<>
char*
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "char*");
}

template<>
std::tuple<size_t, char const**>
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "char const*[]");
}

template<>
struct tm*
perl_interpreter::sv_to (SV* sv)
{
  NO_CONV (sv, "struct tm*");
}

template<>
void
perl_interpreter::sv_to (SV* sv)
{
  xassert (sv == &PL_sv_undef);
}

// vim:ft=xs
