MODULE = PurpleBee      PACKAGE = PurpleBee::Cmds                       PREFIX = purple_cmds_


PurpleContact*
purple_contact_new ();

void
purple_contact_destroy (PurpleContact* contact);

PurpleBuddy*
purple_contact_get_priority_buddy (PurpleContact* contact);

char const*
purple_contact_get_alias (PurpleContact* contact);

gboolean
purple_contact_on_account (PurpleContact* contact, PurpleAccount* account);

void
purple_contact_invalidate_priority_buddy (PurpleContact* contact);
