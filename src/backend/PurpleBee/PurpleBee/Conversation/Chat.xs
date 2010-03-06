MODULE = PurpleBee      PACKAGE = PurpleBee::Conversation::Chat         PREFIX = purple_conv_chat_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


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
