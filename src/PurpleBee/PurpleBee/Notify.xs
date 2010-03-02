MODULE = PurpleBee      PACKAGE = PurpleBee::Notify                     PREFIX = purple_notify_


void*
purple_notify_searchresults (PurpleConnection* gc, char const* title, char const* primary, char const* secondary, PurpleNotifySearchResults* results, PurpleNotifyCloseCallback cb, gpointer user_data);

void
purple_notify_searchresults_free (PurpleNotifySearchResults* results);

void
purple_notify_searchresults_new_rows (PurpleConnection* gc, PurpleNotifySearchResults* results, void* data);

void
purple_notify_searchresults_button_add (PurpleNotifySearchResults* results, PurpleNotifySearchButtonType type, PurpleNotifySearchResultsCallback cb);

void
purple_notify_searchresults_button_add_labeled (PurpleNotifySearchResults* results, char const* label, PurpleNotifySearchResultsCallback cb);

PurpleNotifySearchResults*
purple_notify_searchresults_new ();

PurpleNotifySearchColumn*
purple_notify_searchresults_column_new (char const* title);

void
purple_notify_searchresults_column_add (PurpleNotifySearchResults* results, PurpleNotifySearchColumn* column);

void
purple_notify_searchresults_row_add (PurpleNotifySearchResults* results, GList* row);

void*
purple_notify_message (void* handle, PurpleNotifyMsgType type, char const* title, char const* primary, char const* secondary, PurpleNotifyCloseCallback cb, gpointer user_data);

void*
purple_notify_info (void* handle, char const* title, char const* primary, char const* secondary);

void*
purple_notify_warning (void* handle, char const* title, char const* primary, char const* secondary);

void*
purple_notify_error (void* handle, char const* title, char const* primary, char const* secondary);

void*
purple_notify_email (void* handle, char const* subject, char const* from, char const* to, char const* url, PurpleNotifyCloseCallback cb, gpointer user_data);

void*
purple_notify_emails (void* handle, size_t count, gboolean detailed, char const** subjects, char const** froms, char const** tos, char const** urls, PurpleNotifyCloseCallback cb, gpointer user_data);

void*
purple_notify_formatted (void* handle, char const* title, char const* primary, char const* secondary, char const* text, PurpleNotifyCloseCallback cb, gpointer user_data);

void*
purple_notify_userinfo (PurpleConnection* gc, char const* who, PurpleNotifyUserInfo* user_info, PurpleNotifyCloseCallback cb, gpointer user_data);

PurpleNotifyUserInfo*
purple_notify_user_info_new ();

void
purple_notify_user_info_destroy (PurpleNotifyUserInfo* user_info);

GList*
purple_notify_user_info_get_entries (PurpleNotifyUserInfo* user_info);

char*
purple_notify_user_info_get_text_with_newline (PurpleNotifyUserInfo* user_info, char const* newline);

void
purple_notify_user_info_add_pair (PurpleNotifyUserInfo* user_info, char const* label, char const* value);

void
purple_notify_user_info_prepend_pair (PurpleNotifyUserInfo* user_info, char const* label, char const* value);

PurpleNotifyUserInfoEntry*
purple_notify_user_info_entry_new (char const* label, char const* value);

void
purple_notify_user_info_add_section_break (PurpleNotifyUserInfo* user_info);

void
purple_notify_user_info_prepend_section_break (PurpleNotifyUserInfo* user_info);

void
purple_notify_user_info_add_section_header (PurpleNotifyUserInfo* user_info, char const* label);

void
purple_notify_user_info_prepend_section_header (PurpleNotifyUserInfo* user_info, char const* label);

void
purple_notify_user_info_remove_last_item (PurpleNotifyUserInfo* user_info);

gchar const*
purple_notify_user_info_entry_get_label (PurpleNotifyUserInfoEntry* user_info_entry);

void
purple_notify_user_info_entry_set_label (PurpleNotifyUserInfoEntry* user_info_entry, char const* label);

gchar const*
purple_notify_user_info_entry_get_value (PurpleNotifyUserInfoEntry* user_info_entry);

void
purple_notify_user_info_entry_set_value (PurpleNotifyUserInfoEntry* user_info_entry, char const* value);

PurpleNotifyUserInfoEntryType
purple_notify_user_info_entry_get_type (PurpleNotifyUserInfoEntry* user_info_entry);

void
purple_notify_user_info_entry_set_type (PurpleNotifyUserInfoEntry* user_info_entry, PurpleNotifyUserInfoEntryType type);

void*
purple_notify_uri (void* handle, char const* uri);

void
purple_notify_close (PurpleNotifyType type, void* ui_handle);

void
purple_notify_close_with_handle (void* handle);

void
purple_notify_set_ui_ops (PurpleNotifyUiOps* ops);

PurpleNotifyUiOps*
purple_notify_get_ui_ops ();

void*
purple_notify_get_handle ();

void
purple_notify_init ();

void
purple_notify_uninit ();
