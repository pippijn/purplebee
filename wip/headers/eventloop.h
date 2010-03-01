#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Event Loop API                                                  */
/**************************************************************************/
/*@{*/
/**
 * Creates a callback timer.
 *
 * The timer will repeat until the function returns @c FALSE. The
 * first call will be at the end of the first interval.
 *
 * If the timer is in a multiple of seconds, use purple_timeout_add_seconds()
 * instead as it allows UIs to group timers for power efficiency.
 *
 * @param interval	The time between calls of the function, in
 *                      milliseconds.
 * @param function	The function to call.
 * @param data		data to pass to @a function.
 * @return A handle to the timer which can be passed to
 *         purple_timeout_remove() to remove the timer.
 */
guint purple_timeout_add(guint interval, GSourceFunc function, gpointer data);

/**
 * Creates a callback timer.
 *
 * The timer will repeat until the function returns @c FALSE. The
 * first call will be at the end of the first interval.
 *
 * This function allows UIs to group timers for better power efficiency.  For
 * this reason, @a interval may be rounded by up to a second.
 *
 * @param interval	The time between calls of the function, in
 *                      seconds.
 * @param function	The function to call.
 * @param data		data to pass to @a function.
 * @return A handle to the timer which can be passed to
 *         purple_timeout_remove() to remove the timer.
 *
 * @since 2.1.0
 */
guint purple_timeout_add_seconds(guint interval, GSourceFunc function, gpointer data);

/**
 * Removes a timeout handler.
 *
 * @param handle The handle, as returned by purple_timeout_add().
 *
 * @return @c TRUE if the handler was successfully removed.
 */
gboolean purple_timeout_remove(guint handle);

/**
 * Adds an input handler.
 *
 * @param fd        The input file descriptor.
 * @param cond      The condition type.
 * @param func      The callback function for data.
 * @param user_data User-specified data.
 *
 * @return The resulting handle (will be greater than 0).
 * @see g_io_add_watch_full
 */
guint purple_input_add(int fd, PurpleInputCondition cond,
                       PurpleInputFunction func, gpointer user_data);

/**
 * Removes an input handler.
 *
 * @param handle The handle of the input handler. Note that this is the return
 *               value from purple_input_add(), <i>not</i> the file descriptor.
 */
gboolean purple_input_remove(guint handle);

/**
 * Get the current error status for an input.
 *
 * The return value and error follow getsockopt() with a level of SOL_SOCKET and an
 * option name of SO_ERROR, and this is how the error is determined if the UI does not
 * implement the input_get_error UI op.
 *
 * @param fd        The input file descriptor.
 * @param error     A pointer to an @c int which on return will have the error, or
 *                  @c 0 if no error.
 *
 * @return @c 0 if there is no error; @c -1 if there is an error, in which case
 *         @a errno will be set.
 */
int
purple_input_get_error(int fd, int *error);


/*@}*/


/**************************************************************************/
/** @name UI Registration Functions                                       */
/**************************************************************************/
/*@{*/
/**
 * Sets the UI operations structure to be used for accounts.
 *
 * @param ops The UI operations structure.
 */
void purple_eventloop_set_ui_ops(PurpleEventLoopUiOps *ops);

/**
 * Returns the UI operations structure used for accounts.
 *
 * @return The UI operations structure in use.
 */
PurpleEventLoopUiOps *purple_eventloop_get_ui_ops(void);

/*@}*/

#ifdef __cplusplus
}
#endif
