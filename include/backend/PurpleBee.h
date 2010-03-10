/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

#include "common/perl/interpreter.h"

// The main class that does everything. This class itself is not limited to
// one instance, but libpurple is, so this class is unfortunately a singleton.
struct PurpleBee
  : private perl_interpreter
{
  friend struct perl_interpreter;

  struct directories
  {
    char const* const user;
    char const* const plugins_saved;
    char const* const plugins_path;
  };

  directories dirs;

  PurpleAccountUiOps account_uiops;
  PurpleBlistUiOps blist_uiops;
  PurpleConnectionUiOps connection_uiops;
  PurpleConversationUiOps conversation_uiops;
  PurpleCoreUiOps core_uiops;
  PurpleDebugUiOps debug_uiops;
  PurpleDnsQueryUiOps dnsquery_uiops;
  PurpleEventLoopUiOps eventloop_uiops;
  PurpleIdleUiOps idle_uiops;
  PurpleNotifyUiOps notify_uiops;
  PurplePrivacyUiOps privacy_uiops;
  PurpleRequestUiOps request_uiops;
  PurpleRoomlistUiOps roomlist_uiops;
  PurpleSoundUiOps sound_uiops;
  PurpleWhiteboardUiOps whiteboard_uiops;
  PurpleXferUiOps xfer_uiops;

  PurpleBee (int argc, char* argv[], char* env[]);
  ~PurpleBee ();

  char const* package () const;

  void init ();
  void boot ();
  void main ();

  void valgrind (bool full);
  void fault (int kind);

  using perl_interpreter::call;
  using perl_interpreter::sv_to;
  using perl_interpreter::to_sv;
};

#define server get_server_instance ()
PurpleBee* get_server_instance ();

void init_server (int argc, char* argv[], char* env[]);
void uninit_server ();
