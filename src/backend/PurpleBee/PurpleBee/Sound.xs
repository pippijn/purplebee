MODULE = PurpleBee      PACKAGE = PurpleBee::Sound              PREFIX = purple_sound_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


void
purple_sound_play_file (char const* filename, PurpleAccount* account);

void
purple_sound_play_event (PurpleSoundEventID event, PurpleAccount* account);

void
purple_sound_set_ui_ops (PurpleSoundUiOps* ops);

PurpleSoundUiOps*
purple_sound_get_ui_ops ();

void
purple_sound_init ();

void
purple_sound_uninit ();
