#if 0
#include <iostream>
#include <type_traits>

#include "perl/eval_error.h"

#define CHECK_ERROR\
  if (SvTRUE (ERRSV))\
    throw eval_error (SvPVutf8_nolen (ERRSV));

inline
perl_interpreter::caller::caller (perl_interpreter& perl, size_t argc)
  : perl (perl)
{
  PerlInterpreter* my_perl = perl.perl ();

  dSP;
  ENTER;
  SAVETMPS;
  PUSHMARK (SP);
  EXTEND (SP, argc);
  this->SP = SP;
  this->RETVAL = &PL_sv_undef;
}

inline void
perl_interpreter::caller::arg ()
{
  PerlInterpreter* my_perl = perl.perl ();

  PUTBACK;
}

template<typename T, typename... Args>
inline void
perl_interpreter::caller::arg (T const& expr, Args const&... rest)
{
  PerlInterpreter* my_perl = perl.perl ();

  std::cout << ", ";
  output (expr);

  PUSHs (sv_2mortal (perl.to_sv (expr)));
  arg (rest...);
}

inline void
perl_interpreter::caller::call (char const* method, int flags)
{
  PerlInterpreter* my_perl = perl.perl ();

  char const* pkg = perl.package ();
  char function[strlen (method) + strlen (pkg) + 2 + 1];
  sprintf (function, "%s::%s", pkg, method);

  if (call_pv (function, flags | G_EVAL) > 0)
    RETVAL = POPs;
  SPAGAIN;
}

template<typename R>
inline R
perl_interpreter::caller::result ()
{
  PerlInterpreter* my_perl = perl.perl ();

  R retval = perl.sv_to<R> (RETVAL);
  end ();

  std::cout << "method_return = ";
  output (retval);
  std::cout << '\n';

  return retval;
}

template<>
inline void
perl_interpreter::caller::result ()
{
  std::cout << "method_return<void>\n";
  end ();
}

inline void
perl_interpreter::caller::end ()
{
  PerlInterpreter* my_perl = perl.perl ();

  PUTBACK;
  CHECK_ERROR;
  FREETMPS;
  LEAVE;

  usleep (100000);
}

template<typename R, typename... Args>
inline R
perl_interpreter::call (char const* method, Args const&... args)
{
  caller call (*this, sizeof... (Args) + 1);

  std::cout << "call (";
  output (method);
  call.arg (this);
  call.arg (args...);
  std::cout << ")\n";

  call.call (method, std::is_same<R, void>::value ? G_VOID : G_SCALAR);

  return call.result<R> ();
}
#endif
