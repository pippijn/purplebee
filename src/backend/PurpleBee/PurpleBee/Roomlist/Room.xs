MODULE = PurpleBee      PACKAGE = PurpleBee::Roomlist::Room             PREFIX = purple_roomlist_room_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    ROOMLIST_ROOMTYPE_
  const_val (CATEGORY);
  const_val (ROOM);
#undef TYPE
}

PurpleRoomlistRoom*
purple_roomlist_room_new (PurpleRoomlistRoomType type, gchar const* name, PurpleRoomlistRoom* parent);

void
purple_roomlist_room_add_field (PurpleRoomlist* list, PurpleRoomlistRoom* room, gconstpointer field);

void
purple_roomlist_room_join (PurpleRoomlist* list, PurpleRoomlistRoom* room);

PurpleRoomlistRoomType
purple_roomlist_room_get_type (PurpleRoomlistRoom* room);

char const*
purple_roomlist_room_get_name (PurpleRoomlistRoom* room);

PurpleRoomlistRoom*
purple_roomlist_room_get_parent (PurpleRoomlistRoom* room);

GList*
purple_roomlist_room_get_fields (PurpleRoomlistRoom* room);
