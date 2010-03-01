#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Room List API                                                   */
/**************************************************************************/
/*@{*/

/**
 * This is used to get the room list on an account, asking the UI
 * to pop up a dialog with the specified account already selected,
 * and pretend the user clicked the get list button.
 * While we're pretending, predend I didn't say anything about dialogs
 * or buttons, since this is the core.
 *
 * @param account The account to get the list on.
 */
void purple_roomlist_show_with_account(PurpleAccount *account);

/**
 * Returns a newly created room list object.
 *
 * It has an initial reference count of 1.
 *
 * @param account The account that's listing rooms.
 * @return The new room list handle.
 */
PurpleRoomlist *purple_roomlist_new(PurpleAccount *account);

/**
 * Increases the reference count on the room list.
 *
 * @param list The object to ref.
 */
void purple_roomlist_ref(PurpleRoomlist *list);

/**
 * Decreases the reference count on the room list.
 *
 * The room list will be destroyed when this reaches 0.
 *
 * @param list The room list object to unref and possibly
 *             destroy.
 */
void purple_roomlist_unref(PurpleRoomlist *list);

/**
 * Set the different field types and their names for this protocol.
 *
 * This must be called before purple_roomlist_room_add().
 *
 * @param list The room list.
 * @param fields A GList of PurpleRoomlistField's. UI's are encouraged
 *               to default to displaying them in the order given.
 */
void purple_roomlist_set_fields(PurpleRoomlist *list, GList *fields);

/**
 * Set the "in progress" state of the room list.
 *
 * The UI is encouraged to somehow hint to the user
 * whether or not we're busy downloading a room list or not.
 *
 * @param list The room list.
 * @param in_progress We're downloading it, or we're not.
 */
void purple_roomlist_set_in_progress(PurpleRoomlist *list, gboolean in_progress);

/**
 * Gets the "in progress" state of the room list.
 *
 * The UI is encouraged to somehow hint to the user
 * whether or not we're busy downloading a room list or not.
 *
 * @param list The room list.
 * @return True if we're downloading it, or false if we're not.
 */
gboolean purple_roomlist_get_in_progress(PurpleRoomlist *list);

/**
 * Adds a room to the list of them.
 *
 * @param list The room list.
 * @param room The room to add to the list. The GList of fields must be in the same
               order as was given in purple_roomlist_set_fields().
*/
void purple_roomlist_room_add(PurpleRoomlist *list, PurpleRoomlistRoom *room);

/**
 * Returns a PurpleRoomlist structure from the prpl, and
 * instructs the prpl to start fetching the list.
 *
 * @param gc The PurpleConnection to have get a list.
 *
 * @return A PurpleRoomlist* or @c NULL if the protocol
 *         doesn't support that.
 */
PurpleRoomlist *purple_roomlist_get_list(PurpleConnection *gc);

/**
 * Tells the prpl to stop fetching the list.
 * If this is possible and done, the prpl will
 * call set_in_progress with @c FALSE and possibly
 * unref the list if it took a reference.
 *
 * @param list The room list to cancel a get_list on.
 */
void purple_roomlist_cancel_get_list(PurpleRoomlist *list);

/**
 * Tells the prpl that a category was expanded.
 *
 * On some protocols, the rooms in the category
 * won't be fetched until this is called.
 *
 * @param list     The room list.
 * @param category The category that was expanded. The expression
 *                 (category->type & PURPLE_ROOMLIST_ROOMTYPE_CATEGORY)
 *                 must be true.
 */
void purple_roomlist_expand_category(PurpleRoomlist *list, PurpleRoomlistRoom *category);

/**
 * Get the list of fields for a roomlist.
 *
 * @param roomlist  The roomlist, which must not be @c NULL.
 * @constreturn A list of fields
 * @since 2.4.0
 */
GList * purple_roomlist_get_fields(PurpleRoomlist *roomlist);

/*@}*/

/**************************************************************************/
/** @name Room API                                                        */
/**************************************************************************/
/*@{*/

