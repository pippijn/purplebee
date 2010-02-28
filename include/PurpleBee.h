#pragma once

#include <vector>
#include <string>

#include <purple.h>

#include "perl/interpreter.h"

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

  void run ();
};

extern PurpleBee* server;
