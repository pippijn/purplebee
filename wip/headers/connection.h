#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Connection API                                                  */
/**************************************************************************/
/*@{*/

#if !(defined PURPLE_DISABLE_DEPRECATED) || (defined _PURPLE_CONNECTION_C_)
/**
 * This function should only be called by purple_account_connect()
 * in account.c.  If you're trying to sign on an account, use that
 * function instead.
 *
 * Creates a connection to the specified account and either connects
 * or attempts to register a new account.  If you are logging in,
 * the connection uses the current active status for this account.
 * So if you want to sign on as "away," for example, you need to
 * have called purple_account_set_status(account, "away").
 * (And this will call purple_account_connect() automatically).
 *
 * @param account  The account the connection should be connecting to.
 * @param regist   Whether we are registering a new account or just
 *                 trying to do a normal signon.
 * @param password The password to use.
 *
 * @deprecated As this is internal, we should make it private in 3.0.0.
 */
void purple_connection_new(PurpleAccount *account, gboolean regist,
									const char *password);
#endif

#if !(defined PURPLE_DISABLE_DEPRECATED) || (defined _PURPLE_CONNECTION_C_)
/**
 * This function should only be called by purple_account_unregister()
 * in account.c.
 *
 * Tries to unregister the account on the server. If the account is not
 * connected, also creates a new connection.
 *
 * @param account  The account to unregister
 * @param password The password to use.
 * @param cb Optional callback to be called when unregistration is complete
 * @param user_data user data to pass to the callback
 *
 * @deprecated As this is internal, we should make it private in 3.0.0.
 */
void purple_connection_new_unregister(PurpleAccount *account, const char *password, PurpleAccountUnregistrationCb cb, void *user_data);
#endif

#if !(defined PURPLE_DISABLE_DEPRECATED) || (defined _PURPLE_CONNECTION_C_)
/**
 * Disconnects and destroys a PurpleConnection.
 *
 * This function should only be called by purple_account_disconnect()
 * in account.c.  If you're trying to sign off an account, use that
 * function instead.
 *
 * @param gc The purple connection to destroy.
 *
 * @deprecated As this is internal, we should make it private in 3.0.0.
 */
void purple_connection_destroy(PurpleConnection *gc);
#endif

/**
 * Sets the connection state.  PRPLs should call this and pass in
 * the state #PURPLE_CONNECTED when the account is completely
 * signed on.  What does it mean to be completely signed on?  If
 * the core can call prpl->set_status, and it successfully changes
 * your status, then the account is online.
 *
 * @param gc    The connection.
 * @param state The connection state.
 */
void purple_connection_set_state(PurpleConnection *gc, PurpleConnectionState state);

/**
 * Sets the connection's account.
 *
 * @param gc      The connection.
 * @param account The account.
 */
void purple_connection_set_account(PurpleConnection *gc, PurpleAccount *account);

/**
 * Sets the connection's displayed name.
 *
 * @param gc   The connection.
 * @param name The displayed name.
 */
void purple_connection_set_display_name(PurpleConnection *gc, const char *name);

/**
 * Sets the protocol data for a connection.
 *
 * @param connection The PurpleConnection.
 * @param proto_data The protocol data to set for the connection.
 *
 * @since 2.6.0
 */
void purple_connection_set_protocol_data(PurpleConnection *connection, void *proto_data);

/**
 * Returns the connection state.
 *
 * @param gc The connection.
 *
 * @return The connection state.
 */
PurpleConnectionState purple_connection_get_state(const PurpleConnection *gc);

/**
 * Returns TRUE if the account is connected, otherwise returns FALSE.
 *
 * @return TRUE if the account is connected, otherwise returns FALSE.
 */
#define PURPLE_CONNECTION_IS_CONNECTED(gc) \
	(purple_connection_get_state(gc) == PURPLE_CONNECTED)

/**
 * Returns the connection's account.
 *
 * @param gc The connection.
 *
 * @return The connection's account.
 */
PurpleAccount *purple_connection_get_account(const PurpleConnection *gc);

/**
 * Returns the protocol plugin managing a connection.
 *
 * @param gc The connection.
 *
 * @return The protocol plugin.
 *
 * @since 2.4.0
 */
PurplePlugin * purple_connection_get_prpl(const PurpleConnection *gc);

/**
 * Returns the connection's password.
 *
 * @param gc The connection.
 *
 * @return The connection's password.
 */
const char *purple_connection_get_password(const PurpleConnection *gc);

/**
 * Returns the connection's displayed name.
 *
 * @param gc The connection.
 *
 * @return The connection's displayed name.
 */
const char *purple_connection_get_display_name(const PurpleConnection *gc);

/**
 * Gets the protocol data from a connection.
 *
 * @param connection The PurpleConnection.
 *
 * @return The protocol data for the connection.
 *
 * @since 2.6.0
 */
void *purple_connection_get_protocol_data(const PurpleConnection *connection);

/**
 * Updates the connection progress.
 *
 * @param gc    The connection.
 * @param text  Information on the current step.
 * @param step  The current step.
 * @param count The total number of steps.
 */
