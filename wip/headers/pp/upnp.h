void purple_upnp_init (void);
void purple_upnp_discover (PurpleUPnPCallback cb, gpointer cb_data);
const gchar* purple_upnp_get_public_ip (void);
void purple_upnp_cancel_port_mapping (UPnPMappingAddRemove* mapping_data);
UPnPMappingAddRemove* purple_upnp_set_port_mapping (unsigned short portmap, const gchar* protocol, PurpleUPnPCallback cb, gpointer cb_data);
UPnPMappingAddRemove* purple_upnp_remove_port_mapping (unsigned short portmap, const gchar* protocol, PurpleUPnPCallback cb, gpointer cb_data);
