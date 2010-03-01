MODULE = PurpleBee      PACKAGE = PurpleBee::BuddyIcons         PREFIX = purple_buddy_icons_


void
purple_buddy_icons_set_for_user (PurpleAccount* account, const char* username, void* icon_data, size_t icon_len, const char* checksum);

const char*
purple_buddy_icons_get_checksum_for_user (PurpleBuddy* buddy);

PurpleBuddyIcon*
purple_buddy_icons_find (PurpleAccount* account, const char* username);

PurpleStoredImage*
purple_buddy_icons_find_account_icon (PurpleAccount* account);

PurpleStoredImage*
purple_buddy_icons_set_account_icon (PurpleAccount* account, guchar* icon_data, size_t icon_len);

time_t
purple_buddy_icons_get_account_icon_timestamp (PurpleAccount* account);

gboolean
purple_buddy_icons_node_has_custom_icon (PurpleBlistNode* node);

PurpleStoredImage*
purple_buddy_icons_node_find_custom_icon (PurpleBlistNode* node);

PurpleStoredImage*
purple_buddy_icons_node_set_custom_icon (PurpleBlistNode* node, guchar* icon_data, size_t icon_len);

PurpleStoredImage*
purple_buddy_icons_node_set_custom_icon_from_file (PurpleBlistNode* node, const gchar* filename);

gboolean
purple_buddy_icons_has_custom_icon (PurpleContact* contact);

PurpleStoredImage*
purple_buddy_icons_find_custom_icon (PurpleContact* contact);

void
purple_buddy_icons_set_caching (gboolean caching);

gboolean
purple_buddy_icons_is_caching ();

void
purple_buddy_icons_set_cache_dir (const char* cache_dir);

const char*
purple_buddy_icons_get_cache_dir ();

void*
purple_buddy_icons_get_handle ();
