MODULE = PurpleBee      PACKAGE = PurpleBee::Connection         PREFIX = purple_connection_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    CONNECTION_
  const_val (HTML);
  const_val (NO_BGCOLOR);
  const_val (AUTO_RESP);
  const_val (FORMATTING_WBFO);
  const_val (NO_NEWLINES);
  const_val (NO_FONTSIZE);
  const_val (NO_URLDESC);
  const_val (NO_IMAGES);
  const_val (ALLOW_CUSTOM_SMILEY);
#undef TYPE
#define TYPE
  const_val (DISCONNECTED);
  const_val (CONNECTED);
  const_val (CONNECTING);
#undef TYPE
#define TYPE    CONNECTION_ERROR_
  const_val (NETWORK_ERROR);
  const_val (INVALID_USERNAME);
  const_val (AUTHENTICATION_FAILED);
  const_val (AUTHENTICATION_IMPOSSIBLE);
  const_val (NO_SSL_SUPPORT);
  const_val (ENCRYPTION_ERROR);
  const_val (NAME_IN_USE);
  const_val (INVALID_SETTINGS);
  const_val (CERT_NOT_PROVIDED);
  const_val (CERT_UNTRUSTED);
  const_val (CERT_EXPIRED);
  const_val (CERT_NOT_ACTIVATED);
  const_val (CERT_HOSTNAME_MISMATCH);
  const_val (CERT_FINGERPRINT_MISMATCH);
  const_val (CERT_SELF_SIGNED);
  const_val (CERT_OTHER_ERROR);
  const_val (OTHER_ERROR);
#undef TYPE
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
