MODULE = PurpleBee      PACKAGE = PurpleBee::Prefs                      PREFIX = purple_prefs_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


void*
purple_prefs_get_handle ();

void
purple_prefs_init ();

void
purple_prefs_uninit ();

void
purple_prefs_add_none (char const* name);

void
purple_prefs_add_bool (char const* name, gboolean value);

void
purple_prefs_add_int (char const* name, int value);

void
purple_prefs_add_string (char const* name, char const* value);

void
purple_prefs_add_string_list (char const* name, GList* value);

void
purple_prefs_add_path (char const* name, char const* value);

void
purple_prefs_add_path_list (char const* name, GList* value);

void
purple_prefs_remove (char const* name);

void
purple_prefs_rename (char const* oldname, char const* newname);

void
purple_prefs_rename_boolean_toggle (char const* oldname, char const* newname);

void
purple_prefs_destroy ();

void
purple_prefs_set_generic (char const* name, gpointer value);

void
purple_prefs_set_bool (char const* name, gboolean value);

void
purple_prefs_set_int (char const* name, int value);

void
purple_prefs_set_string (char const* name, char const* value);

void
purple_prefs_set_string_list (char const* name, GList* value);

void
purple_prefs_set_path (char const* name, char const* value);

void
purple_prefs_set_path_list (char const* name, GList* value);

gboolean
purple_prefs_exists (char const* name);

PurplePrefType
purple_prefs_get_type (char const* name);

gboolean
purple_prefs_get_bool (char const* name);

int
purple_prefs_get_int (char const* name);

char const*
purple_prefs_get_string (char const* name);

GList*
purple_prefs_get_string_list (char const* name);

char const*
purple_prefs_get_path (char const* name);

GList*
purple_prefs_get_path_list (char const* name);

GList*
purple_prefs_get_children_names (char const* name);

guint
purple_prefs_connect_callback (void* handle, char const* name, PurplePrefCallback cb, gpointer data);

void
purple_prefs_disconnect_callback (guint callback_id);

void
purple_prefs_disconnect_by_handle (void* handle);

void
purple_prefs_trigger_callback (char const* name);

gboolean
purple_prefs_load ();

void
purple_prefs_update_old ();
