MODULE = PurpleBee      PACKAGE = PurpleBee::Status::Type               PREFIX = purple_status_type_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


PurpleStatusType*
purple_status_type_new_full (PurpleStatusPrimitive primitive, char const* id, char const* name, gboolean saveable, gboolean user_settable, gboolean independent);

PurpleStatusType*
purple_status_type_new (PurpleStatusPrimitive primitive, char const* id, char const* name, gboolean user_settable);

#PurpleStatusType*
#purple_status_type_new_with_attrs (PurpleStatusPrimitive primitive, char const* id, char const* name, gboolean saveable, gboolean user_settable, gboolean independent, char const* attr_id, char const* attr_name, PurpleValue* attr_value, ...);

void
purple_status_type_destroy (PurpleStatusType* status_type);

PurpleStatusPrimitive
purple_status_type_get_primitive (PurpleStatusType* status_type);

char const*
purple_status_type_get_id (PurpleStatusType* status_type);

char const*
purple_status_type_get_name (PurpleStatusType* status_type);

gboolean
purple_status_type_is_saveable (PurpleStatusType* status_type);

gboolean
purple_status_type_is_user_settable (PurpleStatusType* status_type);

gboolean
purple_status_type_is_independent (PurpleStatusType* status_type);

gboolean
purple_status_type_is_exclusive (PurpleStatusType* status_type);

gboolean
purple_status_type_is_available (PurpleStatusType* status_type);

PurpleStatusAttr*
purple_status_type_get_attr (PurpleStatusType* status_type, char const* id);

GList*
purple_status_type_get_attrs (PurpleStatusType* status_type);

PurpleStatusType const*
purple_status_type_find_with_id (GList* status_types, char const* id);
