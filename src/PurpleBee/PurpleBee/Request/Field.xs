MODULE = PurpleBee      PACKAGE = PurpleBee::Request::Field             PREFIX = purple_request_field_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


PurpleRequestFieldGroup*
purple_request_field_group_new (char const* title);

void
purple_request_field_group_destroy (PurpleRequestFieldGroup* group);

void
purple_request_field_group_add_field (PurpleRequestFieldGroup* group, PurpleRequestField* field);

char const*
purple_request_field_group_get_title (PurpleRequestFieldGroup* group);

GList*
purple_request_field_group_get_fields (PurpleRequestFieldGroup* group);

PurpleRequestField*
purple_request_field_new (char const* id, char const* text, PurpleRequestFieldType type);

void
purple_request_field_destroy (PurpleRequestField* field);

void
purple_request_field_set_label (PurpleRequestField* field, char const* label);

void
purple_request_field_set_visible (PurpleRequestField* field, gboolean visible);

void
purple_request_field_set_type_hint (PurpleRequestField* field, char const* type_hint);

void
purple_request_field_set_required (PurpleRequestField* field, gboolean required);

PurpleRequestFieldType
purple_request_field_get_type (PurpleRequestField* field);

PurpleRequestFieldGroup*
purple_request_field_get_group (PurpleRequestField* field);

char const*
purple_request_field_get_id (PurpleRequestField* field);

char const*
purple_request_field_get_label (PurpleRequestField* field);

gboolean
purple_request_field_is_visible (PurpleRequestField* field);

char const*
purple_request_field_get_type_hint (PurpleRequestField* field);

gboolean
purple_request_field_is_required (PurpleRequestField* field);

gpointer
purple_request_field_get_ui_data (PurpleRequestField* field);

void
purple_request_field_set_ui_data (PurpleRequestField* field, gpointer ui_data);

PurpleRequestField*
purple_request_field_string_new (char const* id, char const* text, char const* default_value, gboolean multiline);

void
purple_request_field_string_set_default_value (PurpleRequestField* field, char const* default_value);

void
purple_request_field_string_set_value (PurpleRequestField* field, char const* value);

void
purple_request_field_string_set_masked (PurpleRequestField* field, gboolean masked);

void
purple_request_field_string_set_editable (PurpleRequestField* field, gboolean editable);

char const*
purple_request_field_string_get_default_value (PurpleRequestField* field);

char const*
purple_request_field_string_get_value (PurpleRequestField* field);

gboolean
purple_request_field_string_is_multiline (PurpleRequestField* field);

gboolean
purple_request_field_string_is_masked (PurpleRequestField* field);

gboolean
purple_request_field_string_is_editable (PurpleRequestField* field);

PurpleRequestField*
purple_request_field_int_new (char const* id, char const* text, int default_value);

void
purple_request_field_int_set_default_value (PurpleRequestField* field, int default_value);

void
purple_request_field_int_set_value (PurpleRequestField* field, int value);

int
purple_request_field_int_get_default_value (PurpleRequestField* field);

int
purple_request_field_int_get_value (PurpleRequestField* field);

PurpleRequestField*
purple_request_field_bool_new (char const* id, char const* text, gboolean default_value);

void
purple_request_field_bool_set_default_value (PurpleRequestField* field, gboolean default_value);

void
purple_request_field_bool_set_value (PurpleRequestField* field, gboolean value);

gboolean
purple_request_field_bool_get_default_value (PurpleRequestField* field);

gboolean
purple_request_field_bool_get_value (PurpleRequestField* field);

PurpleRequestField*
purple_request_field_choice_new (char const* id, char const* text, int default_value);

void
purple_request_field_choice_add (PurpleRequestField* field, char const* label);

void
purple_request_field_choice_set_default_value (PurpleRequestField* field, int default_value);

void
purple_request_field_choice_set_value (PurpleRequestField* field, int value);

int
purple_request_field_choice_get_default_value (PurpleRequestField* field);

int
purple_request_field_choice_get_value (PurpleRequestField* field);

GList*
purple_request_field_choice_get_labels (PurpleRequestField* field);

PurpleRequestField*
purple_request_field_list_new (char const* id, char const* text);

void
purple_request_field_list_set_multi_select (PurpleRequestField* field, gboolean multi_select);

gboolean
purple_request_field_list_get_multi_select (PurpleRequestField* field);

void*
purple_request_field_list_get_data (PurpleRequestField* field, char const* text);

void
purple_request_field_list_add (PurpleRequestField* field, char const* item, void* data);

void
purple_request_field_list_add_selected (PurpleRequestField* field, char const* item);

void
purple_request_field_list_clear_selected (PurpleRequestField* field);

void
purple_request_field_list_set_selected (PurpleRequestField* field, GList* items);

gboolean
purple_request_field_list_is_selected (PurpleRequestField* field, char const* item);

GList*
purple_request_field_list_get_selected (PurpleRequestField* field);

GList*
purple_request_field_list_get_items (PurpleRequestField* field);

PurpleRequestField*
purple_request_field_label_new (char const* id, char const* text);

PurpleRequestField*
purple_request_field_image_new (char const* id, char const* text, char const* buf, gsize size);

void
purple_request_field_image_set_scale (PurpleRequestField* field, unsigned int x, unsigned int y);

char const*
purple_request_field_image_get_buffer (PurpleRequestField* field);

gsize
purple_request_field_image_get_size (PurpleRequestField* field);

unsigned int
purple_request_field_image_get_scale_x (PurpleRequestField* field);

unsigned int
purple_request_field_image_get_scale_y (PurpleRequestField* field);

PurpleRequestField*
purple_request_field_account_new (char const* id, char const* text, PurpleAccount* account);

void
purple_request_field_account_set_default_value (PurpleRequestField* field, PurpleAccount* default_value);

void
purple_request_field_account_set_value (PurpleRequestField* field, PurpleAccount* value);

void
purple_request_field_account_set_show_all (PurpleRequestField* field, gboolean show_all);

void
purple_request_field_account_set_filter (PurpleRequestField* field, PurpleFilterAccountFunc filter_func);

PurpleAccount*
purple_request_field_account_get_default_value (PurpleRequestField* field);

PurpleAccount*
purple_request_field_account_get_value (PurpleRequestField* field);

gboolean
purple_request_field_account_get_show_all (PurpleRequestField* field);

PurpleFilterAccountFunc
purple_request_field_account_get_filter (PurpleRequestField* field);
