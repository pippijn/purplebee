MODULE = PurpleBee      PACKAGE = PurpleBee::Account::Option    PREFIX = purple_account_option_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurpleAccountOption*
purple_account_option_new (PurplePrefType type, char const* text, char const* pref_name);

PurpleAccountOption*
purple_account_option_bool_new (char const* text, char const* pref_name, gboolean default_value);

PurpleAccountOption*
purple_account_option_int_new (char const* text, char const* pref_name, int default_value);

PurpleAccountOption*
purple_account_option_string_new (char const* text, char const* pref_name, char const* default_value);

PurpleAccountOption*
purple_account_option_list_new (char const* text, char const* pref_name, GList* list);

void
purple_account_option_destroy (PurpleAccountOption* option);

void
purple_account_option_set_default_bool (PurpleAccountOption* option, gboolean value);

void
purple_account_option_set_default_int (PurpleAccountOption* option, int value);

void
purple_account_option_set_default_string (PurpleAccountOption* option, char const* value);

void
purple_account_option_set_masked (PurpleAccountOption* option, gboolean masked);

void
purple_account_option_set_list (PurpleAccountOption* option, GList* values);

void
purple_account_option_add_list_item (PurpleAccountOption* option, char const* key, char const* value);

PurplePrefType
purple_account_option_get_type (PurpleAccountOption* option);

char const*
purple_account_option_get_text (PurpleAccountOption* option);

char const*
purple_account_option_get_setting (PurpleAccountOption* option);

gboolean
purple_account_option_get_default_bool (PurpleAccountOption* option);

int
purple_account_option_get_default_int (PurpleAccountOption* option);

char const*
purple_account_option_get_default_string (PurpleAccountOption* option);

char const*
purple_account_option_get_default_list_value (PurpleAccountOption* option);

gboolean
purple_account_option_get_masked (PurpleAccountOption* option);

GList*
purple_account_option_get_list (PurpleAccountOption* option);
