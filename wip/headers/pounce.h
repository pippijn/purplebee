#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Buddy Pounce API                                                */
/**************************************************************************/
/*@{*/

/**
 * Creates a new buddy pounce.
 *
 * @param ui_type The type of UI the pounce is for.
 * @param pouncer The account that will pounce.
 * @param pouncee The buddy to pounce on.
 * @param event   The event(s) to pounce on.
 * @param option  Pounce options.
 *
 * @return The new buddy pounce structure.
 */
PurplePounce *purple_pounce_new(const char *ui_type, PurpleAccount *pouncer,
							const char *pouncee, PurplePounceEvent event,
							PurplePounceOption option);

/**
 * Destroys a buddy pounce.
 *
 * @param pounce The buddy pounce.
 */
void purple_pounce_destroy(PurplePounce *pounce);

/**
 * Destroys all buddy pounces for the account
 *
 * @param account The account to remove all pounces from.
 */
void purple_pounce_destroy_all_by_account(PurpleAccount *account);

/**
 * Sets the events a pounce should watch for.
 *
 * @param pounce The buddy pounce.
 * @param events The events to watch for.
 */
void purple_pounce_set_events(PurplePounce *pounce, PurplePounceEvent events);

/**
 * Sets the options for a pounce.
 *
 * @param pounce  The buddy pounce.
 * @param options The options for the pounce.
 */
void purple_pounce_set_options(PurplePounce *pounce, PurplePounceOption options);

/**
 * Sets the account that will do the pouncing.
 *
 * @param pounce  The buddy pounce.
 * @param pouncer The account that will pounce.
 */
void purple_pounce_set_pouncer(PurplePounce *pounce, PurpleAccount *pouncer);

/**
 * Sets the buddy a pounce should pounce on.
 *
 * @param pounce  The buddy pounce.
 * @param pouncee The buddy to pounce on.
 */
void purple_pounce_set_pouncee(PurplePounce *pounce, const char *pouncee);

/**
 * Sets whether or not the pounce should be saved after execution.
 *
 * @param pounce The buddy pounce.
 * @param save   @c TRUE if the pounce should be saved, or @c FALSE otherwise.
 */
void purple_pounce_set_save(PurplePounce *pounce, gboolean save);

/**
 * Registers an action type for the pounce.
 *
 * @param pounce The buddy pounce.
 * @param name   The action name.
 */
void purple_pounce_action_register(PurplePounce *pounce, const char *name);

/**
 * Enables or disables an action for a pounce.
 *
 * @param pounce  The buddy pounce.
 * @param action  The name of the action.
 * @param enabled The enabled state.
 */
void purple_pounce_action_set_enabled(PurplePounce *pounce, const char *action,
									gboolean enabled);

/**
 * Sets a value for an attribute in an action.
 *
 * If @a value is @c NULL, the value will be unset.
 *
 * @param pounce The buddy pounce.
 * @param action The action name.
 * @param attr   The attribute name.
 * @param value  The value.
 */
void purple_pounce_action_set_attribute(PurplePounce *pounce, const char *action,
									  const char *attr, const char *value);

/**
 * Sets the pounce-specific data.
 *
 * @param pounce The buddy pounce.
 * @param data   Data specific to the pounce.
 */
void purple_pounce_set_data(PurplePounce *pounce, void *data);

/**
 * Returns the events a pounce should watch for.
 *
 * @param pounce The buddy pounce.
 *
 * @return The events the pounce is watching for.
 */
PurplePounceEvent purple_pounce_get_events(const PurplePounce *pounce);

/**
 * Returns the options for a pounce.
 *
 * @param pounce The buddy pounce.
 *
 * @return The options for the pounce.
 */
PurplePounceOption purple_pounce_get_options(const PurplePounce *pounce);

/**
 * Returns the account that will do the pouncing.
 *
 * @param pounce The buddy pounce.
 *
 * @return The account that will pounce.
 */
PurpleAccount *purple_pounce_get_pouncer(const PurplePounce *pounce);

