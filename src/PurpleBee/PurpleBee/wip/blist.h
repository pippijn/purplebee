purple_set_blist (PurpleBuddyList* blist) -> void;
purple_get_blist () -> PurpleBuddyList*;
purple_find_buddy (PurpleAccount* account, char const* name) -> PurpleBuddy*;
purple_find_buddy_in_group (PurpleAccount* account, char const* name, PurpleGroup* group) -> PurpleBuddy*;
purple_find_buddies (PurpleAccount* account, char const* name) -> GSList*;
purple_find_group (char const* name) -> PurpleGroup*;
