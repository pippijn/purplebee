#include "perl/interpreter.h"

struct PurpleBee
  : private perl_interpreter
{
  PurpleBee (int argc, char* argv[], char* env[]);
  ~PurpleBee ();

  void run ();
};
