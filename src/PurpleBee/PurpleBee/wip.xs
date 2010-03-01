

void purple_set_blist(PurpleBuddyList *blist);
PurpleBuddyList *purple_get_blist(void);
PurpleChat* purple_chat_new (PurpleAccount* account, const char* alias, GHashTable* components);
void purple_chat_destroy (PurpleChat* chat);
PurpleGroup* purple_group_new (const char* name);
void purple_group_destroy (PurpleGroup* group);
PurpleContact* purple_contact_new (void);
void purple_contact_destroy (PurpleContact* contact);
PurpleBuddy* purple_contact_get_priority_buddy (PurpleContact* contact);
const char* purple_contact_get_alias (PurpleContact* contact);
gboolean purple_contact_on_account (PurpleContact* contact, PurpleAccount* account);
void purple_contact_invalidate_priority_buddy (PurpleContact* contact);
const char* purple_chat_get_name (PurpleChat* chat);
PurpleBuddy* purple_find_buddy (PurpleAccount* account, const char* name);
PurpleBuddy* purple_find_buddy_in_group (PurpleAccount* account, const char* name, PurpleGroup* group);
GSList* purple_find_buddies (PurpleAccount* account, const char* name);
PurpleGroup* purple_find_group (const char* name);
PurpleGroup* purple_chat_get_group (PurpleChat* chat);
PurpleAccount* purple_chat_get_account (PurpleChat* chat);
GHashTable* purple_chat_get_components (PurpleChat* chat);
GSList* purple_group_get_accounts (PurpleGroup* g);
gboolean purple_group_on_account (PurpleGroup* g, PurpleAccount* account);
const char* purple_group_get_name (PurpleGroup* group);
