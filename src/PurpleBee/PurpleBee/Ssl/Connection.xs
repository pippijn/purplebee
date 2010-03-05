MODULE = PurpleBee      PACKAGE = PurpleBee::Ssl::Connection    PREFIX = purple_ssl_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


void
purple_ssl_input_add (PurpleSslConnection* gsc, PurpleSslInputFunction func, void* data);

void
purple_ssl_close (PurpleSslConnection* gsc);

size_t
purple_ssl_read (PurpleSslConnection* gsc, void* buffer, size_t len);

size_t
purple_ssl_write (PurpleSslConnection* gsc, void const* buffer, size_t len);

GList*
purple_ssl_get_peer_certificates (PurpleSslConnection* gsc);
