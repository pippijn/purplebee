MODULE = PurpleBee      PACKAGE = PurpleBee::Chat                       PREFIX = purple_chat_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


PurpleChat*
purple_chat_new (PurpleAccount* account, char const* alias, GHashTable* components);

void
purple_chat_destroy (PurpleChat* chat);

char const*
purple_chat_get_name (PurpleChat* chat);

PurpleGroup*
purple_chat_get_group (PurpleChat* chat);

PurpleAccount*
purple_chat_get_account (PurpleChat* chat);

GHashTable*
purple_chat_get_components (PurpleChat* chat);
