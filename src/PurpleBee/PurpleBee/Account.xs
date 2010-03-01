MODULE = PurpleBee      PACKAGE = PurpleBee::Account    PREFIX = purple_account_

PROTOTYPES: ENABLE

PurpleAccount*
purple_account_new (char* username, const char* protocol_id)

void
purple_account_set_username (PurpleAccount* account, const char* username)

void
purple_account_set_password (PurpleAccount* account, const char* password)

void
purple_account_set_alias (PurpleAccount* account, const char* alias)

void
purple_account_set_user_info (PurpleAccount* account, const char* user_info)

void
purple_account_set_buddy_icon_path (PurpleAccount* account, const char* path)

void
purple_account_set_protocol_id (PurpleAccount* account, const char* id)

gboolean
purple_account_is_connected (PurpleAccount* account)

gboolean
purple_account_is_connecting (PurpleAccount* account)

gboolean
purple_account_is_disconnected (PurpleAccount* account)

const char*
purple_account_get_username (PurpleAccount * account);

const char*
purple_account_get_password (PurpleAccount* account);

const char*
purple_account_get_alias (PurpleAccount* account);

const char*
purple_account_get_user_info (PurpleAccount* account);

const char*
purple_account_get_buddy_icon_path (PurpleAccount* account);

const char*
purple_account_get_protocol_id (PurpleAccount* account);

const char*
purple_account_get_protocol_name (PurpleAccount* account);

gboolean
purple_account_get_enabled (PurpleAccount* account, const char* ui);

void
purple_account_set_enabled (PurpleAccount* account, int val)
    CODE:
    purple_account_set_enabled (account, UI_ID, val);

void
purple_account_connect (PurpleAccount* account)

void
purple_account_disconnect (PurpleAccount* account)

void
purple_account_destroy (PurpleAccount* account)
