#pragma once

#include <vector>
#include <string>

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
  std::vector<std::string> protocols;

  PurpleAccountUiOps account_ops;
  PurpleBlistUiOps blist_ops;
  PurpleConnectionUiOps connection_ops;
  PurpleConversationUiOps conversation_ops;
  PurpleCoreUiOps core_ops;
  PurpleDebugUiOps debug_ops;
  PurpleDnsQueryUiOps dnsquery_ops;
  PurpleEventLoopUiOps eventloop_ops;
  PurpleIdleUiOps idle_ops;
  PurpleNotifyUiOps notify_ops;
  PurplePrivacyUiOps privacy_ops;
  PurpleRequestUiOps request_ops;
  PurpleRoomlistUiOps roomlist_ops;
  PurpleSoundUiOps sound_ops;
  PurpleWhiteboardUiOps whiteboard_ops;
  PurpleXferUiOps xfer_ops;

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

typedef gssize (*PurpleXferReadFunction)(guchar**, PurpleXfer*);
typedef gssize (*PurpleXferWriteFunction)(const guchar*, size_t, PurpleXfer*);
typedef void (*PurpleXferAckFunction)(PurpleXfer*, const guchar*, size_t);
typedef void (*PurpleXferFunction)(PurpleXfer*);
typedef PurpleXferFunction PurpleXferRequestDeniedFunction;
typedef void (*PurplePounceFunction)(PurplePounce* pounce);
typedef void (*PurpleConversationFunction)(PurpleConversation* conv);
