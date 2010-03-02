MODULE = PurpleBee      PACKAGE = PurpleBee::Ssl                PREFIX = purple_ssl_


gboolean
purple_ssl_is_supported ();

gchar const*
purple_ssl_strerror (PurpleSslErrorType error);

PurpleSslConnection*
purple_ssl_connect (PurpleAccount* account, char const* host, int port, PurpleSslInputFunction func, PurpleSslErrorFunction error_func, void* data);

PurpleSslConnection*
purple_ssl_connect_with_ssl_cn (PurpleAccount* account, char const* host, int port, PurpleSslInputFunction func, PurpleSslErrorFunction error_func, char const* ssl_host, void* data);

PurpleSslConnection*
purple_ssl_connect_with_host_fd (PurpleAccount* account, int fd, PurpleSslInputFunction func, PurpleSslErrorFunction error_func, char const* host, void* data);

void
purple_ssl_set_ops (PurpleSslOps* ops);

PurpleSslOps*
purple_ssl_get_ops ();

void
purple_ssl_init ();

void
purple_ssl_uninit ();
