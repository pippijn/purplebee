PurpleCmdId purple_cmd_register (const gchar* cmd, const gchar* args, PurpleCmdPriority p, PurpleCmdFlag f, const gchar* prpl_id, PurpleCmdFunc func, const gchar* helpstr, void* data);
void purple_cmd_unregister (PurpleCmdId id);
PurpleCmdStatus purple_cmd_do_command (PurpleConversation* conv, const gchar* cmdline, const gchar* markup, gchar** errormsg);
GList* purple_cmd_list (PurpleConversation* conv);
GList* purple_cmd_help (PurpleConversation* conv, const gchar* cmd);
gpointer purple_cmds_get_handle (void);
void purple_cmds_init (void);
void purple_cmds_uninit (void);
