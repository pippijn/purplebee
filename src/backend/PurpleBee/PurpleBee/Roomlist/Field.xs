MODULE = PurpleBee      PACKAGE = PurpleBee::Roomlist::Field            PREFIX = purple_roomlist_field_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    ROOMLIST_FIELD_
  const_val (BOOL);
  const_val (INT);
  const_val (STRING);
#undef TYPE
}

PurpleRoomlistField*
purple_roomlist_field_new (PurpleRoomlistFieldType type, gchar const* label, gchar const* name, gboolean hidden);

PurpleRoomlistFieldType
purple_roomlist_field_get_type (PurpleRoomlistField* field);

char const*
purple_roomlist_field_get_label (PurpleRoomlistField* field);

gboolean
purple_roomlist_field_get_hidden (PurpleRoomlistField* field);
