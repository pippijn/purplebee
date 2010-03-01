#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/******************************************************************************/
/** @name PurpleWhiteboard API                                                  */
/******************************************************************************/
/*@{*/

/**
 * Sets the UI operations
 *
 * @param ops The UI operations to set
 */
void purple_whiteboard_set_ui_ops(PurpleWhiteboardUiOps *ops);

/**
 * Sets the prpl operations for a whiteboard
 *
 * @param wb  The whiteboard for which to set the prpl operations
 * @param ops The prpl operations to set
 */
void purple_whiteboard_set_prpl_ops(PurpleWhiteboard *wb, PurpleWhiteboardPrplOps *ops);

/**
 * Creates a whiteboard
 *
 * @param account The account.
 * @param who     Who you're drawing with.
 * @param state   The state.
 *
 * @return The new whiteboard
 */
PurpleWhiteboard *purple_whiteboard_create(PurpleAccount *account, const char *who, int state);

/**
 * Destroys a whiteboard
 *
 * @param wb The whiteboard.
 */
void purple_whiteboard_destroy(PurpleWhiteboard *wb);

/**
 * Starts a whiteboard
 *
 * @param wb The whiteboard.
 */
void purple_whiteboard_start(PurpleWhiteboard *wb);

/**
 * Finds a whiteboard from an account and user.
 *
 * @param account The account.
 * @param who     The user.
 *
 * @return The whiteboard if found, otherwise @c NULL.
 */
PurpleWhiteboard *purple_whiteboard_get_session(const PurpleAccount *account, const char *who);

/**
 * Destorys a drawing list for a whiteboard
 *
 * @param draw_list The drawing list.
 */
void purple_whiteboard_draw_list_destroy(GList *draw_list);

/**
 * Gets the dimension of a whiteboard.
 *
 * @param wb		The whiteboard.
 * @param width		The width to be set.
 * @param height	The height to be set.
 *
 * @return TRUE if the values of width and height were set.
 */
gboolean purple_whiteboard_get_dimensions(const PurpleWhiteboard *wb, int *width, int *height);

/**
 * Sets the dimensions for a whiteboard.
 *
 * @param wb     The whiteboard.
 * @param width  The width.
 * @param height The height.
 */
void purple_whiteboard_set_dimensions(PurpleWhiteboard *wb, int width, int height);

/**
 * Draws a point on a whiteboard.
 *
 * @param wb    The whiteboard.
 * @param x     The x coordinate.
 * @param y     The y coordinate.
 * @param color The color to use.
 * @param size  The brush size.
 */
void purple_whiteboard_draw_point(PurpleWhiteboard *wb, int x, int y, int color, int size);

/**
 * Send a list of points to draw to the buddy.
 *
 * @param wb	The whiteboard
 * @param list	A GList of points
 */
void purple_whiteboard_send_draw_list(PurpleWhiteboard *wb, GList *list);

/**
 * Draws a line on a whiteboard
 *
 * @param wb    The whiteboard.
 * @param x1    The top-left x coordinate.
 * @param y1    The top-left y coordinate.
 * @param x2    The bottom-right x coordinate.
 * @param y2    The bottom-right y coordinate.
 * @param color The color to use.
 * @param size  The brush size.
 */
void purple_whiteboard_draw_line(PurpleWhiteboard *wb, int x1, int y1, int x2, int y2, int color, int size);

/**
 * Clears a whiteboard
 *
 * @param wb The whiteboard.
 */
void purple_whiteboard_clear(PurpleWhiteboard *wb);

/**
 * Sends a request to the buddy to clear the whiteboard.
 *
 * @param wb The whiteboard
 */
void purple_whiteboard_send_clear(PurpleWhiteboard *wb);

/**
 * Sends a request to change the size and color of the brush.
 *
 * @param wb	The whiteboard
 * @param size	The size of the brush
 * @param color	The color of the brush
 */
void purple_whiteboard_send_brush(PurpleWhiteboard *wb, int size, int color);

/**
 * Gets the size and color of the brush.
 *
 * @param wb	The whiteboard
 * @param size	The size of the brush
 * @param color	The color of the brush
 *
 * @return	TRUE if the size and color were set.
 */
gboolean purple_whiteboard_get_brush(const PurpleWhiteboard *wb, int *size, int *color);

/**
 * Sets the size and color of the brush.
 *
 * @param wb	The whiteboard
 * @param size	The size of the brush
 * @param color	The color of the brush
 */
void purple_whiteboard_set_brush(PurpleWhiteboard *wb, int size, int color);

/*@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */
