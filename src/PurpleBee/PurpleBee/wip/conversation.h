PurpleConversation*
purple_conversation_new (PurpleConversationType type, PurpleAccount* account, char const* name);

void
purple_conversation_destroy (PurpleConversation* conv);

void
purple_conversation_present (PurpleConversation* conv);

PurpleConversationType
purple_conversation_get_type (PurpleConversation* conv);

void
purple_conversation_set_ui_ops (PurpleConversation* conv, PurpleConversationUiOps* ops);

void
purple_conversations_set_ui_ops (PurpleConversationUiOps* ops);

PurpleConversationUiOps*
purple_conversation_get_ui_ops (PurpleConversation* conv);

void
purple_conversation_set_account (PurpleConversation* conv, PurpleAccount* account);

PurpleAccount*
purple_conversation_get_account (PurpleConversation* conv);

PurpleConnection*
purple_conversation_get_gc (PurpleConversation* conv);

void
purple_conversation_set_title (PurpleConversation* conv, char const* title);

char const*
purple_conversation_get_title (PurpleConversation* conv);

void
purple_conversation_autoset_title (PurpleConversation* conv);

void
purple_conversation_set_name (PurpleConversation* conv, char const* name);

char const*
purple_conversation_get_name (PurpleConversation* conv);

void
purple_conversation_set_logging (PurpleConversation* conv, gboolean log);

gboolean
purple_conversation_is_logging (PurpleConversation* conv);

void
purple_conversation_close_logs (PurpleConversation* conv);

PurpleConvIm*
purple_conversation_get_im_data (PurpleConversation* conv);

PurpleConvChat*
purple_conversation_get_chat_data (PurpleConversation* conv);

void
purple_conversation_set_data (PurpleConversation* conv, char const* key, gpointer data);

gpointer
purple_conversation_get_data (PurpleConversation* conv, char const* key);

GList*
purple_get_conversations ();

GList*
purple_get_ims ();

GList*
purple_get_chats ();

PurpleConversation*
purple_find_conversation_with_account (PurpleConversationType type, char const* name, PurpleAccount* account);

void
purple_conversation_write (PurpleConversation* conv, char const* who, char const* message, PurpleMessageFlags flags, time_t mtime);

void
purple_conversation_set_features (PurpleConversation* conv, PurpleConnectionFlags features);

PurpleConnectionFlags
purple_conversation_get_features (PurpleConversation* conv);

gboolean
purple_conversation_has_focus (PurpleConversation* conv);

void
purple_conversation_update (PurpleConversation* conv, PurpleConvUpdateType type);

void
purple_conversation_foreach (PurpleConversationFunction func);

GList*
purple_conversation_get_message_history (PurpleConversation* conv);

void
purple_conversation_clear_message_history (PurpleConversation* conv);

char const*
purple_conversation_message_get_sender (PurpleConvMessage* msg);

char const*
purple_conversation_message_get_message (PurpleConvMessage* msg);

PurpleMessageFlags
purple_conversation_message_get_flags (PurpleConvMessage* msg);

time_t
purple_conversation_message_get_timestamp (PurpleConvMessage* msg);

PurpleConversation*
purple_conv_im_get_conversation (PurpleConvIm* im);

void
purple_conv_im_set_icon (PurpleConvIm* im, PurpleBuddyIcon* icon);

PurpleBuddyIcon*
purple_conv_im_get_icon (PurpleConvIm* im);

void
purple_conv_im_set_typing_state (PurpleConvIm* im, PurpleTypingState state);

PurpleTypingState
purple_conv_im_get_typing_state (PurpleConvIm* im);

void
purple_conv_im_start_typing_timeout (PurpleConvIm* im, int timeout);

void
purple_conv_im_stop_typing_timeout (PurpleConvIm* im);

guint
purple_conv_im_get_typing_timeout (PurpleConvIm* im);

void
purple_conv_im_set_type_again (PurpleConvIm* im, unsigned int val);

time_t
purple_conv_im_get_type_again (PurpleConvIm* im);

void
purple_conv_im_start_send_typed_timeout (PurpleConvIm* im);

void
purple_conv_im_stop_send_typed_timeout (PurpleConvIm* im);

guint
purple_conv_im_get_send_typed_timeout (PurpleConvIm* im);

void
purple_conv_im_update_typing (PurpleConvIm* im);

void
purple_conv_im_write (PurpleConvIm* im, char const* who, char const* message, PurpleMessageFlags flags, time_t mtime);

gboolean
purple_conv_present_error (char const* who, PurpleAccount* account, char const* what);

void
purple_conv_im_send (PurpleConvIm* im, char const* message);

void
purple_conv_send_confirm (PurpleConversation* conv, char const* message);

void
purple_conv_im_send_with_flags (PurpleConvIm* im, char const* message, PurpleMessageFlags flags);

gboolean
purple_conv_custom_smiley_add (PurpleConversation* conv, char const* smile, char const* cksum_type, char const* chksum, gboolean remote);

void
purple_conv_custom_smiley_write (PurpleConversation* conv, char const* smile, guchar const* data, gsize size);

void
purple_conv_custom_smiley_close (PurpleConversation* conv, char const* smile);

PurpleConversation*
purple_conv_chat_get_conversation (PurpleConvChat* chat);

GList*
purple_conv_chat_set_users (PurpleConvChat* chat, GList* users);

GList*
purple_conv_chat_get_users (PurpleConvChat* chat);

void
purple_conv_chat_ignore (PurpleConvChat* chat, char const* name);

void
purple_conv_chat_unignore (PurpleConvChat* chat, char const* name);

GList*
purple_conv_chat_set_ignored (PurpleConvChat* chat, GList* ignored);

GList*
purple_conv_chat_get_ignored (PurpleConvChat* chat);

char const*
purple_conv_chat_get_ignored_user (PurpleConvChat* chat, char const* user);

gboolean
purple_conv_chat_is_user_ignored (PurpleConvChat* chat, char const* user);

void
purple_conv_chat_set_topic (PurpleConvChat* chat, char const* who, char const* topic);

char const*
purple_conv_chat_get_topic (PurpleConvChat* chat);

void
purple_conv_chat_set_id (PurpleConvChat* chat, int id);

int
purple_conv_chat_get_id (PurpleConvChat* chat);

void
purple_conv_chat_write (PurpleConvChat* chat, char const* who, char const* message, PurpleMessageFlags flags, time_t mtime);

void
purple_conv_chat_send (PurpleConvChat* chat, char const* message);

void
purple_conv_chat_send_with_flags (PurpleConvChat* chat, char const* message, PurpleMessageFlags flags);

void
purple_conv_chat_add_user (PurpleConvChat* chat, char const* user, char const* extra_msg, PurpleConvChatBuddyFlags flags, gboolean new_arrival);

void
purple_conv_chat_add_users (PurpleConvChat* chat, GList* users, GList* extra_msgs, GList* flags, gboolean new_arrivals);

void
purple_conv_chat_rename_user (PurpleConvChat* chat, char const* old_user, char const* new_user);

void
purple_conv_chat_remove_user (PurpleConvChat* chat, char const* user, char const* reason);

void
purple_conv_chat_remove_users (PurpleConvChat* chat, GList* users, char const* reason);

gboolean
purple_conv_chat_find_user (PurpleConvChat* chat, char const* user);

void
purple_conv_chat_user_set_flags (PurpleConvChat* chat, char const* user, PurpleConvChatBuddyFlags flags);

PurpleConvChatBuddyFlags
purple_conv_chat_user_get_flags (PurpleConvChat* chat, char const* user);

void
purple_conv_chat_clear_users (PurpleConvChat* chat);

void
purple_conv_chat_set_nick (PurpleConvChat* chat, char const* nick);

char const*
purple_conv_chat_get_nick (PurpleConvChat* chat);

PurpleConversation*
purple_find_chat (PurpleConnection* gc, int id);

void
purple_conv_chat_left (PurpleConvChat* chat);

void
purple_conv_chat_invite_user (PurpleConvChat* chat, char const* user, char const* message, gboolean confirm);

gboolean
purple_conv_chat_has_left (PurpleConvChat* chat);

PurpleConvChatBuddy*
purple_conv_chat_cb_new (char const* name, char const* alias, PurpleConvChatBuddyFlags flags);

PurpleConvChatBuddy*
purple_conv_chat_cb_find (PurpleConvChat* chat, char const* name);

char const*
purple_conv_chat_cb_get_name (PurpleConvChatBuddy* cb);

void
purple_conv_chat_cb_destroy (PurpleConvChatBuddy* cb);

GList*
purple_conversation_get_extended_menu (PurpleConversation* conv);

gboolean
purple_conversation_do_command (PurpleConversation* conv, gchar const* cmdline, gchar const* markup, gchar** error);

void*
purple_conversations_get_handle ();

void
purple_conversations_init ();

void
purple_conversations_uninit ();
