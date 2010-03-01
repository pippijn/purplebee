void purple_connection_set_state (PurpleConnection* gc, PurpleConnectionState state);
void purple_connection_set_account (PurpleConnection* gc, PurpleAccount* account);
void purple_connection_set_display_name (PurpleConnection* gc, const char* name);
void purple_connection_set_protocol_data (PurpleConnection* connection, void* proto_data);
PurpleConnectionState purple_connection_get_state (const PurpleConnection* gc);
PurpleAccount* purple_connection_get_account (const PurpleConnection* gc);
PurplePlugin* purple_connection_get_prpl (const PurpleConnection* gc);
const char* purple_connection_get_password (const PurpleConnection* gc);
const char* purple_connection_get_display_name (const PurpleConnection* gc);
void* purple_connection_get_protocol_data (const PurpleConnection* connection);
void purple_connection_update_progress (PurpleConnection* gc, const char* text, size_t step, size_t count);
void purple_connection_notice (PurpleConnection* gc, const char* text);
void purple_connection_error (PurpleConnection* gc, const char* reason);
void purple_connection_error_reason (PurpleConnection* gc, PurpleConnectionError reason, const char* description);
void purple_connection_ssl_error (PurpleConnection* gc, PurpleSslErrorType ssl_error);
gboolean purple_connection_error_is_fatal (PurpleConnectionError reason);
void purple_connections_disconnect_all(void);
GList *purple_connections_get_all(void);
GList *purple_connections_get_connecting(void);
