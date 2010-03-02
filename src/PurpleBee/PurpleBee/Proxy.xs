MODULE = PurpleBee      PACKAGE = PurpleBee::Proxy                      PREFIX = purple_proxy_


PurpleProxyInfo*
purple_proxy_info_new ();

void
purple_proxy_info_destroy (PurpleProxyInfo* info);

void
purple_proxy_info_set_type (PurpleProxyInfo* info, PurpleProxyType type);

void
purple_proxy_info_set_host (PurpleProxyInfo* info, char const* host);

void
purple_proxy_info_set_port (PurpleProxyInfo* info, int port);

void
purple_proxy_info_set_username (PurpleProxyInfo* info, char const* username);

void
purple_proxy_info_set_password (PurpleProxyInfo* info, char const* password);

PurpleProxyType
purple_proxy_info_get_type (PurpleProxyInfo* info);

char const*
purple_proxy_info_get_host (PurpleProxyInfo* info);

int
purple_proxy_info_get_port (PurpleProxyInfo* info);

char const*
purple_proxy_info_get_username (PurpleProxyInfo* info);

char const*
purple_proxy_info_get_password (PurpleProxyInfo* info);

void*
purple_proxy_get_handle ();

void
purple_proxy_init ();

void
purple_proxy_uninit ();

PurpleProxyInfo*
purple_proxy_get_setup (PurpleAccount* account);

PurpleProxyConnectData*
purple_proxy_connect (void* handle, PurpleAccount* account, char const* host, int port, PurpleProxyConnectFunction connect_cb, gpointer data);

PurpleProxyConnectData*
purple_proxy_connect_udp (void* handle, PurpleAccount* account, char const* host, int port, PurpleProxyConnectFunction connect_cb, gpointer data);

PurpleProxyConnectData*
purple_proxy_connect_socks5 (void* handle, PurpleProxyInfo* gpi, char const* host, int port, PurpleProxyConnectFunction connect_cb, gpointer data);

void
purple_proxy_connect_cancel (PurpleProxyConnectData* connect_data);

void
purple_proxy_connect_cancel_with_handle (void* handle);
