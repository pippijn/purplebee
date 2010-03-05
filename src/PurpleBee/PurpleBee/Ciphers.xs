MODULE = PurpleBee      PACKAGE = PurpleBee::Ciphers                    PREFIX = purple_ciphers_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


PurpleCipher*
purple_ciphers_find_cipher (gchar const* name);

PurpleCipher*
purple_ciphers_register_cipher (gchar const* name, PurpleCipherOps* ops);

gboolean
purple_ciphers_unregister_cipher (PurpleCipher* cipher);

GList*
purple_ciphers_get_ciphers ();

gpointer
purple_ciphers_get_handle ();

void
purple_ciphers_init ();

void
purple_ciphers_uninit ();

