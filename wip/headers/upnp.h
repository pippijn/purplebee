#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize UPnP
 */
void purple_upnp_init(void);


/**
 * Sends a discovery request to search for a UPnP enabled IGD that
 * contains the WANIPConnection service that will allow us to recieve the
 * public IP address of the IGD, and control it for forwarding ports.
 * The result will be cached for further use.
 *
 * @param cb an optional callback function to be notified when the UPnP
 *           discovery is complete
 * @param cb_data Extra data to be passed to the callback
 */
void purple_upnp_discover(PurpleUPnPCallback cb, gpointer cb_data);

#if 0
/**
 * Retrieve the current UPnP control info, if there is any available.
 * This will only be filled in if purple_upnp_discover() had been called,
 * and finished discovering.
 *
 * @return The control URL for the IGD we'll use to use the IGD services
 */
const PurpleUPnPControlInfo* purple_upnp_get_control_info(void);
#endif

/**
 * Gets the IP address from a UPnP enabled IGD that sits on the local
 * network, so when getting the network IP, instead of returning the
 * local network IP, the public IP is retrieved.  This is a cached value from
 * the time of the UPnP discovery.
 *
 * @return The IP address of the network, or NULL if something went wrong
 */
const gchar* purple_upnp_get_public_ip(void);

/**
 * Cancel a pending port mapping request initiated with either
 * purple_upnp_set_port_mapping() or purple_upnp_remove_port_mapping().
 *
 * @param mapping_data The data returned when you initiated the UPnP mapping request.
 */
void purple_upnp_cancel_port_mapping(UPnPMappingAddRemove *mapping_data);

/**
 * Maps Ports in a UPnP enabled IGD that sits on the local network to
 * this purple client. Essentially, this function takes care of the port
 * forwarding so things like file transfers can work behind NAT firewalls
 *
 * @param portmap The port to map to this client
 * @param protocol The protocol to map, either "TCP" or "UDP"
 * @param cb an optional callback function to be notified when the mapping
 *           addition is complete
 * @param cb_data Extra data to be passed to the callback
 *
 * @return Data which can be passed to purple_upnp_port_mapping_cancel() to cancel
 */
UPnPMappingAddRemove *purple_upnp_set_port_mapping(unsigned short portmap, const gchar* protocol,
		PurpleUPnPCallback cb, gpointer cb_data);

/**
 * Deletes a port mapping in a UPnP enabled IGD that sits on the local network
 * to this purple client. Essentially, this function takes care of deleting the
 * port forwarding after they have completed a connection so another client on
 * the local network can take advantage of the port forwarding
 *
 * @param portmap The port to delete the mapping for
 * @param protocol The protocol to map to. Either "TCP" or "UDP"
 * @param cb an optional callback function to be notified when the mapping
 *           removal is complete
 * @param cb_data Extra data to be passed to the callback
 *
 * @return Data which can be passed to purple_upnp_port_mapping_cancel() to cancel
 */
UPnPMappingAddRemove *purple_upnp_remove_port_mapping(unsigned short portmap,
		const gchar* protocol, PurpleUPnPCallback cb, gpointer cb_data);

/*@}*/

#ifdef __cplusplus
}
#endif
