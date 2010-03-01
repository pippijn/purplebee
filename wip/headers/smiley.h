#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Custom Smiley API                                               */
/**************************************************************************/
/*@{*/

/**
 * GObject-fu.
 * @internal.
 */
GType purple_smiley_get_type(void);

/**
 * Creates a new custom smiley from a PurpleStoredImage.
 *
 * If a custom smiley with the given shortcut already exists, it
 * will be automaticaly returned.
 *
 * @param img         The image associated with the smiley.
 * @param shortcut    The associated shortcut (e.g. "(homer)").
 *
 * @return The custom smiley.
 */
PurpleSmiley *
purple_smiley_new(PurpleStoredImage *img, const char *shortcut);

/**
 * Creates a new custom smiley, reading the image data from a file.
 *
 * If a custom smiley with the given shortcut already exists, it
 * will be automaticaly returned.
 *
 * @param shortcut           The associated shortcut (e.g. "(homer)").
 * @param filepath           The image file.
 *
 * @return The custom smiley.
 */
PurpleSmiley *
purple_smiley_new_from_file(const char *shortcut, const char *filepath);

/**
 * Destroys the custom smiley and releases the associated resources.
 *
 * @param smiley    The custom smiley.
 */
void
purple_smiley_delete(PurpleSmiley *smiley);

/**
 * Changes the custom smiley's shortcut.
 *
 * @param smiley    The custom smiley.
 * @param shortcut  The new shortcut. A custom smiley with this shortcut
 *                  cannot already be in use.
 *
 * @return TRUE if the shortcut was changed. FALSE otherwise.
 */
gboolean
purple_smiley_set_shortcut(PurpleSmiley *smiley, const char *shortcut);

/**
 * Changes the custom smiley's image data.
 *
 * @param smiley             The custom smiley.
 * @param smiley_data        The custom smiley data, which the smiley code
 *                           takes ownership of and will free.
 * @param smiley_data_len    The length of the data in @a smiley_data.
 */
void
purple_smiley_set_data(PurpleSmiley *smiley, guchar *smiley_data,
                                           size_t smiley_data_len);

/**
 * Returns the custom smiley's associated shortcut (e.g. "(homer)").
 *
 * @param smiley   The custom smiley.
 *
 * @return The shortcut.
 */
const char *purple_smiley_get_shortcut(const PurpleSmiley *smiley);

/**
 * Returns the custom smiley data's checksum.
 *
 * @param smiley   The custom smiley.
 *
 * @return The checksum.
 */
const char *purple_smiley_get_checksum(const PurpleSmiley *smiley);

/**
 * Returns the PurpleStoredImage with the reference counter incremented.
 *
 * The returned PurpleStoredImage reference counter must be decremented
 * when the caller is done using it.
 *
 * @param smiley   The custom smiley.
 *
 * @return A PurpleStoredImage.
 */
PurpleStoredImage *purple_smiley_get_stored_image(const PurpleSmiley *smiley);

/**
 * Returns the custom smiley's data.
 *
 * @param smiley  The custom smiley.
 * @param len     If not @c NULL, the length of the image data returned
 *                will be set in the location pointed to by this.
 *
 * @return A pointer to the custom smiley data.
 */
gconstpointer purple_smiley_get_data(const PurpleSmiley *smiley, size_t *len);

/**
 * Returns an extension corresponding to the custom smiley's file type.
 *
 * @param smiley  The custom smiley.
 *
 * @return The custom smiley's extension, "icon" if unknown, or @c NULL if
 *         the image data has disappeared.
 */
const char *purple_smiley_get_extension(const PurpleSmiley *smiley);

/**
 * Returns a full path to an custom smiley.
 *
 * If the custom smiley has data and the file exists in the cache, this
 * will return a full path to the cached file.
 *
 * In general, it is not appropriate to be poking in the file cache
 * directly.  If you find yourself wanting to use this function, think
 * very long and hard about it, and then don't.
 *
 * Think some more.
 *
 * @param smiley  The custom smiley.
 *
 * @return A full path to the file, or @c NULL under various conditions.
 *         The caller should use g_free to free the returned string.
 */
char *purple_smiley_get_full_path(PurpleSmiley *smiley);

/*@}*/


/**************************************************************************/
/** @name Custom Smiley Subsystem API                                     */
/**************************************************************************/
/*@{*/

/**
 * Returns a list of all custom smileys. The caller is responsible for freeing
 * the list.
 *
 * @return A list of all custom smileys.
 */
GList *
purple_smileys_get_all(void);

/**
 * Returns a custom smiley given its shortcut.
 *
 * @param shortcut The custom smiley's shortcut.
 *
 * @return The custom smiley if found, or @c NULL if not found.
 */
PurpleSmiley *
purple_smileys_find_by_shortcut(const char *shortcut);

/**
 * Returns a custom smiley given its checksum.
 *
 * @param checksum The custom smiley's checksum.
 *
 * @return The custom smiley if found, or @c NULL if not found.
 */
PurpleSmiley *
purple_smileys_find_by_checksum(const char *checksum);

/**
 * Returns the directory used to store custom smiley cached files.
 *
 * The default directory is PURPLEDIR/custom_smiley.
 *
 * @return The directory in which to store custom smileys cached files.
 */
const char *purple_smileys_get_storing_dir(void);

/**
 * Initializes the custom smiley subsystem.
 */
void purple_smileys_init(void);

/**
 * Uninitializes the custom smiley subsystem.
 */
void purple_smileys_uninit(void);

/*@}*/

#ifdef __cplusplus
}
#endif
