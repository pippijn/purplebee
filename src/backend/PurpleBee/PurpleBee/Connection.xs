MODULE = PurpleBee      PACKAGE = PurpleBee::Connection         PREFIX = purple_connection_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

void
purple_connection_set_state (PurpleConnection* gc, PurpleConnectionState state);

void
purple_connection_set_account (PurpleConnection* gc, PurpleAccount* account);

void
purple_connection_set_display_name (PurpleConnection* gc, char const* name);

void
purple_connection_set_protocol_data (PurpleConnection* connection, void* proto_data);

PurpleConnectionState
purple_connection_get_state (PurpleConnection* gc);

PurpleAccount*
purple_connection_get_account (PurpleConnection* gc);

PurplePlugin*
purple_connection_get_prpl (PurpleConnection* gc);

char const*
purple_connection_get_password (PurpleConnection* gc);

char const*
purple_connection_get_display_name (PurpleConnection* gc);

void*
purple_connection_get_protocol_data (PurpleConnection* connection);

void
purple_connection_update_progress (PurpleConnection* gc, char const* text, size_t step, size_t count);

void
purple_connection_notice (PurpleConnection* gc, char const* text);

void
purple_connection_error (PurpleConnection* gc, char const* reason);

void
purple_connection_error_reason (PurpleConnection* gc, PurpleConnectionError reason, char const* description);

void
purple_connection_ssl_error (PurpleConnection* gc, PurpleSslErrorType ssl_error);

gboolean
purple_connection_error_is_fatal (PurpleConnectionError reason);

gboolean
PURPLE_CONNECTION_IS_CONNECTED (PurpleConnection* gc);

gboolean
PURPLE_CONNECTION_IS_VALID (PurpleConnection* gc);
