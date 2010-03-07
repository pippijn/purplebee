MODULE = PurpleBee      PACKAGE = PurpleBee::Status             PREFIX = purple_status_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurpleStatus*
purple_status_new (PurpleStatusType* status_type, PurplePresence* presence);

void
purple_status_destroy (PurpleStatus* status);

void
purple_status_set_active (PurpleStatus* status, gboolean active);

#void
#purple_status_set_active_with_attrs (PurpleStatus* status, gboolean active, va_list args);

void
purple_status_set_active_with_attrs_list (PurpleStatus* status, gboolean active, GList* attrs);

PurpleStatusType*
purple_status_get_type (PurpleStatus* status);

PurplePresence*
purple_status_get_presence (PurpleStatus* status);

char const*
purple_status_get_id (PurpleStatus* status);

char const*
purple_status_get_name (PurpleStatus* status);

gboolean
purple_status_is_independent (PurpleStatus* status);

gboolean
purple_status_is_exclusive (PurpleStatus* status);

gboolean
purple_status_is_available (PurpleStatus* status);

gboolean
purple_status_is_active (PurpleStatus* status);

gboolean
purple_status_is_online (PurpleStatus* status);

PurpleValue*
purple_status_get_attr_value (PurpleStatus* status, char const* id);

gboolean
purple_status_get_attr_boolean (PurpleStatus* status, char const* id);

int
purple_status_get_attr_int (PurpleStatus* status, char const* id);

char const*
purple_status_get_attr_string (PurpleStatus* status, char const* id);

gint
purple_status_compare (PurpleStatus* status1, PurpleStatus* status2);

void*
purple_status_get_handle ();

void
purple_status_init ();

void
purple_status_uninit ();
