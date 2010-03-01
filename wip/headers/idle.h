#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Idle API                                                        */
/**************************************************************************/
/*@{*/

/**
 * Touch our idle tracker.  This signifies that the user is
 * 'active'.  The conversation code calls this when the
 * user sends an IM, for example.
 */
void purple_idle_touch(void);

/**
 * Fake our idle time by setting the time at which our
 * accounts purportedly became idle.  This is used by
 * the I'dle Mak'er plugin.
 */
void purple_idle_set(time_t time);

/*@}*/

/**************************************************************************/
/** @name Idle Subsystem                                                  */
/**************************************************************************/
/*@{*/

/**
 * Sets the UI operations structure to be used for idle reporting.
 *
 * @param ops The UI operations structure.
 */
void purple_idle_set_ui_ops(PurpleIdleUiOps *ops);

/**
 * Returns the UI operations structure used for idle reporting.
 *
 * @return The UI operations structure in use.
 */
PurpleIdleUiOps *purple_idle_get_ui_ops(void);

/**
 * Initializes the idle system.
 */
void purple_idle_init(void);

/**
 * Uninitializes the idle system.
 */
void purple_idle_uninit(void);

/*@}*/

#ifdef __cplusplus
}
#endif
