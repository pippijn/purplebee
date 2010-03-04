#pragma once

#include <iostream>

#include "perl/object.h"
#include "util/output.h"

struct perl_interpreter
  : perl_object
{
  struct arguments
  {
    int argc;
    char** argv;
    char** env;
  };

  arguments args;

  SV* newSVptr (void const *ptr, SV *sv = newSV (0), HV *stash = 0);
  SV* newSVptr (void const *ptr, HV *hv,             HV *stash = 0);
  SV* newSVptr (void const *ptr, AV *av,             HV *stash = 0);

  void* SvPTR (SV* sv);

  template<typename T> SV* to_sv (T v);
  template<typename T> T   sv_to (SV* sv);

protected:
  static PerlInterpreter *my_perl;

  perl_interpreter (int argc, char* argv[], char* env[]);
  ~perl_interpreter ();

private:
  struct CALL
  {
    void check_error ();
    int method_call (char const* method, int flags);

    CALL (perl_interpreter& perl, size_t args)
      : object (perl)
      , RETVAL (&PL_sv_undef)
    {
      dSP;
      ENTER;
      SAVETMPS;
      PUSHMARK (SP);
      EXTEND (SP, args);
      this->SP = SP;
    }

    template<typename T>
    void ARG (T expr)
    {
      PUSHs (sv_2mortal (object.to_sv (expr)));
    }

    void INVOKE (char const* name, int flags)
    {
      PUTBACK;
      int count = method_call (name, flags | G_EVAL);
      SPAGAIN;

      if (count)
        RETVAL = POPs;
    }

    ~CALL ()
    {
      PUTBACK;
      check_error ();
      FREETMPS;
      LEAVE;
    }

    perl_interpreter& object;
    SV* RETVAL;
    SV** SP;
  };

  void push_arguments (CALL& call)
  {
  }

  template<typename T, typename... Args>
  void push_arguments (CALL& call, T const& v, Args const&... args)
  {
    std::cout << ", ";
    output (v);
    call.ARG (v);
    push_arguments (call, args...);
  }

  template<typename R>
  R method_return (SV* sv)
  {
    R retval = sv_to<R> (sv);
    std::cout << "method_return = ";
    output (retval);
    std::cout << '\n';
    return retval;
  }

public:
  template<typename R, typename... Args>
  R call (char const* method, Args const&... args)
  {
    CALL call (*this, sizeof... (Args) + 1);

    std::cout << "call (";
    output (method);
    push_arguments (call, this);
    push_arguments (call, args...);
    std::cout << ")\n";

    call.INVOKE (method, G_SCALAR);

    return method_return<R> (call.RETVAL);
  }

  PerlInterpreter* perl () { return my_perl; }
};

template<>
inline void
perl_interpreter::method_return (SV* sv)
{
  std::cout << "method_return<void>\n";
}
