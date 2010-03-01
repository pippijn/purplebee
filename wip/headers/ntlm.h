#ifdef __cplusplus
extern "C" {
#endif

/**
 * Generates the base64 encoded type 1 message needed for NTLM authentication
 *
 * @param hostname Your hostname
 * @param domain The domain to authenticate to
 * @return base64 encoded string to send to the server.  This should
 *         be g_free'd by the caller.
 */
gchar *purple_ntlm_gen_type1(const gchar *hostname, const gchar *domain);

/**
 * Parses the ntlm type 2 message
 *
 * @param type2 String containing the base64 encoded type2 message
 * @param flags If not @c NULL, this will store the flags for the message
 *
 * @return The nonce for use in message type3.  This is a statically
 *         allocated 8 byte binary string.
 */
guint8 *purple_ntlm_parse_type2(const gchar *type2, guint32 *flags);

/**
 * Generates a type3 message
 *
 * @param username The username
 * @param passw The password
 * @param hostname The hostname
 * @param domain The domain to authenticate against
 * @param nonce The nonce returned by purple_ntlm_parse_type2
 * @param flags Pointer to the flags returned by purple_ntlm_parse_type2
 * @return A base64 encoded type3 message.  This should be g_free'd by
 *         the caller.
 */
gchar *purple_ntlm_gen_type3(const gchar *username, const gchar *passw, const gchar *hostname, const gchar *domain, const guint8 *nonce, guint32 *flags);

#ifdef __cplusplus
}
#endif
