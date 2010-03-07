/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

namespace uiops
{
  struct conversation
  {
    static void create_conversation (PurpleConversation* conv);
    static void destroy_conversation (PurpleConversation* conv);
    static void write_chat (PurpleConversation* conv, const char* who, const char* message, PurpleMessageFlags flags, time_t mtime);
    static void write_im (PurpleConversation* conv, const char* who, const char* message, PurpleMessageFlags flags, time_t mtime);
    static void write_conv (PurpleConversation* conv, const char* name, const char* alias, const char* message, PurpleMessageFlags flags, time_t mtime);
    static void chat_add_users (PurpleConversation* conv, GList* cbuddies, gboolean new_arrivals);
    static void chat_rename_user (PurpleConversation* conv, const char* old_name, const char* new_name, const char* new_alias);
    static void chat_remove_users (PurpleConversation* conv, GList* users);
    static void chat_update_user (PurpleConversation* conv, const char* user);
    static void present (PurpleConversation* conv);
    static gboolean has_focus (PurpleConversation* conv);
    static gboolean custom_smiley_add (PurpleConversation* conv, const char* smile, gboolean remote);
    static void custom_smiley_write (PurpleConversation* conv, const char* smile, const guchar* data, gsize size);
    static void custom_smiley_close (PurpleConversation* conv, const char* smile);
    static void send_confirm (PurpleConversation* conv, const char* message);

    static PurpleConversationUiOps create ();
    static void destroy (PurpleConversationUiOps& ops);
  };
}
