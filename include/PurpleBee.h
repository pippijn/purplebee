#pragma once

#include <vector>
#include <string>

#include <purple.h>

#include "perl/interpreter.h"

namespace stash
{
  extern HV* Callback;
  extern HV* PurpleBee;
  extern HV* PurpleBee_Account;
}

struct PurpleBee
  : private perl_interpreter
{
  struct directories
  {
    char const* const user;
  };

  directories dirs;
  std::vector<std::string> protocols;

  PurpleBlistUiOps blist_uiops;
  PurpleCoreUiOps core_uiops;
  PurpleConversationUiOps conversation_uiops;
  PurpleEventLoopUiOps eventloop_uiops;

  PurpleBee (int argc, char* argv[], char* env[]);
  ~PurpleBee ();

  char const* package () const;

  void init ();
  void run ();

  using perl_interpreter::call;
  using perl_interpreter::sv_to;
  using perl_interpreter::to_sv;
};

#define server get_server_instance ()
PurpleBee* get_server_instance ();

void init_server (int argc, char* argv[], char* env[]);
void uninit_server ();
