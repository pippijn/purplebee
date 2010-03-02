MODULE = PurpleBee      PACKAGE = PurpleBee::Request::Fields            PREFIX = purple_request_fields_


PurpleRequestFields*
purple_request_fields_new ();

void
purple_request_fields_destroy (PurpleRequestFields* fields);

void
purple_request_fields_add_group (PurpleRequestFields* fields, PurpleRequestFieldGroup* group);

GList*
purple_request_fields_get_groups (PurpleRequestFields* fields);

gboolean
purple_request_fields_exists (PurpleRequestFields* fields, char const* id);

GList*
purple_request_fields_get_required (PurpleRequestFields* fields);

gboolean
purple_request_fields_is_field_required (PurpleRequestFields* fields, char const* id);

gboolean
purple_request_fields_all_required_filled (PurpleRequestFields* fields);

PurpleRequestField*
purple_request_fields_get_field (PurpleRequestFields* fields, char const* id);

char const*
purple_request_fields_get_string (PurpleRequestFields* fields, char const* id);

int
purple_request_fields_get_integer (PurpleRequestFields* fields, char const* id);

gboolean
purple_request_fields_get_bool (PurpleRequestFields* fields, char const* id);

int
purple_request_fields_get_choice (PurpleRequestFields* fields, char const* id);

PurpleAccount*
purple_request_fields_get_account (PurpleRequestFields* fields, char const* id);
