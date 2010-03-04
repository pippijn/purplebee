MODULE = PurpleBee      PACKAGE = PurpleBee::Request                    PREFIX = purple_request_


void*
purple_request_input (void* handle, char const* title, char const* primary, char const* secondary, char const* default_value, gboolean multiline, gboolean masked, gchar* hint, char const* ok_text, GCallback ok_cb, char const* cancel_text, GCallback cancel_cb, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data);

#void*
#purple_request_choice (void* handle, char const* title, char const* primary, char const* secondary, int default_value, char const* ok_text, GCallback ok_cb, char const* cancel_text, GCallback cancel_cb, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data, ...);

#void*
#purple_request_choice_varg (void* handle, char const* title, char const* primary, char const* secondary, int default_value, char const* ok_text, GCallback ok_cb, char const* cancel_text, GCallback cancel_cb, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data, va_list choices);

#void*
#purple_request_action (void* handle, char const* title, char const* primary, char const* secondary, int default_action, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data, size_t action_count, ...);

void*
purple_request_yes_no (void* handle, char const* title, char const* primary, char const* secondary, int default_action, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data, GCallback yes_cb, GCallback no_cb);

void*
purple_request_ok_cancel (void* handle, char const* title, char const* primary, char const* secondary, int default_action, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data, GCallback ok_cb, GCallback cancel_cb);

void*
purple_request_accept_cancel (void* handle, char const* title, char const* primary, char const* secondary, int default_action, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data, GCallback accept_cb, GCallback cancel_cb);

#void*
#purple_request_action_varg (void* handle, char const* title, char const* primary, char const* secondary, int default_action, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data, size_t action_count, va_list actions);

void*
purple_request_fields (void* handle, char const* title, char const* primary, char const* secondary, PurpleRequestFields* fields, char const* ok_text, GCallback ok_cb, char const* cancel_text, GCallback cancel_cb, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data);

void
purple_request_close (PurpleRequestType type, void* uihandle);

void
purple_request_close_with_handle (void* handle);

void*
purple_request_file (void* handle, char const* title, char const* filename, gboolean savedialog, GCallback ok_cb, GCallback cancel_cb, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data);

void*
purple_request_folder (void* handle, char const* title, char const* dirname, GCallback ok_cb, GCallback cancel_cb, PurpleAccount* account, char const* who, PurpleConversation* conv, void* user_data);

void
purple_request_set_ui_ops (PurpleRequestUiOps* ops);

PurpleRequestUiOps*
purple_request_get_ui_ops ();
