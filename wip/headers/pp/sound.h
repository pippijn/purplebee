void purple_sound_play_file (const char* filename, const PurpleAccount* account);
void purple_sound_play_event (PurpleSoundEventID event, const PurpleAccount* account);
void purple_sound_set_ui_ops (PurpleSoundUiOps* ops);
PurpleSoundUiOps* purple_sound_get_ui_ops (void);
void purple_sound_init (void);
void purple_sound_uninit (void);
void* purple_sounds_get_handle (void);
