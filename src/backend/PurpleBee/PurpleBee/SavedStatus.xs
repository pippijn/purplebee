MODULE = PurpleBee      PACKAGE = PurpleBee::SavedStatus                PREFIX = purple_savedstatus_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurpleSavedStatus*
purple_savedstatus_new (char const* title, PurpleStatusPrimitive type);

void
purple_savedstatus_set_title (PurpleSavedStatus* status, char const* title);

void
purple_savedstatus_set_type (PurpleSavedStatus* status, PurpleStatusPrimitive type);

void
purple_savedstatus_set_message (PurpleSavedStatus* status, char const* message);

void
purple_savedstatus_set_substatus (PurpleSavedStatus* status, PurpleAccount* account, PurpleStatusType* type, char const* message);

void
purple_savedstatus_unset_substatus (PurpleSavedStatus* saved_status, PurpleAccount* account);

gboolean
purple_savedstatus_delete (char const* title);

void
purple_savedstatus_delete_by_status (PurpleSavedStatus* saved_status);

PurpleSavedStatus*
purple_savedstatus_get_current ();

PurpleSavedStatus*
purple_savedstatus_get_default ();

PurpleSavedStatus*
purple_savedstatus_get_idleaway ();

gboolean
purple_savedstatus_is_idleaway ();

void
purple_savedstatus_set_idleaway (gboolean idleaway);

PurpleSavedStatus*
purple_savedstatus_get_startup ();

PurpleSavedStatus*
purple_savedstatus_find (char const* title);

PurpleSavedStatus*
purple_savedstatus_find_by_creation_time (time_t creation_time);

PurpleSavedStatus*
purple_savedstatus_find_transient_by_type_and_message (PurpleStatusPrimitive type, char const* message);

gboolean
purple_savedstatus_is_transient (PurpleSavedStatus* saved_status);

char const*
purple_savedstatus_get_title (PurpleSavedStatus* saved_status);

PurpleStatusPrimitive
purple_savedstatus_get_type (PurpleSavedStatus* saved_status);

char const*
purple_savedstatus_get_message (PurpleSavedStatus* saved_status);

time_t
purple_savedstatus_get_creation_time (PurpleSavedStatus* saved_status);

gboolean
purple_savedstatus_has_substatuses (PurpleSavedStatus* saved_status);

PurpleSavedStatusSub*
purple_savedstatus_get_substatus (PurpleSavedStatus* saved_status, PurpleAccount* account);

PurpleStatusType const*
purple_savedstatus_substatus_get_type (PurpleSavedStatusSub* substatus);

char const*
purple_savedstatus_substatus_get_message (PurpleSavedStatusSub* substatus);

void
purple_savedstatus_activate (PurpleSavedStatus* saved_status);

void
purple_savedstatus_activate_for_account (PurpleSavedStatus* saved_status, PurpleAccount* account);
