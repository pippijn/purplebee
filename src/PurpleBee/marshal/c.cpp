#include "perl/interpreter.h"
#include "util/unimplemented.h"

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
perl_interpreter::to_sv (void* v)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (unsigned char* v)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (void const* v)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (long* v)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (int* v)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (int v)
{
  return newSViv (v);
}

template<>
SV*
perl_interpreter::to_sv (long long v)
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
perl_interpreter::to_sv (unsigned long v)
{
  return newSVuv (v);
}

template<>
SV*
perl_interpreter::to_sv (unsigned int v)
{
  return newSVuv (v);
}

template<>
SV*
perl_interpreter::to_sv (long v)
{
  return newSViv (v);
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
perl_interpreter::to_sv (char const** v)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (unsigned char** v)
{
  UNIMPLEMENTED;
}

template<>
SV*
perl_interpreter::to_sv (double v)
{
  UNIMPLEMENTED;
}


/*
 * SV* -> T
 */

template<>
int
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
unsigned long
perl_interpreter::sv_to (SV* v)
{
  return SvUV (v);
}

template<>
long long
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

template<>
long
perl_interpreter::sv_to (SV* v)
{
  return SvIV (v);
}

template<>
char const*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
unsigned char const*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
unsigned char*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
int*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
unsigned int*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
void*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
void const*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
unsigned char**
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
char*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
char const**
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
char**
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
long*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
struct tm*
perl_interpreter::sv_to (SV* v)
{
  UNIMPLEMENTED;
}

template<>
void
perl_interpreter::sv_to (SV* v)
{
}

// vim:ft=xs
