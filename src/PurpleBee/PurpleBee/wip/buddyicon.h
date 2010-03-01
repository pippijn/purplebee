PurpleBuddyIcon*
purple_buddy_icon_new (PurpleAccount* account, char const* username, void* icon_data, size_t icon_len, char const* checksum);

PurpleBuddyIcon*
purple_buddy_icon_ref (PurpleBuddyIcon* icon);

PurpleBuddyIcon*
purple_buddy_icon_unref (PurpleBuddyIcon* icon);

void
purple_buddy_icon_update (PurpleBuddyIcon* icon);

void
purple_buddy_icon_set_data (PurpleBuddyIcon* icon, guchar* data, size_t len, char const* checksum);

PurpleAccount*
purple_buddy_icon_get_account (PurpleBuddyIcon* icon);

char const*
purple_buddy_icon_get_username (PurpleBuddyIcon* icon);

char const*
purple_buddy_icon_get_checksum (PurpleBuddyIcon* icon);

gconstpointer
purple_buddy_icon_get_data (PurpleBuddyIcon* icon, size_t* len);

char const*
purple_buddy_icon_get_extension (PurpleBuddyIcon* icon);

char*
purple_buddy_icon_get_full_path (PurpleBuddyIcon* icon);

void
purple_buddy_icons_set_for_user (PurpleAccount* account, char const* username, void* icon_data, size_t icon_len, char const* checksum);

char const*
purple_buddy_icons_get_checksum_for_user (PurpleBuddy* buddy);

PurpleBuddyIcon*
purple_buddy_icons_find (PurpleAccount* account, char const* username);

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
purple_buddy_icons_node_set_custom_icon_from_file (PurpleBlistNode* node, gchar const* filename);

void
purple_buddy_icons_set_caching (gboolean caching);

gboolean
purple_buddy_icons_is_caching ();

void
purple_buddy_icons_set_cache_dir (char const* cache_dir);

char const*
purple_buddy_icons_get_cache_dir ();

void*
purple_buddy_icons_get_handle ();

void
purple_buddy_icons_init ();

void
purple_buddy_icons_uninit ();

void
purple_buddy_icon_get_scale_size (PurpleBuddyIconSpec* spec, int* width, int* height);
