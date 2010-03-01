PurpleBuddyList*
purple_blist_new ();

void
purple_set_blist (PurpleBuddyList* blist);

PurpleBuddyList*
purple_get_blist ();

PurpleBlistNode*
purple_blist_get_root ();

GSList*
purple_blist_get_buddies ();

gpointer
purple_blist_get_ui_data ();

void
purple_blist_set_ui_data (gpointer ui_data);

PurpleBlistNode*
purple_blist_node_next (PurpleBlistNode* node, gboolean offline);

PurpleBlistNode*
purple_blist_node_get_parent (PurpleBlistNode* node);

PurpleBlistNode*
purple_blist_node_get_first_child (PurpleBlistNode* node);

PurpleBlistNode*
purple_blist_node_get_sibling_next (PurpleBlistNode* node);

PurpleBlistNode*
purple_blist_node_get_sibling_prev (PurpleBlistNode* node);

gpointer
purple_blist_node_get_ui_data (PurpleBlistNode* node);

void
purple_blist_node_set_ui_data (PurpleBlistNode* node, gpointer ui_data);

void
purple_blist_show ();

void
purple_blist_destroy ();

void
purple_blist_set_visible (gboolean show);

void
purple_blist_update_buddy_status (PurpleBuddy* buddy, PurpleStatus* old_status);

void
purple_blist_update_node_icon (PurpleBlistNode* node);

void
purple_blist_rename_buddy (PurpleBuddy* buddy, char const* name);

void
purple_blist_alias_contact (PurpleContact* contact, char const* alias);

void
purple_blist_alias_buddy (PurpleBuddy* buddy, char const* alias);

void
purple_blist_server_alias_buddy (PurpleBuddy* buddy, char const* alias);

void
purple_blist_alias_chat (PurpleChat* chat, char const* alias);

void
purple_blist_rename_group (PurpleGroup* group, char const* name);

PurpleChat*
purple_chat_new (PurpleAccount* account, char const* alias, GHashTable* components);

void
purple_chat_destroy (PurpleChat* chat);

void
purple_blist_add_chat (PurpleChat* chat, PurpleGroup* group, PurpleBlistNode* node);

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

void
purple_blist_add_buddy (PurpleBuddy* buddy, PurpleContact* contact, PurpleGroup* group, PurpleBlistNode* node);

PurpleGroup*
purple_group_new (char const* name);

void
purple_group_destroy (PurpleGroup* group);

void
purple_blist_add_group (PurpleGroup* group, PurpleBlistNode* node);

PurpleContact*
purple_contact_new ();

void
purple_contact_destroy (PurpleContact* contact);

void
purple_blist_add_contact (PurpleContact* contact, PurpleGroup* group, PurpleBlistNode* node);

void
purple_blist_merge_contact (PurpleContact* source, PurpleBlistNode* node);

PurpleBuddy*
purple_contact_get_priority_buddy (PurpleContact* contact);

char const*
purple_contact_get_alias (PurpleContact* contact);

gboolean
purple_contact_on_account (PurpleContact* contact, PurpleAccount* account);

void
purple_contact_invalidate_priority_buddy (PurpleContact* contact);

void
purple_blist_remove_buddy (PurpleBuddy* buddy);

void
purple_blist_remove_contact (PurpleContact* contact);

void
purple_blist_remove_chat (PurpleChat* chat);

void
purple_blist_remove_group (PurpleGroup* group);

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

char const*
purple_chat_get_name (PurpleChat* chat);

PurpleBuddy*
purple_find_buddy (PurpleAccount* account, char const* name);

PurpleBuddy*
purple_find_buddy_in_group (PurpleAccount* account, char const* name, PurpleGroup* group);

GSList*
purple_find_buddies (PurpleAccount* account, char const* name);

PurpleGroup*
purple_find_group (char const* name);

PurpleChat*
purple_blist_find_chat (PurpleAccount* account, char const* name);

PurpleGroup*
purple_chat_get_group (PurpleChat* chat);

PurpleAccount*
purple_chat_get_account (PurpleChat* chat);

GHashTable*
purple_chat_get_components (PurpleChat* chat);

PurpleGroup*
purple_buddy_get_group (PurpleBuddy* buddy);

GSList*
purple_group_get_accounts (PurpleGroup* g);

gboolean
purple_group_on_account (PurpleGroup* g, PurpleAccount* account);

char const*
purple_group_get_name (PurpleGroup* group);

void
purple_blist_add_account (PurpleAccount* account);

void
purple_blist_remove_account (PurpleAccount* account);

int
purple_blist_get_group_size (PurpleGroup* group, gboolean offline);

int
purple_blist_get_group_online_count (PurpleGroup* group);

void
purple_blist_load ();

void
purple_blist_schedule_save ();

void
purple_blist_request_add_buddy (PurpleAccount* account, char const* username, char const* group, char const* alias);

void
purple_blist_request_add_chat (PurpleAccount* account, PurpleGroup* group, char const* alias, char const* name);

void
purple_blist_request_add_group ();

void
purple_blist_node_set_bool (PurpleBlistNode* node, char const* key, gboolean value);

gboolean
purple_blist_node_get_bool (PurpleBlistNode* node, char const* key);

void
purple_blist_node_set_int (PurpleBlistNode* node, char const* key, int value);

int
purple_blist_node_get_int (PurpleBlistNode* node, char const* key);

void
purple_blist_node_set_string (PurpleBlistNode* node, char const* key, char const* value);

char const*
purple_blist_node_get_string (PurpleBlistNode* node, char const* key);

void
purple_blist_node_remove_setting (PurpleBlistNode* node, char const* key);

void
purple_blist_node_set_flags (PurpleBlistNode* node, PurpleBlistNodeFlags flags);

PurpleBlistNodeFlags
purple_blist_node_get_flags (PurpleBlistNode* node);

PurpleBlistNodeType
purple_blist_node_get_type (PurpleBlistNode* node);

GList*
purple_blist_node_get_extended_menu (PurpleBlistNode* n);

void
purple_blist_set_ui_ops (PurpleBlistUiOps* ops);

PurpleBlistUiOps*
purple_blist_get_ui_ops ();

void*
purple_blist_get_handle ();

void
purple_blist_init ();

void
purple_blist_uninit ();
