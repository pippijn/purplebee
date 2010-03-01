#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Sound API                                                       */
/**************************************************************************/
/*@{*/

/**
 * Plays the specified sound file.
 *
 * @param filename The file to play.
 * @param account The account that this sound is associated with, or
 *        NULL if the sound is not associated with any specific
 *        account.  This is needed for the "sounds while away?"
 *        preference to work correctly.
 */
void purple_sound_play_file(const char *filename, const PurpleAccount *account);

/**
 * Plays the sound associated with the specified event.
 *
 * @param event The event.
 * @param account The account that this sound is associated with, or
 *        NULL if the sound is not associated with any specific
 *        account.  This is needed for the "sounds while away?"
 *        preference to work correctly.
 */
void purple_sound_play_event(PurpleSoundEventID event, const PurpleAccount *account);

/**
 * Sets the UI sound operations
 *
 * @param ops The UI sound operations structure.
 */
void purple_sound_set_ui_ops(PurpleSoundUiOps *ops);

/**
 * Gets the UI sound operations
 *
 * @return The UI sound operations structure.
 */
PurpleSoundUiOps *purple_sound_get_ui_ops(void);

/**
 * Initializes the sound subsystem
 */
void purple_sound_init(void);

/**
 * Shuts down the sound subsystem
 */
void purple_sound_uninit(void);

/**
 * Returns the sound subsystem handle.
 *
 * @return The sound subsystem handle.
 */
void *purple_sounds_get_handle(void);

/*@}*/

#ifdef __cplusplus
}
#endif
