MODULE = PurpleBee      PACKAGE = PurpleBee::Conversation       PREFIX = purple_conversation_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    CONV_
  const_val (TYPE_UNKNOWN);
  const_val (TYPE_IM);
  const_val (TYPE_CHAT);
  const_val (TYPE_MISC);
  const_val (TYPE_ANY);

  const_val (UPDATE_ADD);
  const_val (UPDATE_REMOVE);
  const_val (UPDATE_ACCOUNT);
  const_val (UPDATE_TYPING);
  const_val (UPDATE_UNSEEN);
  const_val (UPDATE_LOGGING);
  const_val (UPDATE_TOPIC);
  const_val (ACCOUNT_ONLINE);
  const_val (ACCOUNT_OFFLINE);
  const_val (UPDATE_AWAY);
  const_val (UPDATE_ICON);
  const_val (UPDATE_TITLE);
  const_val (UPDATE_CHATLEFT);
  const_val (UPDATE_FEATURES);
#undef TYPE
#define TYPE
  const_val (NOT_TYPING);
  const_val (TYPING);
  const_val (TYPED);
#undef TYPE
#define TYPE    MESSAGE_
  const_val (SEND);
  const_val (RECV);
  const_val (SYSTEM);
  const_val (AUTO_RESP);
  const_val (ACTIVE_ONLY);
  const_val (NICK);
  const_val (NO_LOG);
  const_val (WHISPER);
  const_val (ERROR);
  const_val (DELAYED);
  const_val (RAW);
  const_val (IMAGES);
  const_val (NOTIFY);
  const_val (NO_LINKIFY);
  const_val (INVISIBLE);
#undef TYPE
#define TYPE    CBFLAGS_
  const_val (NONE);
  const_val (VOICE);
  const_val (HALFOP);
  const_val (OP);
  const_val (FOUNDER);
  const_val (TYPING);
#undef TYPE
}

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

GList*
purple_conversation_get_extended_menu (PurpleConversation* conv);

gboolean
purple_conversation_do_command (PurpleConversation* conv, gchar const* cmdline, gchar const* markup, gchar*& error);
    OUTPUT:
    error