/**
 * Creates a new room, to be added to the list.
 *
 * @param type The type of room.
 * @param name The name of the room.
 * @param parent The room's parent, if any.
 *
 * @return A new room.
 */
PurpleRoomlistRoom *purple_roomlist_room_new(PurpleRoomlistRoomType type, const gchar *name,
                                         PurpleRoomlistRoom *parent);

/**
 * Adds a field to a room.
 *
 * @param list The room list the room belongs to.
 * @param room The room.
 * @param field The field to append. Strings get g_strdup'd internally.
 */
void purple_roomlist_room_add_field(PurpleRoomlist *list, PurpleRoomlistRoom *room, gconstpointer field);

/**
 * Join a room, given a PurpleRoomlistRoom and it's associated PurpleRoomlist.
 *
 * @param list The room list the room belongs to.
 * @param room The room to join.
 */
void purple_roomlist_room_join(PurpleRoomlist *list, PurpleRoomlistRoom *room);

/**
 * Get the type of a room.
 * @param room  The room, which must not be @c NULL.
 * @return The type of the room.
 * @since 2.4.0
 */
PurpleRoomlistRoomType purple_roomlist_room_get_type(PurpleRoomlistRoom *room);

/**
 * Get the name of a room.
 * @param room  The room, which must not be @c NULL.
 * @return The name of the room.
 * @since 2.4.0
 */
const char * purple_roomlist_room_get_name(PurpleRoomlistRoom *room);

/**
 * Get the parent of a room.
 * @param room  The room, which must not be @c NULL.
 * @return The parent of the room, which can be @c NULL.
 * @since 2.4.0
 */
PurpleRoomlistRoom * purple_roomlist_room_get_parent(PurpleRoomlistRoom *room);

/**
 * Get the list of fields for a room.
 *
 * @param room  The room, which must not be @c NULL.
 * @constreturn A list of fields
 * @since 2.4.0
 */
GList * purple_roomlist_room_get_fields(PurpleRoomlistRoom *room);

/*@}*/

/**************************************************************************/
/** @name Room Field API                                                  */
/**************************************************************************/
/*@{*/

/**
 * Creates a new field.
 *
 * @param type   The type of the field.
 * @param label  The i18n'ed, user displayable name.
 * @param name   The internal name of the field.
 * @param hidden Hide the field.
 *
 * @return A new PurpleRoomlistField, ready to be added to a GList and passed to
 *         purple_roomlist_set_fields().
 */
PurpleRoomlistField *purple_roomlist_field_new(PurpleRoomlistFieldType type,
                                           const gchar *label, const gchar *name,
                                           gboolean hidden);

/**
 * Get the type of a field.
 *
 * @param field  A PurpleRoomlistField, which must not be @c NULL.
 *
 * @return  The type of the field.
 * @since 2.4.0
 */
PurpleRoomlistFieldType purple_roomlist_field_get_type(PurpleRoomlistField *field);

/**
 * Get the label of a field.
 *
 * @param field  A PurpleRoomlistField, which must not be @c NULL.
 *
 * @return  The label of the field.
 * @since 2.4.0
 */
const char * purple_roomlist_field_get_label(PurpleRoomlistField *field);

/**
 * Check whether a roomlist-field is hidden.
 * @param field  A PurpleRoomlistField, which must not be @c NULL.
 *
 * @return  @c TRUE if the field is hidden, @c FALSE otherwise.
 * @since 2.4.0
 */
gboolean purple_roomlist_field_get_hidden(PurpleRoomlistField *field);

/*@}*/

/**************************************************************************/
/** @name UI Registration Functions                                       */
/**************************************************************************/
/*@{*/

/**
 * Sets the UI operations structure to be used in all purple room lists.
 *
 * @param ops The UI operations structure.
 */
void purple_roomlist_set_ui_ops(PurpleRoomlistUiOps *ops);

/**
 * Returns the purple window UI operations structure to be used in
 * new windows.
 *
 * @return A filled-out PurpleRoomlistUiOps structure.
 */
PurpleRoomlistUiOps *purple_roomlist_get_ui_ops(void);

/*@}*/

#ifdef __cplusplus
}
#endif
