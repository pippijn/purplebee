#ifdef __cplusplus
extern "C" {
#endif

/**
 * Queries an SRV record.
 *
 * @param protocol Name of the protocol (e.g. "sip")
 * @param transport Name of the transport ("tcp" or "udp")
 * @param domain Domain name to query (e.g. "blubb.com")
 * @param cb A callback which will be called with the results
 * @param extradata Extra data to be passed to the callback
 */
PurpleSrvQueryData *purple_srv_resolve(const char *protocol, const char *transport, const char *domain, PurpleSrvCallback cb, gpointer extradata);

/**
 * Cancel an SRV DNS query.
 *
 * @param query_data The request to cancel.
 */
void purple_srv_cancel(PurpleSrvQueryData *query_data);

/**
 * Queries an TXT record.
 *
 * @param owner Name of the protocol (e.g. "_xmppconnect")
 * @param domain Domain name to query (e.g. "blubb.com")
 * @param cb A callback which will be called with the results
 * @param extradata Extra data to be passed to the callback
 *
 * @since 2.6.0
 */
PurpleSrvQueryData *purple_txt_resolve(const char *owner, const char *domain, PurpleTxtCallback cb, gpointer extradata);

/**
 * Cancel an TXT DNS query.
 *
 * @param query_data The request to cancel.
 * @since 2.6.0
 */
void purple_txt_cancel(PurpleSrvQueryData *query_data);

/**
 * Get the value of the current TXT record.
 *
 * @param response  The TXT response record
 * @returns The value of the current TXT record.
 * @since 2.6.0
 */
const gchar *purple_txt_response_get_content(PurpleTxtResponse *response);

/**
 * Destroy a TXT DNS response object.
 *
 * @param response The PurpleTxtResponse to destroy.
 * @since 2.6.0
 */
void purple_txt_response_destroy(PurpleTxtResponse *response);

#ifdef __cplusplus
}
#endif
