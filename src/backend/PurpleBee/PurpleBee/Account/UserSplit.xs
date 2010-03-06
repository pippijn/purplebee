MODULE = PurpleBee      PACKAGE = PurpleBee::Account::UserSplit PREFIX = purple_account_user_split_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


PurpleAccountUserSplit*
purple_account_user_split_new (char const* text, char const* default_value, char sep);

void
purple_account_user_split_destroy (PurpleAccountUserSplit* split);

char const*
purple_account_user_split_get_text (PurpleAccountUserSplit* split);

char const*
purple_account_user_split_get_default_value (PurpleAccountUserSplit* split);

char
purple_account_user_split_get_separator (PurpleAccountUserSplit* split);

gboolean
purple_account_user_split_get_reverse (PurpleAccountUserSplit* split);

void
purple_account_user_split_set_reverse (PurpleAccountUserSplit* split, gboolean reverse);
