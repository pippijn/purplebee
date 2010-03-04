#pragma once

#include <purple.h>

#include "perl/interpreter.h"

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
  void run ();

  void valgrind (bool full);

  using perl_interpreter::call;
  using perl_interpreter::sv_to;
  using perl_interpreter::to_sv;
};

#define server get_server_instance ()
PurpleBee* get_server_instance ();

void init_server (int argc, char* argv[], char* env[]);
void uninit_server ();

typedef gssize (*PurpleXferReadFunction)(guchar**, PurpleXfer*);
typedef gssize (*PurpleXferWriteFunction)(const guchar*, size_t, PurpleXfer*);
typedef void (*PurpleXferAckFunction)(PurpleXfer*, const guchar*, size_t);
typedef void (*PurpleXferFunction)(PurpleXfer*);
typedef PurpleXferFunction PurpleXferRequestDeniedFunction;
typedef void (*PurplePounceFunction)(PurplePounce* pounce);
typedef void (*PurpleConversationFunction)(PurpleConversation* conv);
