MODULE = PurpleBee      PACKAGE = PurpleBee::Sound              PREFIX = purple_sound_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    SOUND_
  const_val (BUDDY_ARRIVE);
  const_val (BUDDY_LEAVE);
  const_val (RECEIVE);
  const_val (FIRST_RECEIVE);
  const_val (SEND);
  const_val (CHAT_JOIN);
  const_val (CHAT_LEAVE);
  const_val (CHAT_YOU_SAY);
  const_val (CHAT_SAY);
  const_val (POUNCE_DEFAULT);
  const_val (CHAT_NICK);
#undef TYPE
}

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
