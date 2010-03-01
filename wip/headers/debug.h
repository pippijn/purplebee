#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Debug API                                                       */
/**************************************************************************/
/**
 * Outputs debug information.
 *
 * @param level    The debug level.
 * @param category The category (or @c NULL).
 * @param format   The format string.
 */
void purple_debug(PurpleDebugLevel level, const char *category,
				const char *format, ...) G_GNUC_PRINTF(3, 4);

/**
 * Outputs misc. level debug information.
 *
 * This is a wrapper for purple_debug(), and uses PURPLE_DEBUG_MISC as
 * the level.
 *
 * @param category The category (or @c NULL).
 * @param format   The format string.
 *
 * @see purple_debug()
 */
void purple_debug_misc(const char *category, const char *format, ...) G_GNUC_PRINTF(2, 3);

/**
 * Outputs info level debug information.
 *
 * This is a wrapper for purple_debug(), and uses PURPLE_DEBUG_INFO as
 * the level.
 *
 * @param category The category (or @c NULL).
 * @param format   The format string.
 *
 * @see purple_debug()
 */
void purple_debug_info(const char *category, const char *format, ...) G_GNUC_PRINTF(2, 3);

/**
 * Outputs warning level debug information.
 *
 * This is a wrapper for purple_debug(), and uses PURPLE_DEBUG_WARNING as
 * the level.
 *
 * @param category The category (or @c NULL).
 * @param format   The format string.
 *
 * @see purple_debug()
 */
void purple_debug_warning(const char *category, const char *format, ...) G_GNUC_PRINTF(2, 3);

/**
 * Outputs error level debug information.
 *
 * This is a wrapper for purple_debug(), and uses PURPLE_DEBUG_ERROR as
 * the level.
 *
 * @param category The category (or @c NULL).
 * @param format   The format string.
 *
 * @see purple_debug()
 */
void purple_debug_error(const char *category, const char *format, ...) G_GNUC_PRINTF(2, 3);

/**
 * Outputs fatal error level debug information.
 *
 * This is a wrapper for purple_debug(), and uses PURPLE_DEBUG_ERROR as
 * the level.
 *
 * @param category The category (or @c NULL).
 * @param format   The format string.
 *
 * @see purple_debug()
 */
void purple_debug_fatal(const char *category, const char *format, ...) G_GNUC_PRINTF(2, 3);

/**
 * Enable or disable printing debug output to the console.
 *
 * @param enabled TRUE to enable debug output or FALSE to disable it.
 */
void purple_debug_set_enabled(gboolean enabled);

/**
 * Check if console debug output is enabled.
 *
 * @return TRUE if debugging is enabled, FALSE if it is not.
 */
gboolean purple_debug_is_enabled(void);

/**
 * Enable or disable verbose debugging.  This ordinarily should only be called
 * by #purple_debug_init, but there are cases where this can be useful for
 * plugins.
 *
 * @param verbose TRUE to enable verbose debugging or FALSE to disable it.
 *
 * @since 2.6.0
 */
void purple_debug_set_verbose(gboolean verbose);

/**
 * Check if verbose logging is enabled.
 *
 * @return TRUE if verbose debugging is enabled, FALSE if it is not.
 *
 * @since 2.6.0
 */
gboolean purple_debug_is_verbose(void);

/**
 * Enable or disable verbose debugging.  This ordinarily should only be called
 * by #purple_debug_init, but there are cases where this can be useful for
 * plugins.
 *
 * @param unsafe  TRUE to enable verbose debugging or FALSE to disable it.
 *
 * @since 2.6.0
 */
void purple_debug_set_unsafe(gboolean unsafe);

/**
 * Check if unsafe debugging is enabled.
 *
 * @return TRUE if verbose debugging is enabled, FALSE if it is not.
 *
 * @since 2.6.0
 */
gboolean purple_debug_is_unsafe(void);

/*@}*/

/**************************************************************************/
/** @name UI Registration Functions                                       */
/**************************************************************************/
/*@{*/

/**
 * Sets the UI operations structure to be used when outputting debug
 * information.
 *
 * @param ops The UI operations structure.
 */
void purple_debug_set_ui_ops(PurpleDebugUiOps *ops);

/**
 * Returns the UI operations structure used when outputting debug
 * information.
 *
 * @return The UI operations structure in use.
 */
PurpleDebugUiOps *purple_debug_get_ui_ops(void);

/*@}*/

/**************************************************************************/
/** @name Debug Subsystem                                                 */
/**************************************************************************/
/*@{*/

/**
 * Initializes the debug subsystem.
 */
void purple_debug_init(void);

/*@}*/

#ifdef __cplusplus
}
#endif
