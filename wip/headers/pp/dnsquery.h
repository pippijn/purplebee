PurpleDnsQueryData* purple_dnsquery_a (const char* hostname, int port, PurpleDnsQueryConnectFunction callback, gpointer data);
void purple_dnsquery_destroy (PurpleDnsQueryData* query_data);
void purple_dnsquery_set_ui_ops (PurpleDnsQueryUiOps* ops);
PurpleDnsQueryUiOps* purple_dnsquery_get_ui_ops (void);
char* purple_dnsquery_get_host (PurpleDnsQueryData* query_data);
unsigned short purple_dnsquery_get_port (PurpleDnsQueryData* query_data);
void purple_dnsquery_init (void);
void purple_dnsquery_uninit (void);
