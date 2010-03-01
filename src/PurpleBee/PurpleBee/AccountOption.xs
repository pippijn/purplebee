MODULE = PurpleBee      PACKAGE = PurpleBee::AccountOption      PREFIX = purple_account_option_


PurpleAccountOption*
purple_account_option_new (PurplePrefType type, const char* text, const char* pref_name);

PurpleAccountOption*
purple_account_option_bool_new (const char* text, const char* pref_name, gboolean default_value);

PurpleAccountOption*
purple_account_option_int_new (const char* text, const char* pref_name, int default_value);

PurpleAccountOption*
purple_account_option_string_new (const char* text, const char* pref_name, const char* default_value);

PurpleAccountOption*
purple_account_option_list_new (const char* text, const char* pref_name, GList* list);

void
purple_account_option_destroy (PurpleAccountOption* option);

void
purple_account_option_set_default_bool (PurpleAccountOption* option, gboolean value);

void
purple_account_option_set_default_int (PurpleAccountOption* option, int value);

void
purple_account_option_set_default_string (PurpleAccountOption* option, const char* value);

void
purple_account_option_set_masked (PurpleAccountOption* option, gboolean masked);

void
purple_account_option_set_list (PurpleAccountOption* option, GList* values);

void
purple_account_option_add_list_item (PurpleAccountOption* option, const char* key, const char* value);

PurplePrefType
purple_account_option_get_type (PurpleAccountOption* option);

const char*
purple_account_option_get_text (PurpleAccountOption* option);

const char*
purple_account_option_get_setting (PurpleAccountOption* option);

gboolean
purple_account_option_get_default_bool (PurpleAccountOption* option);

int
purple_account_option_get_default_int (PurpleAccountOption* option);

const char*
purple_account_option_get_default_string (PurpleAccountOption* option);

const char*
purple_account_option_get_default_list_value (PurpleAccountOption* option);

gboolean
purple_account_option_get_masked (PurpleAccountOption* option);

GList*
purple_account_option_get_list (PurpleAccountOption* option);

PurpleAccountUserSplit*
purple_account_user_split_new (const char* text, const char* default_value, char sep);

void
purple_account_user_split_destroy (PurpleAccountUserSplit* split);

const char*
purple_account_user_split_get_text (PurpleAccountUserSplit* split);

const char*
purple_account_user_split_get_default_value (PurpleAccountUserSplit* split);

char
purple_account_user_split_get_separator (PurpleAccountUserSplit* split);

gboolean
purple_account_user_split_get_reverse (PurpleAccountUserSplit* split);

void
purple_account_user_split_set_reverse (PurpleAccountUserSplit* split, gboolean reverse);
