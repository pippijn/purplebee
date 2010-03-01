#include "PurpleBee.h"
#include "uiops/sound.h"

#define OPS "Ops::Sound::"

namespace uiops
{
  void
  sound::init (void)
  {
    return server->call<void> (OPS "init");
  }

  void
  sound::uninit (void)
  {
    return server->call<void> (OPS "uninit");
  }

  void
  sound::play_file (const char* filename)
  {
    return server->call<void> (OPS "play_file", filename);
  }

  void
  sound::play_event (PurpleSoundEventID event)
  {
    return server->call<void> (OPS "play_event", event);
  }

  PurpleSoundUiOps
  sound::create ()
  {
    return {
      init,
      uninit,
      play_file,
      play_event,
    };
  }
}
