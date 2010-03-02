MODULE = PurpleBee      PACKAGE = PurpleBee::Account            PREFIX = purple_account_


PurpleAccount*
purple_account_new (char const* username, char const* protocol_id);

void
purple_account_destroy (PurpleAccount* account);

void
purple_account_connect (PurpleAccount* account);

void
purple_account_set_register_callback (PurpleAccount* account, PurpleAccountRegistrationCb cb, void* user_data);

void
purple_account_register (PurpleAccount* account);

void
purple_account_unregister (PurpleAccount* account, PurpleAccountUnregistrationCb cb, void* user_data);

void
purple_account_disconnect (PurpleAccount* account);

void
purple_account_notify_added (PurpleAccount* account, char const* remote_user, char const* id, char const* alias, char const* message);

void
purple_account_request_add (PurpleAccount* account, char const* remote_user, char const* id, char const* alias, char const* message);

void*
purple_account_request_authorization (PurpleAccount* account, char const* remote_user, char const* id, char const* alias, char const* message, gboolean on_list, PurpleAccountRequestAuthorizationCb auth_cb, PurpleAccountRequestAuthorizationCb deny_cb, void* user_data);

void
purple_account_request_close_with_account (PurpleAccount* account);

void
purple_account_request_close (void* ui_handle);

void
purple_account_request_password (PurpleAccount* account, GCallback ok_cb, GCallback cancel_cb, void* user_data);

void
purple_account_request_change_password (PurpleAccount* account);

void
purple_account_request_change_user_info (PurpleAccount* account);

void
purple_account_set_username (PurpleAccount* account, char const* username);

void
purple_account_set_password (PurpleAccount* account, char const* password);

void
purple_account_set_alias (PurpleAccount* account, char const* alias);

void
purple_account_set_user_info (PurpleAccount* account, char const* user_info);

void
purple_account_set_buddy_icon_path (PurpleAccount* account, char const* path);

void
purple_account_set_protocol_id (PurpleAccount* account, char const* protocol_id);

void
purple_account_set_connection (PurpleAccount* account, PurpleConnection* gc);

void
purple_account_set_remember_password (PurpleAccount* account, gboolean value);

void
purple_account_set_check_mail (PurpleAccount* account, gboolean value);

void
purple_account_set_enabled (PurpleAccount* account, char const* ui, gboolean value);

void
purple_account_set_proxy_info (PurpleAccount* account, PurpleProxyInfo* info);

void
purple_account_set_status_types (PurpleAccount* account, GList* status_types);

void
purple_account_set_status (PurpleAccount* account, char const* status_id, gboolean active, ...);

void
purple_account_set_status_list (PurpleAccount* account, char const* status_id, gboolean active, GList* attrs);

void
purple_account_clear_settings (PurpleAccount* account);

void
purple_account_remove_setting (PurpleAccount* account, char const* setting);

void
purple_account_set_int (PurpleAccount* account, char const* name, int value);

void
purple_account_set_string (PurpleAccount* account, char const* name, char const* value);

void
purple_account_set_bool (PurpleAccount* account, char const* name, gboolean value);

void
purple_account_set_ui_int (PurpleAccount* account, char const* ui, char const* name, int value);

void
purple_account_set_ui_string (PurpleAccount* account, char const* ui, char const* name, char const* value);

void
purple_account_set_ui_bool (PurpleAccount* account, char const* ui, char const* name, gboolean value);

gboolean
purple_account_is_connected (PurpleAccount* account);

gboolean
purple_account_is_connecting (PurpleAccount* account);

gboolean
purple_account_is_disconnected (PurpleAccount* account);

char const*
purple_account_get_username (PurpleAccount* account);

char const*
purple_account_get_password (PurpleAccount* account);

char const*
purple_account_get_alias (PurpleAccount* account);

char const*
purple_account_get_user_info (PurpleAccount* account);

char const*
purple_account_get_buddy_icon_path (PurpleAccount* account);

char const*
purple_account_get_protocol_id (PurpleAccount* account);

char const*
purple_account_get_protocol_name (PurpleAccount* account);

PurpleConnection*
purple_account_get_connection (PurpleAccount* account);

gboolean
purple_account_get_remember_password (PurpleAccount* account);

gboolean
purple_account_get_check_mail (PurpleAccount* account);

gboolean
purple_account_get_enabled (PurpleAccount* account, char const* ui);

PurpleProxyInfo*
purple_account_get_proxy_info (PurpleAccount* account);

PurpleStatus*
purple_account_get_active_status (PurpleAccount* account);

PurpleStatus*
purple_account_get_status (PurpleAccount* account, char const* status_id);

PurpleStatusType*
purple_account_get_status_type (PurpleAccount* account, char const* id);

PurpleStatusType*
purple_account_get_status_type_with_primitive (PurpleAccount* account, PurpleStatusPrimitive primitive);

PurplePresence*
purple_account_get_presence (PurpleAccount* account);

gboolean
purple_account_is_status_active (PurpleAccount* account, char const* status_id);

GList*
purple_account_get_status_types (PurpleAccount* account);

int
purple_account_get_int (PurpleAccount* account, char const* name, int default_value);

char const*
purple_account_get_string (PurpleAccount* account, char const* name, char const* default_value);

gboolean
purple_account_get_bool (PurpleAccount* account, char const* name, gboolean default_value);

int
purple_account_get_ui_int (PurpleAccount* account, char const* ui, char const* name, int default_value);

char const*
purple_account_get_ui_string (PurpleAccount* account, char const* ui, char const* name, char const* default_value);

gboolean
purple_account_get_ui_bool (PurpleAccount* account, char const* ui, char const* name, gboolean default_value);

PurpleLog*
purple_account_get_log (PurpleAccount* account, gboolean create);

void
purple_account_destroy_log (PurpleAccount* account);

void
purple_account_add_buddy (PurpleAccount* account, PurpleBuddy* buddy);

void
purple_account_add_buddies (PurpleAccount* account, GList* buddies);

void
purple_account_remove_buddy (PurpleAccount* account, PurpleBuddy* buddy, PurpleGroup* group);

void
purple_account_remove_buddies (PurpleAccount* account, GList* buddies, GList* groups);

void
purple_account_remove_group (PurpleAccount* account, PurpleGroup* group);

void
purple_account_change_password (PurpleAccount* account, char const* orig_pw, char const* new_pw);

gboolean
purple_account_supports_offline_message (PurpleAccount* account, PurpleBuddy* buddy);

PurpleConnectionErrorInfo const*
purple_account_get_current_error (PurpleAccount* account);

void
purple_account_clear_current_error (PurpleAccount* account);
