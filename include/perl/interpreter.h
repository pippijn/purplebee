#pragma once

#include <EXTERN.h>
#include <perl.h>

struct perl_interpreter
{
  struct arguments
  {
    int argc;
    char** argv;
    char** env;
  };

  arguments args;

  PerlInterpreter *my_perl;

  perl_interpreter (int argc, char* argv[], char* env[]);
  ~perl_interpreter ();
};
