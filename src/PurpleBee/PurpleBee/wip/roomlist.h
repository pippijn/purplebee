void
purple_roomlist_show_with_account (PurpleAccount* account);

PurpleRoomlist*
purple_roomlist_new (PurpleAccount* account);

void
purple_roomlist_ref (PurpleRoomlist* list);

void
purple_roomlist_unref (PurpleRoomlist* list);

void
purple_roomlist_set_fields (PurpleRoomlist* list, GList* fields);

void
purple_roomlist_set_in_progress (PurpleRoomlist* list, gboolean in_progress);

gboolean
purple_roomlist_get_in_progress (PurpleRoomlist* list);

void
purple_roomlist_room_add (PurpleRoomlist* list, PurpleRoomlistRoom* room);

PurpleRoomlist*
purple_roomlist_get_list (PurpleConnection* gc);

void
purple_roomlist_cancel_get_list (PurpleRoomlist* list);

void
purple_roomlist_expand_category (PurpleRoomlist* list, PurpleRoomlistRoom* category);

GList*
purple_roomlist_get_fields (PurpleRoomlist* roomlist);

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

PurpleRoomlistField*
purple_roomlist_field_new (PurpleRoomlistFieldType type, gchar const* label, gchar const* name, gboolean hidden);

PurpleRoomlistFieldType
purple_roomlist_field_get_type (PurpleRoomlistField* field);

char const*
purple_roomlist_field_get_label (PurpleRoomlistField* field);

gboolean
purple_roomlist_field_get_hidden (PurpleRoomlistField* field);

void
purple_roomlist_set_ui_ops (PurpleRoomlistUiOps* ops);

PurpleRoomlistUiOps*
purple_roomlist_get_ui_ops ();
