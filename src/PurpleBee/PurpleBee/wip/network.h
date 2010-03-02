char unsigned const*
purple_network_ip_atoi (char const* ip);

void
purple_network_set_public_ip (char const* ip);

char const*
purple_network_get_public_ip ();

char const*
purple_network_get_local_system_ip (int fd);

char const*
purple_network_get_my_ip (int fd);

void
purple_network_listen_map_external (gboolean map_external);

PurpleNetworkListenData*
purple_network_listen (unsigned short port, int socket_type, PurpleNetworkListenCallback cb, gpointer cb_data);

PurpleNetworkListenData*
purple_network_listen_range (unsigned short start, unsigned short end, int socket_type, PurpleNetworkListenCallback cb, gpointer cb_data);

void
purple_network_listen_cancel (PurpleNetworkListenData* listen_data);

unsigned short
purple_network_get_port_from_fd (int fd);

gboolean
purple_network_is_available ();

void
purple_network_force_online ();

void*
purple_network_get_handle ();

void
purple_network_set_stun_server (gchar const* stun_server);

gchar const*
purple_network_get_stun_ip ();

void
purple_network_set_turn_server (gchar const* turn_server);

gchar const*
purple_network_get_turn_ip ();

void
purple_network_remove_port_mapping (gint fd);

int
purple_network_convert_idn_to_ascii (gchar const* in, gchar** out);

void
purple_network_init ();

void
purple_network_uninit ();
