#include "perl/interpreter.h"
#include "util/unimplemented.h"

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

/*
 * SV* -> T
 */

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
