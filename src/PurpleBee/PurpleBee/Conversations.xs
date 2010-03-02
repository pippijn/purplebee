MODULE = PurpleBee      PACKAGE = PurpleBee::Conversations      PREFIX = purple_conversations_


void
purple_conversations_set_ui_ops (PurpleConversationUiOps* ops);

void*
purple_conversations_get_handle ();

void
purple_conversations_init ();

void
purple_conversations_uninit ();
