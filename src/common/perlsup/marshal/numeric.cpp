/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/interpreter.h"
#include "common/util/unimplemented.h"

#if IVSIZE >= 8
typedef IV val64;
typedef IV uval64;
# define newSVval64 newSViv
# define SvVAL64 SvIV
# define newSVuval64 newSVuv
# define SvUVAL64 SvUV
#else
typedef double val64;
typedef double uval64;
# define newSVval64 newSVnv
# define SvVAL64 SvNV
# define newSVuval64 newSVnv
# define SvUVAL64 SvNV
#endif

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (bool v)
{
  return newSVuv (v);
}

template<>
SV*
perl_interpreter::to_sv (signed char v)
{
  return newSViv (v);
}

template<>
SV*
perl_interpreter::to_sv (unsigned char v)
{
  return newSVuv (v);
}

template<>
SV*
perl_interpreter::to_sv (signed short v)
{
  return newSViv (v);
}

template<>
SV*
perl_interpreter::to_sv (unsigned short v)
{
  return newSVuv (v);
}

template<>
SV*
perl_interpreter::to_sv (signed int v)
{
  return newSViv (v);
}

template<>
SV*
perl_interpreter::to_sv (unsigned int v)
{
  return newSVuv (v);
}

template<>
SV*
perl_interpreter::to_sv (signed long v)
{
  return newSViv (v);
}

template<>
SV*
perl_interpreter::to_sv (unsigned long v)
{
  return newSVuv (v);
}

template<>
SV*
perl_interpreter::to_sv (signed long long v)
{
  return newSVval64 (v);
}

template<>
SV*
perl_interpreter::to_sv (unsigned long long v)
{
  return newSVuval64 (v);
}

template<>
SV*
perl_interpreter::to_sv (double v)
{
  return newSVnv (v);
}

template<>
SV*
perl_interpreter::to_sv (float v)
{
  return newSVnv (v);
}

/*
 * SV* -> T
 */

template<>
bool
perl_interpreter::sv_to (SV* v)
{
  return SvUV (v);
}

template<>
signed char
perl_interpreter::sv_to (SV* v)
{
  return SvIV (v);
}

template<>
unsigned char
perl_interpreter::sv_to (SV* v)
{
  return SvUV (v);
}

template<>
signed short
perl_interpreter::sv_to (SV* v)
{
  return SvIV (v);
}

template<>
unsigned short
perl_interpreter::sv_to (SV* v)
{
  return SvUV (v);
}

template<>
signed int
perl_interpreter::sv_to (SV* v)
{
  return SvIV (v);
}

template<>
unsigned int
perl_interpreter::sv_to (SV* v)
{
  return SvUV (v);
}

template<>
signed long
perl_interpreter::sv_to (SV* v)
{
  return SvIV (v);
}

template<>
unsigned long
perl_interpreter::sv_to (SV* v)
{
  return SvUV (v);
}

template<>
signed long long
perl_interpreter::sv_to (SV* v)
{
  return SvVAL64 (v);
}

template<>
unsigned long long
perl_interpreter::sv_to (SV* v)
{
  return SvUVAL64 (v);
}

