/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <iostream>
#include <type_traits>

#include "common/debug/dout.h"
#include "common/perl/eval_error.h"
#include "common/perl/interpreter.h"

#define CHECK_ERROR     \
  if (SvTRUE (ERRSV))   \
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
}

template<typename T, typename... Args>
inline void
perl_interpreter::caller::arg (T const& expr, Args const&... rest)
{
  PerlInterpreter* my_perl = perl.perl ();

  PUSHs (sv_2mortal (perl.to_sv (expr)));
  arg (rest...);
}

inline void
perl_interpreter::caller::call (char const* method, int flags)
{
  PerlInterpreter* my_perl = perl.perl ();

  char const* pkg = PACKAGE_NAME;
  char function[strlen (method) + strlen (pkg) + 2 + 1];
  sprintf (function, "%s::%s", pkg, method);

  PUTBACK;
  int count = call_pv (function, flags | G_EVAL);
  SPAGAIN;

  if (count > 0)
    RETVAL = POPs;
}

template<typename R>
inline R
perl_interpreter::caller::result ()
{
  R retval = perl.sv_to<R> (RETVAL);
  end ();

  return retval;
}

template<>
inline void
perl_interpreter::caller::result ()
{
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
}

template<typename R, typename... Args>
inline R
perl_interpreter::call (char const* method, Args const&... args)
{
  caller call (*this, sizeof... (Args) + 1);
  call.arg (this);
  call.arg (args...);
  call.call (method, std::is_same<R, void>::value ? G_VOID : G_SCALAR);
  return call.result<R> ();
}


// This class prints the arguments passed.
struct perl_caller_base
{
  static void print ()
  {
  }

  template<typename T, typename... Args>
  static void print (T const& arg, Args const&... rest)
  {
    dout << ", ";
    dout.pretty (arg);
    print (rest...);
  }
};

// Verbose perl call that outputs to the "ffi" debug channel.
template<typename R, typename... Args>
struct perl_caller
  : perl_caller_base
{
  template<typename Interpreter>
  static R call (Interpreter& perl, char const* method, Args const&... args)
  {
    dout.acquire ();

    dout << "call (";
    dout.pretty (method);
    print (args...);
    dout << ')';
    dout.release (purple_debug_info, "ffi");
    R const& retval = perl.call<R> (method, args...);
    dout.atomic (purple_debug_info, "ffi") ("call to ", method, " returned ", retval);

    return retval;
  }
};

// Specialisation for void-calls.
template<typename... Args>
struct perl_caller<void, Args...>
  : perl_caller_base
{
  template<typename Interpreter>
  static void call (Interpreter& perl, char const* method, Args const&... args)
  {
    dout.acquire ();

    dout << "call (";
    dout.pretty (method);
    print (args...);
    dout << ')';
    dout.release (purple_debug_info, "ffi");

    // XXX: deadlock if the following call ends up here again. maybe remove
    // the whole locking thing and start stacking stringstreams?
    perl.call<void> (method, args...);
    dout.atomic (purple_debug_info, "ffi") ("call returned void");
  }
};

// This function just creates a perl_caller, taking advantage of argument
// type deduction to simplify client code.
template<typename Interpreter, typename R, typename... Args>
static inline R
perl_call (Interpreter& perl, char const* method, Args const&... args)
{
  return perl_caller<R, Args...>::call (perl, method, args...);
}

// vim:ft=xs
