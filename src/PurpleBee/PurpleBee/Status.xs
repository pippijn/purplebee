MODULE = PurpleBee      PACKAGE = PurpleBee::Status             PREFIX = purple_status_


PurpleStatusType*
purple_status_type_new_full (PurpleStatusPrimitive primitive, char const* id, char const* name, gboolean saveable, gboolean user_settable, gboolean independent);

PurpleStatusType*
purple_status_type_new (PurpleStatusPrimitive primitive, char const* id, char const* name, gboolean user_settable);

PurpleStatusType*
purple_status_type_new_with_attrs (PurpleStatusPrimitive primitive, char const* id, char const* name, gboolean saveable, gboolean user_settable, gboolean independent, char const* attr_id, char const* attr_name, PurpleValue* attr_value, ...);

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

PurpleStatusAttr*
purple_status_attr_new (char const* id, char const* name, PurpleValue* value_type);

void
purple_status_attr_destroy (PurpleStatusAttr* attr);

char const*
purple_status_attr_get_id (PurpleStatusAttr* attr);

char const*
purple_status_attr_get_name (PurpleStatusAttr* attr);

PurpleValue*
purple_status_attr_get_value (PurpleStatusAttr* attr);

PurpleStatus*
purple_status_new (PurpleStatusType* status_type, PurplePresence* presence);

void
purple_status_destroy (PurpleStatus* status);

void
purple_status_set_active (PurpleStatus* status, gboolean active);

void
purple_status_set_active_with_attrs (PurpleStatus* status, gboolean active, va_list args);

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
