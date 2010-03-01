MODULE = PurpleBee      PACKAGE = PurpleBee::BuddyList          PREFIX = purple_blist_


PurpleBuddyList*
purple_blist_new ();

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
purple_blist_rename_buddy (PurpleBuddy* buddy, const char* name);

void
purple_blist_alias_contact (PurpleContact* contact, const char* alias);

void
purple_blist_alias_buddy (PurpleBuddy* buddy, const char* alias);

void
purple_blist_server_alias_buddy (PurpleBuddy* buddy, const char* alias);

void
purple_blist_alias_chat (PurpleChat* chat, const char* alias);

void
purple_blist_rename_group (PurpleGroup* group, const char* name);

void
purple_blist_add_chat (PurpleChat* chat, PurpleGroup* group, PurpleBlistNode* node);

void
purple_blist_add_buddy (PurpleBuddy* buddy, PurpleContact* contact, PurpleGroup* group, PurpleBlistNode* node);

void
purple_blist_add_group (PurpleGroup* group, PurpleBlistNode* node);

void
purple_blist_add_contact (PurpleContact* contact, PurpleGroup* group, PurpleBlistNode* node);

void
purple_blist_merge_contact (PurpleContact* source, PurpleBlistNode* node);

void
purple_blist_remove_buddy (PurpleBuddy* buddy);

void
purple_blist_remove_contact (PurpleContact* contact);

void
purple_blist_remove_chat (PurpleChat* chat);

void
purple_blist_remove_group (PurpleGroup* group);

PurpleChat*
purple_blist_find_chat (PurpleAccount* account, const char* name);

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
purple_blist_request_add_buddy (PurpleAccount* account, const char* username, const char* group, const char* alias);

void
purple_blist_request_add_chat (PurpleAccount* account, PurpleGroup* group, const char* alias, const char* name);

void
purple_blist_request_add_group ();

void
purple_blist_node_set_bool (PurpleBlistNode* node, const char* key, gboolean value);

gboolean
purple_blist_node_get_bool (PurpleBlistNode* node, const char* key);

void
purple_blist_node_set_int (PurpleBlistNode* node, const char* key, int value);

int
purple_blist_node_get_int (PurpleBlistNode* node, const char* key);

void
purple_blist_node_set_string (PurpleBlistNode* node, const char* key, const char* value);

const char*
purple_blist_node_get_string (PurpleBlistNode* node, const char* key);

void
purple_blist_node_remove_setting (PurpleBlistNode* node, const char* key);

void
purple_blist_node_set_flags (PurpleBlistNode* node, PurpleBlistNodeFlags flags);

PurpleBlistNodeFlags
purple_blist_node_get_flags (PurpleBlistNode* node);

PurpleBlistNodeType
purple_blist_node_get_type (PurpleBlistNode* node);

GList*
purple_blist_node_get_extended_menu (PurpleBlistNode* n);
