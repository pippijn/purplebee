#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name DNS query API                                                   */
/**************************************************************************/
/*@{*/

/**
 * Perform an asynchronous DNS query.
 *
 * @param hostname The hostname to resolve.
 * @param port     A port number which is stored in the struct sockaddr.
 * @param callback The callback function to call after resolving.
 * @param data     Extra data to pass to the callback function.
 *
 * @return NULL if there was an error, otherwise return a reference to
 *         a data structure that can be used to cancel the pending
 *         DNS query, if needed.
 */
PurpleDnsQueryData *purple_dnsquery_a(const char *hostname, int port, PurpleDnsQueryConnectFunction callback, gpointer data);

/**
 * Cancel a DNS query and destroy the associated data structure.
 *
 * @param query_data The DNS query to cancel.  This data structure
 *        is freed by this function.
 */
void purple_dnsquery_destroy(PurpleDnsQueryData *query_data);

/**
 * Sets the UI operations structure to be used when doing a DNS
 * resolve.  The UI operations need only be set if the UI wants to
 * handle the resolve itself; otherwise, leave it as NULL.
 *
 * @param ops The UI operations structure.
 */
void purple_dnsquery_set_ui_ops(PurpleDnsQueryUiOps *ops);

/**
 * Returns the UI operations structure to be used when doing a DNS
 * resolve.
 *
 * @return The UI operations structure.
 */
PurpleDnsQueryUiOps *purple_dnsquery_get_ui_ops(void);

/**
 * Get the host associated with a PurpleDnsQueryData
 *
 * @param query_data The DNS query
 * @return The host.
 */
char *purple_dnsquery_get_host(PurpleDnsQueryData *query_data);

/**
 * Get the port associated with a PurpleDnsQueryData
 *
 * @param query_data The DNS query
 * @return The port.
 */
unsigned short purple_dnsquery_get_port(PurpleDnsQueryData *query_data);

/**
 * Initializes the DNS query subsystem.
 */
void purple_dnsquery_init(void);

/**
 * Uninitializes the DNS query subsystem.
 */
void purple_dnsquery_uninit(void);

/*@}*/

#ifdef __cplusplus
}
#endif
