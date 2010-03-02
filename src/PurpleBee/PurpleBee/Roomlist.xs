MODULE = PurpleBee      PACKAGE = PurpleBee::Roomlist                   PREFIX = purple_roomlist_


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

void
purple_roomlist_set_ui_ops (PurpleRoomlistUiOps* ops);

PurpleRoomlistUiOps*
purple_roomlist_get_ui_ops ();
