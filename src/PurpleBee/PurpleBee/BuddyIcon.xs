MODULE = PurpleBee      PACKAGE = PurpleBee::BuddyIcon          PREFIX = purple_buddy_icon_


PurpleBuddyIcon*
purple_buddy_icon_new (PurpleAccount* account, const char* username, void* icon_data, size_t icon_len, const char* checksum);

PurpleBuddyIcon*
purple_buddy_icon_ref (PurpleBuddyIcon* icon);

PurpleBuddyIcon*
purple_buddy_icon_unref (PurpleBuddyIcon* icon);

void
purple_buddy_icon_update (PurpleBuddyIcon* icon);

void
purple_buddy_icon_set_data (PurpleBuddyIcon* icon, guchar* data, size_t len, const char* checksum);

PurpleAccount*
purple_buddy_icon_get_account (PurpleBuddyIcon* icon);

const char*
purple_buddy_icon_get_username (PurpleBuddyIcon* icon);

const char*
purple_buddy_icon_get_checksum (PurpleBuddyIcon* icon);

gconstpointer
purple_buddy_icon_get_data (PurpleBuddyIcon* icon, size_t* len);

const char*
purple_buddy_icon_get_extension (PurpleBuddyIcon* icon);

char*
purple_buddy_icon_get_full_path (PurpleBuddyIcon* icon);

void
purple_buddy_icon_get_scale_size (PurpleBuddyIconSpec* spec, int* width, int* height);
