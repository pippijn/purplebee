#include "perl/interpreter.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (void* v)
{
  return newSVptr (v);
}

template<>
SV*
perl_interpreter::to_sv (int* v)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (int v)
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
perl_interpreter::to_sv (long v)
{
  return newSViv (v);
}

template<>
SV*
perl_interpreter::to_sv (char* v)
{
  STRLEN len = 0;
  return newSVpv (v, len);
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
perl_interpreter::to_sv (unsigned char const* v)
{
  return to_sv (reinterpret_cast<char const*> (v));
}

template<>
SV*
perl_interpreter::to_sv (char const** v)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (unsigned char** v)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (double v)
{
  return newSVnv (v);
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
long
perl_interpreter::sv_to (SV* v)
{
  return SvIV (v);
}

template<>
void*
perl_interpreter::sv_to (SV* v)
{
  return NULL;
}

template<>
void
perl_interpreter::sv_to (SV* v)
{
}

// vim:ft=xs
