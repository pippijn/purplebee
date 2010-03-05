MODULE = PurpleBee      PACKAGE = PurpleBee::Cmd                        PREFIX = purple_cmd_


PurpleCmdId
purple_cmd_register (gchar const* cmd, gchar const* args, PurpleCmdPriority p, PurpleCmdFlag f, gchar const* prpl_id, PurpleCmdFunc func, gchar const* helpstr, void* data);

void
purple_cmd_unregister (PurpleCmdId id);

PurpleCmdStatus
purple_cmd_do_command (PurpleConversation* conv, gchar const* cmdline, gchar const* markup, gchar*& errormsg);
    OUTPUT:
    errormsg

GList*
purple_cmd_list (PurpleConversation* conv);

GList*
purple_cmd_help (PurpleConversation* conv, gchar const* cmd);
