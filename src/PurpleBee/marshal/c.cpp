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
  int retval = SvIV (v);
#if 0
  printf ("sv_to<int> (%p) = %d", v, retval);
#endif
  return retval;
}

template<>
unsigned int
perl_interpreter::sv_to (SV* v)
{
  unsigned int retval = SvUV (v);
#if 0
  printf ("sv_to<unsigned int> (%p) = %u", v, retval);
#endif
  return retval;
}

template<>
long
perl_interpreter::sv_to (SV* v)
{
  long retval = SvIV (v);
#if 0
  printf ("sv_to<unsigned int> (%p) = %ld", v, retval);
#endif
  return retval;
}

template<>
void*
perl_interpreter::sv_to (SV* v)
{
#if 0
  printf ("sv_to<void*>");
#endif
  return NULL;
}

template<>
void
perl_interpreter::sv_to (SV* v)
{
#if 0
  printf ("sv_to<void>");
#endif
}

// vim:ft=xs
