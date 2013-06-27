MODULE = PurpleBee      PACKAGE = PurpleBee::Buddy              PREFIX = purple_buddy_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurpleBuddy*
purple_buddy_new (PurpleAccount* account, char const* name, char const* alias);

void
purple_buddy_destroy (PurpleBuddy* buddy);

void
purple_buddy_set_icon (PurpleBuddy* buddy, PurpleBuddyIcon* icon);

PurpleAccount*
purple_buddy_get_account (PurpleBuddy* buddy);

char const*
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

char const*
purple_buddy_get_alias_only (PurpleBuddy* buddy);

char const*
purple_buddy_get_server_alias (PurpleBuddy* buddy);

char const*
purple_buddy_get_contact_alias (PurpleBuddy* buddy);

char const*
purple_buddy_get_alias (PurpleBuddy* buddy);

char const*
purple_buddy_get_local_buddy_alias (PurpleBuddy* buddy);

PurpleGroup*
purple_buddy_get_group (PurpleBuddy* buddy);
