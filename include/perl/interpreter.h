#pragma once

#include <EXTERN.h>
#include <perl.h>

#define CALL_BEGIN(args)        dSP; ENTER; SAVETMPS; PUSHMARK (SP); EXTEND (SP, args)
#define CALL_ARG(expr)          PUSHs (sv_2mortal (to_sv (expr)))
#define CALL_CALL(name, flags)  PUTBACK; int count = method_call (name, (flags) | G_EVAL); SPAGAIN;
#define CALL_END                PUTBACK; check_error (); FREETMPS; LEAVE

struct perl_interpreter
{
  struct arguments
  {
    int argc;
    char** argv;
    char** env;
  };

  arguments args;
  virtual char const* package () const = 0;

  static PerlInterpreter *my_perl;

  perl_interpreter (int argc, char* argv[], char* env[]);
  ~perl_interpreter ();

  void check_error ();

  template<typename T>
  static SV* to_sv (T v);
  template<typename T>
  static T sv_to (SV* sv);

  void push_arguments (SV** sp)
  {
  }

  template<typename T, typename... Args>
  void push_arguments (SV** sp, T const& v, Args const&... args)
  {
    CALL_ARG (v);
    push_arguments (sp, args...);
  }

  int method_call (char const* method, int flags);

  template<typename R, typename... Args>
  R call (char const* method, Args const&... args)
  {
    CALL_BEGIN (sizeof... args);
    push_arguments (SP, args...);
    CALL_CALL (method, G_SCALAR);
    SV* retval = &PL_sv_undef;
    if (count) retval = POPs;
    CALL_END;

    return sv_to<R> (retval);
  }
};