/**
 * Returns the buddy a pounce should pounce on.
 *
 * @param pounce The buddy pounce.
 *
 * @return The buddy to pounce on.
 */
const char *purple_pounce_get_pouncee(const PurplePounce *pounce);

/**
 * Returns whether or not the pounce should save after execution.
 *
 * @param pounce The buddy pounce.
 *
 * @return @c TRUE if the pounce should be saved after execution, or
 *         @c FALSE otherwise.
 */
gboolean purple_pounce_get_save(const PurplePounce *pounce);

/**
 * Returns whether or not an action is enabled.
 *
 * @param pounce The buddy pounce.
 * @param action The action name.
 *
 * @return @c TRUE if the action is enabled, or @c FALSE otherwise.
 */
gboolean purple_pounce_action_is_enabled(const PurplePounce *pounce,
									   const char *action);

/**
 * Returns the value for an attribute in an action.
 *
 * @param pounce The buddy pounce.
 * @param action The action name.
 * @param attr   The attribute name.
 *
 * @return The attribute value, if it exists, or @c NULL.
 */
const char *purple_pounce_action_get_attribute(const PurplePounce *pounce,
											 const char *action,
											 const char *attr);

/**
 * Returns the pounce-specific data.
 *
 * @param pounce The buddy pounce.
 *
 * @return The data specific to a buddy pounce.
 */
void *purple_pounce_get_data(const PurplePounce *pounce);

/**
 * Executes a pounce with the specified pouncer, pouncee, and event type.
 *
 * @param pouncer The account that will do the pouncing.
 * @param pouncee The buddy that is being pounced.
 * @param events  The events that triggered the pounce.
 */
void purple_pounce_execute(const PurpleAccount *pouncer, const char *pouncee,
						 PurplePounceEvent events);

/*@}*/

/**************************************************************************/
/** @name Buddy Pounce Subsystem API                                      */
/**************************************************************************/
/*@{*/

/**
 * Finds a pounce with the specified event(s) and buddy.
 *
 * @param pouncer The account to match against.
 * @param pouncee The buddy to match against.
 * @param events  The event(s) to match against.
 *
 * @return The pounce if found, or @c NULL otherwise.
 */
PurplePounce *purple_find_pounce(const PurpleAccount *pouncer,
							 const char *pouncee, PurplePounceEvent events);


/**
 * Loads the pounces.
 *
 * @return @c TRUE if the pounces could be loaded.
 */
gboolean purple_pounces_load(void);

/**
 * Registers a pounce handler for a UI.
 *
 * @param ui          The UI name.
 * @param cb          The callback function.
 * @param new_pounce  The function called when a pounce is created.
 * @param free_pounce The function called when a pounce is freed.
 */
void purple_pounces_register_handler(const char *ui, PurplePounceCb cb,
								   void (*new_pounce)(PurplePounce *pounce),
								   void (*free_pounce)(PurplePounce *pounce));

/**
 * Unregisters a pounce handle for a UI.
 *
 * @param ui The UI name.
 */
void purple_pounces_unregister_handler(const char *ui);

/**
 * Returns a list of all registered buddy pounces.
 *
 * @constreturn The list of buddy pounces.
 */
GList *purple_pounces_get_all(void);

/**
 * Returns a list of registered buddy pounces for the ui-type.
 *
 * @param ui  The ID of the UI using the core.
 *
 * @return The list of buddy pounces. The list should be freed by
 *         the caller when it's no longer used.
 * @since  2.1.0
 */
GList *purple_pounces_get_all_for_ui(const char *ui);

/**
 * Returns the buddy pounce subsystem handle.
 *
 * @return The subsystem handle.
 */
void *purple_pounces_get_handle(void);

/**
 * Initializes the pounces subsystem.
 */
void purple_pounces_init(void);

/**
 * Uninitializes the pounces subsystem.
 */
void purple_pounces_uninit(void);

/*@}*/

#ifdef __cplusplus
}
#endif
