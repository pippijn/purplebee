MODULE = PurpleBee      PACKAGE = PurpleBee::Cipher                     PREFIX = purple_cipher_


gchar const*
purple_cipher_get_name (PurpleCipher* cipher);

guint
purple_cipher_get_capabilities (PurpleCipher* cipher);

gboolean
purple_cipher_digest_region (gchar const* name, guchar const* data, size_t data_len, size_t in_len, guchar* digest, size_t& out_len);
    OUTPUT:
    out_len

void
purple_cipher_context_set_option (PurpleCipherContext* context, gchar const* name, gpointer value);

gpointer
purple_cipher_context_get_option (PurpleCipherContext* context, gchar const* name);

PurpleCipherContext*
purple_cipher_context_new (PurpleCipher* cipher, void* extra);

PurpleCipherContext*
purple_cipher_context_new_by_name (gchar const* name, void* extra);

void
purple_cipher_context_reset (PurpleCipherContext* context, gpointer extra);

void
purple_cipher_context_destroy (PurpleCipherContext* context);

void
purple_cipher_context_set_iv (PurpleCipherContext* context, guchar* iv, size_t len);

void
purple_cipher_context_append (PurpleCipherContext* context, guchar const* data, size_t len);

gboolean
purple_cipher_context_digest (PurpleCipherContext* context, size_t in_len, guchar* digest, size_t& out_len);
    OUTPUT:
    out_len

gboolean
purple_cipher_context_digest_to_str (PurpleCipherContext* context, size_t in_len, gchar* digest_s, size_t& out_len);
    OUTPUT:
    out_len

gint
purple_cipher_context_encrypt (PurpleCipherContext* context, guchar const* data, size_t len, guchar* output, size_t& outlen);
    OUTPUT:
    outlen

gint
purple_cipher_context_decrypt (PurpleCipherContext* context, guchar const* data, size_t len, guchar* output, size_t& outlen);
    OUTPUT:
    outlen

void
purple_cipher_context_set_salt (PurpleCipherContext* context, guchar* salt);

size_t
purple_cipher_context_get_salt_size (PurpleCipherContext* context);

void
purple_cipher_context_set_key (PurpleCipherContext* context, guchar const* key);

size_t
purple_cipher_context_get_key_size (PurpleCipherContext* context);

void
purple_cipher_context_set_batch_mode (PurpleCipherContext* context, PurpleCipherBatchMode mode);

PurpleCipherBatchMode
purple_cipher_context_get_batch_mode (PurpleCipherContext* context);

size_t
purple_cipher_context_get_block_size (PurpleCipherContext* context);

void
purple_cipher_context_set_key_with_len (PurpleCipherContext* context, guchar const* key, size_t len);

void
purple_cipher_context_set_data (PurpleCipherContext* context, gpointer data);

gpointer
purple_cipher_context_get_data (PurpleCipherContext* context);

gchar*
purple_cipher_http_digest_calculate_session_key (gchar const* algorithm, gchar const* username, gchar const* realm, gchar const* password, gchar const* nonce, gchar const* client_nonce);

gchar*
purple_cipher_http_digest_calculate_response (gchar const* algorithm, gchar const* method, gchar const* digest_uri, gchar const* qop, gchar const* entity, gchar const* nonce, gchar const* nonce_count, gchar const* client_nonce, gchar const* session_key);
