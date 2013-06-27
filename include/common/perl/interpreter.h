/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/closure.h"
#include "common/perl/package.h"
#include "common/util/output.h"
#include "common/util/type_traits/identity.h"

// This class owns a PerlInterpreter* that is actually stored in its
// perl_object base. The perl_interpreter class takes care of construction
// and destruction of said PerlInterpreter.
struct perl_interpreter
{
  // Encapsulates arguments received from _start or similar
  // libc startup function.
  struct system_arguments
  {
    int argc;
    int envc;
    char** argv;
    char** env;
  };

  system_arguments args;

  // Creates a new perl object using a given stash and vtable.
  // It uses identity<T> so C++ doesn't infer T from the argument type and
  // picks void by default, so it uses the proper default vtable.
  template<typename T = void>
  SV* newSVptr (typename identity<T>::type* ptr, HV* stash, SV* self, MGVTBL* vtbl = &perl_package<T>::vtbl)
  {
    return newSVptr<void> (ptr, stash, self, vtbl);
  }
  // Same as above but requires ptr to be non-null and self to be a perl hash.
  // This is used for C++ objects that are either intrusively or externally
  // bound to exactly one perl object.
  template<typename T = void>
  SV* newSVobj (typename identity<T>::type* ptr, HV* stash, HV* self, MGVTBL* vtbl = &perl_package<T>::vtbl)
  {
    return newSVobj<void> (ptr, stash, self, vtbl);
  }

  // Returns the magic pointer contained within the SV*.
  void* SvPTR (SV* sv);

  // Creates an SV* out of a C++ object.
  template<typename T> SV* to_sv (T v);
  // The other way around.
  template<typename T> T   sv_to (SV* sv);

  PerlInterpreter* perl () { return my_perl; }

protected:
  PerlInterpreter *my_perl;

protected:
  // Allocates and initialises the PerlInterpreter.
  perl_interpreter (int argc, char* argv[], char* env[]);
  // Destroys and frees the PerlInterpreter.
  ~perl_interpreter ();

private:
  // Helper class that provides some abstraction over perl method invocation
  // stack manipulation.
  struct caller
  {
    // Initialises the stack pointer and allocates space for argv elements.
    caller (perl_interpreter& perl, size_t argv);
    // End of recursion. Does nothing.
    void arg ();
    // Recursively pushes all arguments onto the perl stack after converting
    // them to SV*s using to_sv.
    template<typename T, typename... Args>
    void arg (T const& expr, Args const&... rest);
    // Invokes the actual method after prepending the package name "PurpleBee::".
    void call (char const* method, int flags);
    // Returns the result converted to R using sv_to.
    template<typename R>
    R result ();
    // Frees temporary objects (including the return value, hence it is a
    // separate step.
    void end ();

  private:
    perl_interpreter& perl;
    SV** SP;
    SV* RETVAL;
  };

public:
  // Invokes a perl method using 'this' as the first argument and args
  // converted to scalars for the rest.
  template<typename R, typename... Args>
  R call (char const* method, Args const&... args);

  perl_interpreter& base ()
  {
    return *this;
  }
};

template<> SV* perl_interpreter::newSVptr<void> (void* ptr, HV* stash, SV* self, MGVTBL* vtbl);
template<> SV* perl_interpreter::newSVobj<void> (void* obj, HV* stash, HV* self, MGVTBL* vtbl);

// vim:ft=xs
