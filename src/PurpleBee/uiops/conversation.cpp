#include "uiops/conversation.h"

namespace uiops
{
  void
  conversation::create_conversation (PurpleConversation* conv)
  {
  }

  void
  conversation::destroy_conversation (PurpleConversation* conv)
  {
  }

  void
  conversation::write_chat (PurpleConversation* conv, const char* who, const char* message, PurpleMessageFlags flags, time_t mtime)
  {
  }

  void
  conversation::write_im (PurpleConversation* conv, const char* who, const char* message, PurpleMessageFlags flags, time_t mtime)
  {
  }

  void
  conversation::write_conv (PurpleConversation* conv, const char* name, const char* alias, const char* message, PurpleMessageFlags flags, time_t mtime)
  {
  }

  void
  conversation::chat_add_users (PurpleConversation* conv, GList* cbuddies, gboolean new_arrivals)
  {
  }

  void
  conversation::chat_rename_user (PurpleConversation* conv, const char* old_name, const char* new_name, const char* new_alias)
  {
  }

  void
  conversation::chat_remove_users (PurpleConversation* conv, GList* users)
  {
  }

  void
  conversation::chat_update_user (PurpleConversation* conv, const char* user)
  {
  }

  void
  conversation::present (PurpleConversation* conv)
  {
  }

  gboolean
  conversation::has_focus (PurpleConversation* conv)
  {
    return false;
  }

  gboolean
  conversation::custom_smiley_add (PurpleConversation* conv, const char* smile, gboolean remote)
  {
    return false;
  }

  void
  conversation::custom_smiley_write (PurpleConversation* conv, const char* smile, const guchar* data, gsize size)
  {
  }

  void
  conversation::custom_smiley_close (PurpleConversation* conv, const char* smile)
  {
  }

  void
  conversation::send_confirm (PurpleConversation* conv, const char* message)
  {
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
    };
  }
}
