MODULE = PurpleBee      PACKAGE = PurpleBee::Cmd                        PREFIX = purple_cmd_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    CMD_STATUS_
  const_val (OK);
  const_val (FAILED);
  const_val (NOT_FOUND);
  const_val (WRONG_ARGS);
  const_val (WRONG_PRPL);
  const_val (WRONG_TYPE);
#undef TYPE
#define TYPE    CMD_RET_
  const_val (OK);
  const_val (FAILED);
  const_val (CONTINUE);
#undef TYPE
#define TYPE    CMD_P_
  const_val (VERY_LOW);
  const_val (LOW);
  const_val (DEFAULT);
  const_val (PRPL);
  const_val (PLUGIN);
  const_val (ALIAS);
  const_val (HIGH);
  const_val (VERY_HIGH);
#undef TYPE
#define TYPE    CMD_FLAG_
  const_val (IM);
  const_val (CHAT);
  const_val (PRPL_ONLY);
  const_val (ALLOW_WRONG_ARGS);
#undef TYPE
}

PurpleCmdId
purple_cmd_register (gchar const* cmd, gchar const* args, PurpleCmdPriority p, PurpleCmdFlag f, gchar const* prpl_id, PurpleCmdFunc func, gchar const* helpstr, void* data);

void
purple_cmd_unregister (PurpleCmdId id);

PurpleCmdStatus
purple_cmd_do_command (PurpleConversation* conv, gchar const* cmdline, gchar const* markup, gchar*& errormsg = NO_INIT);
    OUTPUT:
    errormsg

GList*
purple_cmd_list (PurpleConversation* conv);

GList*
purple_cmd_help (PurpleConversation* conv, gchar const* cmd);
