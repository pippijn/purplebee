MODULE = PurpleBee      PACKAGE = PurpleBee::Buddy::Icon        PREFIX = purple_buddy_icon_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

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
purple_buddy_icon_get_data (PurpleBuddyIcon* icon, size_t& len);
    OUTPUT:
    len

char const*
purple_buddy_icon_get_extension (PurpleBuddyIcon* icon);

char*
purple_buddy_icon_get_full_path (PurpleBuddyIcon* icon);

void
purple_buddy_icon_get_scale_size (PurpleBuddyIconSpec* spec, int& width, int& height);
    OUTPUT:
    width
    height
