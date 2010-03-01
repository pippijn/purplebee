MODULE = PurpleBee      PACKAGE = PurpleBee::Buddy              PREFIX = purple_buddy_

PurpleBuddy*
purple_buddy_new (PurpleAccount* account, const char* name, const char* alias);

void
purple_buddy_destroy (PurpleBuddy* buddy);

void
purple_buddy_set_icon (PurpleBuddy* buddy, PurpleBuddyIcon* icon);

PurpleAccount*
purple_buddy_get_account (PurpleBuddy* buddy);

const char*
purple_buddy_get_name (PurpleBuddy* buddy);

PurpleBuddyIcon*
purple_buddy_get_icon (PurpleBuddy* buddy);

gpointer
purple_buddy_get_protocol_data (PurpleBuddy* buddy);

void
purple_buddy_set_protocol_data (PurpleBuddy* buddy, gpointer data);

PurpleContact*
purple_buddy_get_contact (PurpleBuddy* buddy);

PurplePresence*
purple_buddy_get_presence (PurpleBuddy* buddy);

const char*
purple_buddy_get_alias_only (PurpleBuddy* buddy);

const char*
purple_buddy_get_server_alias (PurpleBuddy* buddy);

const char*
purple_buddy_get_contact_alias (PurpleBuddy* buddy);

const char*
purple_buddy_get_alias (PurpleBuddy* buddy);

const char*
purple_buddy_get_local_buddy_alias (PurpleBuddy* buddy);

PurpleGroup*
purple_buddy_get_group (PurpleBuddy* buddy);
