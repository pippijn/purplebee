/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/sound.h"

#define OPS "UiOps::Sound::"

namespace uiops
{
  void
  sound::init (void)
  {
    return perl_call<void> (OPS "init");
  }

  void
  sound::uninit (void)
  {
    return perl_call<void> (OPS "uninit");
  }

  void
  sound::play_file (const char* filename)
  {
    return perl_call<void> (OPS "play_file", filename);
  }

  void
  sound::play_event (PurpleSoundEventID event)
  {
    return perl_call<void> (OPS "play_event", event);
  }

  PurpleSoundUiOps
  sound::create ()
  {
    return {
      init,
      uninit,
      play_file,
      play_event,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }

  void
  sound::destroy (G_GNUC_UNUSED PurpleSoundUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying sound callbacks");
  }
}