void purple_connection_update_progress(PurpleConnection *gc, const char *text,
									 size_t step, size_t count);

/**
 * Displays a connection-specific notice.
 *
 * @param gc   The connection.
 * @param text The notice text.
 */
void purple_connection_notice(PurpleConnection *gc, const char *text);

/**
 * Closes a connection with an error.
 *
 * @param gc     The connection.
 * @param reason The error text, which may not be @c NULL.
 * @deprecated in favour of #purple_connection_error_reason.  Calling
 *  @c purple_connection_error(gc, text) is equivalent to calling
 *  @c purple_connection_error_reason(gc, reason, text) where @c reason is
 *  #PURPLE_CONNECTION_ERROR_OTHER_ERROR if @c gc->wants_to_die is @c TRUE, and
 *  #PURPLE_CONNECTION_ERROR_NETWORK_ERROR if not.  (This is to keep
 *  auto-reconnection behaviour the same when using old prpls which don't use
 *  reasons yet.)
 */
void purple_connection_error(PurpleConnection *gc, const char *reason);

/**
 * Closes a connection with an error and a human-readable description of the
 * error.  It also sets @c gc->wants_to_die to the value of
 * #purple_connection_error_is_fatal(@a reason), mainly for
 * backwards-compatibility.
 *
 * @param gc          the connection which is closing.
 * @param reason      why the connection is closing.
 * @param description a non-@c NULL localized description of the error.
 *
 * @since 2.3.0
 */
void
purple_connection_error_reason (PurpleConnection *gc,
                                PurpleConnectionError reason,
                                const char *description);

/**
 * Closes a connection due to an SSL error; this is basically a shortcut to
 * turning the #PurpleSslErrorType into a #PurpleConnectionError and a
 * human-readable string and then calling purple_connection_error_reason().
 *
 * @since 2.3.0
 */
void
purple_connection_ssl_error (PurpleConnection *gc,
                             PurpleSslErrorType ssl_error);

/**
 * Reports whether a disconnection reason is fatal (in which case the account
 * should probably not be automatically reconnected) or transient (so
 * auto-reconnection is a good idea).
 * For instance, #PURPLE_CONNECTION_ERROR_NETWORK_ERROR is a temporary error,
 * which might be caused by losing the network connection, so <tt>
 * purple_connection_error_is_fatal (PURPLE_CONNECTION_ERROR_NETWORK_ERROR)</tt>
 * is @c FALSE.  On the other hand,
 * #PURPLE_CONNECTION_ERROR_AUTHENTICATION_FAILED probably indicates a
 * misconfiguration of the account which needs the user to go fix it up, so
 * <tt> purple_connection_error_is_fatal
 * (PURPLE_CONNECTION_ERROR_AUTHENTICATION_FAILED)</tt> is @c TRUE.
 *
 * (This function is meant to replace checking PurpleConnection.wants_to_die.)
 *
 * @return @c TRUE if the account should not be automatically reconnected, and
 *         @c FALSE otherwise.
 *
 * @since 2.3.0
 */
gboolean
purple_connection_error_is_fatal (PurpleConnectionError reason);

/*@}*/

/**************************************************************************/
/** @name Connections API                                                 */
/**************************************************************************/
/*@{*/

/**
 * Disconnects from all connections.
 */
void purple_connections_disconnect_all(void);

/**
 * Returns a list of all active connections.  This does not
 * include connections that are in the process of connecting.
 *
 * @constreturn A list of all active connections.
 */
GList *purple_connections_get_all(void);

/**
 * Returns a list of all connections in the process of connecting.
 *
 * @constreturn A list of connecting connections.
 */
GList *purple_connections_get_connecting(void);

/**
 * Checks if gc is still a valid pointer to a gc.
 *
 * @return @c TRUE if gc is valid.
 *
 * @deprecated Do not use this.  Instead, cancel your asynchronous request
 *             when the PurpleConnection is destroyed.
 */
/*
 * TODO: Eventually this bad boy will be removed, because it is
 *       a gross fix for a crashy problem.
 */
#define PURPLE_CONNECTION_IS_VALID(gc) (g_list_find(purple_connections_get_all(), (gc)) != NULL)

/*@}*/

/**************************************************************************/
/** @name UI Registration Functions                                       */
/**************************************************************************/
/*@{*/

/**
 * Sets the UI operations structure to be used for connections.
 *
 * @param ops The UI operations structure.
 */
void purple_connections_set_ui_ops(PurpleConnectionUiOps *ops);

/**
 * Returns the UI operations structure used for connections.
 *
 * @return The UI operations structure in use.
 */
PurpleConnectionUiOps *purple_connections_get_ui_ops(void);

/*@}*/

/**************************************************************************/
/** @name Connections Subsystem                                           */
/**************************************************************************/
/*@{*/

/**
 * Initializes the connections subsystem.
 */
void purple_connections_init(void);

/**
 * Uninitializes the connections subsystem.
 */
void purple_connections_uninit(void);

/**
 * Returns the handle to the connections subsystem.
 *
 * @return The connections subsystem handle.
 */
void *purple_connections_get_handle(void);

/*@}*/


#ifdef __cplusplus
}
#endif
