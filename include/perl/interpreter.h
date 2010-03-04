#pragma once

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

  SV* newSVobj (void* obj, HV* stash, HV* self);
  SV* newSVptr (void* ptr, HV* stash, SV* self);

  void* SvPTR (SV* sv);

  template<typename T> SV* to_sv (T v);
  template<typename T> T   sv_to (SV* sv);

protected:
  static PerlInterpreter *my_perl;

  perl_interpreter (int argc, char* argv[], char* env[]);
  ~perl_interpreter ();

private:
  struct caller
  {
    caller (perl_interpreter& perl, size_t argv);
    void arg ();
    template<typename T, typename... Args>
    void arg (T const& expr, Args const&... rest);
    void call (char const* method, int flags);
    template<typename R>
    R result ();
    void end ();

  private:
    perl_interpreter& perl;
    SV** SP;
    SV* RETVAL;
  };

public:
  template<typename R, typename... Args>
  R call (char const* method, Args const&... args);

  PerlInterpreter* perl () { return my_perl; }
};
