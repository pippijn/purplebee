MODULE = PurpleBee      PACKAGE = PurpleBee::NTLM                       PREFIX = purple_ntlm_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


gchar*
purple_ntlm_gen_type1 (gchar const* hostname, gchar const* domain);

guint8*
purple_ntlm_parse_type2 (gchar const* type2, guint32& flags);
    OUTPUT:
    flags

gchar*
purple_ntlm_gen_type3 (gchar const* username, gchar const* passw, gchar const* hostname, gchar const* domain, guint8 const* nonce, guint32& flags);
    OUTPUT:
    flags
