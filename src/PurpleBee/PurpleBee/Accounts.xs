MODULE = PurpleBee      PACKAGE = PurpleBee::Accounts           PREFIX = purple_accounts_


void
purple_accounts_add (PurpleAccount* account);

void
purple_accounts_remove (PurpleAccount* account);

void
purple_accounts_delete (PurpleAccount* account);

void
purple_accounts_reorder (PurpleAccount* account, gint new_index);

GList*
purple_accounts_get_all ();

GList*
purple_accounts_get_all_active ();

PurpleAccount*
purple_accounts_find (char const* name, char const* protocol);

void
purple_accounts_restore_current_statuses ();

void
purple_accounts_set_ui_ops (PurpleAccountUiOps* ops);

PurpleAccountUiOps*
purple_accounts_get_ui_ops ();

void*
purple_accounts_get_handle ();

void
purple_accounts_init ();

void
purple_accounts_uninit ();
