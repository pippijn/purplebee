#pragma once

#include <vector>
#include <string>

#include <purple.h>

#include "perl/interpreter.h"

namespace stash
{
  extern HV* Callback;
}

void init_server (int argc, char* argv[], char* env[]);

struct PurpleBee
  : private perl_interpreter
{
  struct directories
  {
    char const* const user;
  };

  directories dirs;
  std::vector<std::string> protocols;

  PurpleCoreUiOps core_uiops;
  PurpleConversationUiOps conversation_uiops;
  PurpleEventLoopUiOps eventloop_uiops;

  PurpleBee (int argc, char* argv[], char* env[]);
  ~PurpleBee ();

  char const* package () const;

  void init ();
  void run ();

  using perl_interpreter::call;
  using perl_interpreter::newSVptr;
  using perl_interpreter::SvPTR;
};

#define server get_server_instance ()
PurpleBee* get_server_instance ();
