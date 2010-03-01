/**
 * GObject foo.
 * @internal.
 */
GType purple_sound_theme_get_type(void);

/**
 * Returns a copy of the filename for the sound event.
 *
 * @param theme The theme.
 * @param event The purple sound event to look up.
 *
 * @returns The filename of the sound event.
 */
const gchar *purple_sound_theme_get_file(PurpleSoundTheme *theme,
		const gchar *event);

/**
 * Returns a copy of the directory and filename for the sound event
 *
 * @param theme The theme.
 * @param event The purple sound event to look up
 *
 * @returns The directory + '/' + filename of the sound event.  This is
 *          a newly allocated string that should be freed with g_free.
 */
gchar *purple_sound_theme_get_file_full(PurpleSoundTheme *theme,
		const gchar *event);

/**
 * Sets the filename for a given sound event
 *
 * @param theme    The theme.
 * @param event    the purple sound event to look up
 * @param filename the name of the file to be used for the event
 */
void purple_sound_theme_set_file(PurpleSoundTheme *theme,
		const gchar *event,
		const gchar *filename);
