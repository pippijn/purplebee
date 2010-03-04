#pragma once

#include "perl/object.h"
#include "perl/package.h"
#include "util/identity.h"
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

  template<typename T = void>
  SV* newSVptr (typename identity<T>::type* ptr, HV* stash, SV* self, MGVTBL* vtbl = &perl_package<T>::vtbl)
  {
    return newSVptr<void> (ptr, stash, self, vtbl);
  }
  template<typename T = void>
  SV* newSVobj (typename identity<T>::type* ptr, HV* stash, HV* self, MGVTBL* vtbl = &perl_package<T>::vtbl)
  {
    return newSVobj<void> (ptr, stash, self, vtbl);
  }

  void* SvPTR (SV* sv);

  template<typename T> SV* to_sv (T v);
  template<typename T> T   sv_to (SV* sv);

protected:
  PerlInterpreter *my_perl;

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

template<> SV* perl_interpreter::newSVptr<void> (void* ptr, HV* stash, SV* self, MGVTBL* vtbl);
template<> SV* perl_interpreter::newSVobj<void> (void* obj, HV* stash, HV* self, MGVTBL* vtbl);

// vim:ft=xs
