#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name SSL API                                                         */
/**************************************************************************/
/*@{*/

/**
 * Returns whether or not SSL is currently supported.
 *
 * @return @a TRUE if SSL is supported, or @a FALSE otherwise.
 */
gboolean purple_ssl_is_supported(void);

/**
 * Returns a human-readable string for an SSL error.
 *
 * @param error      Error code
 * @return Human-readable error explanation
 */
const gchar * purple_ssl_strerror(PurpleSslErrorType error);

/**
 * Makes a SSL connection to the specified host and port.  The caller
 * should keep track of the returned value and use it to cancel the
 * connection, if needed.
 *
 * @param account    The account making the connection.
 * @param host       The destination host.
 * @param port       The destination port.
 * @param func       The SSL input handler function.
 * @param error_func The SSL error handler function.  This function
 *                   should <strong>NOT</strong> call purple_ssl_close().  In
 *                   the event of an error the #PurpleSslConnection will be
 *                   destroyed for you.
 * @param data       User-defined data.
 *
 * @return The SSL connection handle.
 */
PurpleSslConnection *purple_ssl_connect(PurpleAccount *account, const char *host,
									int port, PurpleSslInputFunction func,
									PurpleSslErrorFunction error_func,
									void *data);

/**
 * Makes a SSL connection to the specified host and port, using the separate
 * name to verify with the certificate.  The caller should keep track of the
 * returned value and use it to cancel the connection, if needed.
 *
 * @param account    The account making the connection.
 * @param host       The destination host.
 * @param port       The destination port.
 * @param func       The SSL input handler function.
 * @param error_func The SSL error handler function.  This function
 *                   should <strong>NOT</strong> call purple_ssl_close().  In
 *                   the event of an error the #PurpleSslConnection will be
 *                   destroyed for you.
 * @param ssl_host   The hostname of the other peer (to verify the CN)
 * @param data       User-defined data.
 *
 * @return The SSL connection handle.
 * @since 2.6.0
 */
PurpleSslConnection *purple_ssl_connect_with_ssl_cn(PurpleAccount *account, const char *host,
									int port, PurpleSslInputFunction func,
									PurpleSslErrorFunction error_func,
									const char *ssl_host,
									void *data);

#if !(defined PURPLE_DISABLE_DEPRECATED) || (defined _PURPLE_SSLCONN_C_)
/**
 * Makes a SSL connection using an already open file descriptor.
 *
 * @deprecated Use purple_ssl_connect_with_host_fd() instead.
 *
 * @param account    The account making the connection.
 * @param fd         The file descriptor.
 * @param func       The SSL input handler function.
 * @param error_func The SSL error handler function.
 * @param data       User-defined data.
 *
 * @return The SSL connection handle.
 */
PurpleSslConnection *purple_ssl_connect_fd(PurpleAccount *account, int fd,
									   PurpleSslInputFunction func,
									   PurpleSslErrorFunction error_func,
 									   void *data);
#endif

/**
 * Makes a SSL connection using an already open file descriptor.
 *
 * @param account    The account making the connection.
 * @param fd         The file descriptor.
 * @param func       The SSL input handler function.
 * @param error_func The SSL error handler function.
 * @param host       The hostname of the other peer (to verify the CN)
 * @param data       User-defined data.
 *
 * @return The SSL connection handle.
 *
 * @since 2.2.0
 */
PurpleSslConnection *purple_ssl_connect_with_host_fd(PurpleAccount *account, int fd,
                                           PurpleSslInputFunction func,
                                           PurpleSslErrorFunction error_func,
                                           const char *host,
                                           void *data);

/**
 * Adds an input watcher for the specified SSL connection.
 * Once the SSL handshake is complete, use this to watch for actual data across it.
 *
 * @param gsc   The SSL connection handle.
 * @param func  The callback function.
 * @param data  User-defined data.
 */
void purple_ssl_input_add(PurpleSslConnection *gsc, PurpleSslInputFunction func,
						void *data);

/**
 * Closes a SSL connection.
 *
 * @param gsc The SSL connection to close.
 */
void purple_ssl_close(PurpleSslConnection *gsc);

/**
 * Reads data from an SSL connection.
 *
 * @param gsc    The SSL connection handle.
 * @param buffer The destination buffer.
 * @param len    The maximum number of bytes to read.
 *
 * @return The number of bytes read.
 */
size_t purple_ssl_read(PurpleSslConnection *gsc, void *buffer, size_t len);

/**
 * Writes data to an SSL connection.
 *
 * @param gsc    The SSL connection handle.
 * @param buffer The buffer to write.
 * @param len    The length of the data to write.
 *
 * @return The number of bytes written.
 */
size_t purple_ssl_write(PurpleSslConnection *gsc, const void *buffer, size_t len);

/**
 * Obtains the peer's presented certificates
 *
 * @param gsc    The SSL connection handle
 *
 * @return The peer certificate chain, in the order of certificate, issuer,
 *         issuer's issuer, etc. @a NULL if no certificates have been provided,
 *
 * @since 2.2.0
 */
GList * purple_ssl_get_peer_certificates(PurpleSslConnection *gsc);

/*@}*/

/**************************************************************************/
/** @name Subsystem API                                                   */
/**************************************************************************/
/*@{*/

/**
 * Sets the current SSL operations structure.
 *
 * @param ops The SSL operations structure to assign.
 */
void purple_ssl_set_ops(PurpleSslOps *ops);

/**
 * Returns the current SSL operations structure.
 *
 * @return The SSL operations structure.
 */
PurpleSslOps *purple_ssl_get_ops(void);

/**
 * Initializes the SSL subsystem.
 */
void purple_ssl_init(void);

/**
 * Uninitializes the SSL subsystem.
 */
void purple_ssl_uninit(void);

/*@}*/

#ifdef __cplusplus
}
#endif
