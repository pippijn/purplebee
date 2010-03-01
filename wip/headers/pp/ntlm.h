gchar* purple_ntlm_gen_type1 (const gchar* hostname, const gchar* domain);
guint8* purple_ntlm_parse_type2 (const gchar* type2, guint32* flags);
gchar* purple_ntlm_gen_type3 (const gchar* username, const gchar* passw, const gchar* hostname, const gchar* domain, const guint8* nonce, guint32* flags);
