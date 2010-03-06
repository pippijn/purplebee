/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "PurpleBee.h"
#include "perl/call.tcc"
#include "uiops/conversation.h"

#define OPS "UiOps::Conversation::"

namespace uiops
{
  void
  conversation::create_conversation (PurpleConversation* conv)
  {
    return perl_call<void> (OPS "create_conversation", conv);
  }

  void
  conversation::destroy_conversation (PurpleConversation* conv)
  {
    return perl_call<void> (OPS "destroy_conversation", conv);
  }

  void
  conversation::write_chat (PurpleConversation* conv, const char* who, const char* message, PurpleMessageFlags flags, time_t mtime)
  {
    return perl_call<void> (OPS "write_chat", conv, who, message, flags, mtime);
  }

  void
  conversation::write_im (PurpleConversation* conv, const char* who, const char* message, PurpleMessageFlags flags, time_t mtime)
  {
    return perl_call<void> (OPS "write_im", conv, who, message, flags, mtime);
  }

  void
  conversation::write_conv (PurpleConversation* conv, const char* name, const char* alias, const char* message, PurpleMessageFlags flags, time_t mtime)
  {
    return perl_call<void> (OPS "write_conv", conv, name, alias, message, flags, mtime);
  }

  void
  conversation::chat_add_users (PurpleConversation* conv, GList* cbuddies, gboolean new_arrivals)
  {
    return perl_call<void> (OPS "chat_add_users", conv, cbuddies, new_arrivals);
  }

  void
  conversation::chat_rename_user (PurpleConversation* conv, const char* old_name, const char* new_name, const char* new_alias)
  {
    return perl_call<void> (OPS "chat_rename_user", conv, old_name, new_name, new_alias);
  }

  void
  conversation::chat_remove_users (PurpleConversation* conv, GList* users)
  {
    return perl_call<void> (OPS "chat_remove_users", conv, users);
  }

  void
  conversation::chat_update_user (PurpleConversation* conv, const char* user)
  {
    return perl_call<void> (OPS "chat_update_user", conv, user);
  }

  void
  conversation::present (PurpleConversation* conv)
  {
    return perl_call<void> (OPS "present", conv);
  }

  gboolean
  conversation::has_focus (PurpleConversation* conv)
  {
    return perl_call<gboolean> (OPS "has_focus", conv);
  }

  gboolean
  conversation::custom_smiley_add (PurpleConversation* conv, const char* smile, gboolean remote)
  {
    return perl_call<gboolean> (OPS "custom_smiley_add", conv, smile, remote);
  }

  void
  conversation::custom_smiley_write (PurpleConversation* conv, const char* smile, const guchar* data, gsize size)
  {
    return perl_call<void> (OPS "custom_smiley_write", conv, smile, data, size);
  }

  void
  conversation::custom_smiley_close (PurpleConversation* conv, const char* smile)
  {
    return perl_call<void> (OPS "custom_smiley_close", conv, smile);
  }

  void
  conversation::send_confirm (PurpleConversation* conv, const char* message)
  {
    return perl_call<void> (OPS "send_confirm", conv, message);
  }

  PurpleConversationUiOps
  conversation::create ()
  {
    return {
      create_conversation,
      destroy_conversation,
      write_chat,
      write_im,
      write_conv,
      chat_add_users,
      chat_rename_user,
      chat_remove_users,
      chat_update_user,
      present,
      has_focus,
      custom_smiley_add,
      custom_smiley_write,
      custom_smiley_close,
      send_confirm,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }
}
