#pragma once

#include <purple.h>

namespace uiops
{
  struct sound
  {
    static void init (void);
    static void uninit (void);
    static void play_file (const char* filename);
    static void play_event (PurpleSoundEventID event);

    static PurpleSoundUiOps create ();
  };
}
