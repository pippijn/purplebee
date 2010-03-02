MODULE = PurpleBee      PACKAGE = PurpleBee::Group                      PREFIX = purple_group_


PurpleGroup*
purple_group_new (char const* name);

void
purple_group_destroy (PurpleGroup* group);

GSList*
purple_group_get_accounts (PurpleGroup* g);

gboolean
purple_group_on_account (PurpleGroup* g, PurpleAccount* account);

char const*
purple_group_get_name (PurpleGroup* group);
