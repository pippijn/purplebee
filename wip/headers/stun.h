#ifdef __cplusplus
extern "C" {
#endif

/**
 * Starts a NAT discovery. It returns a PurpleStunNatDiscovery if the discovery
 * is already done. Otherwise the callback is called when the discovery is over
 * and NULL is returned.
 *
 * @param cb The callback to call when the STUN discovery is finished if the
 *           discovery would block.  If the discovery is done, this is NOT
 *           called.
 *
 * @return a PurpleStunNatDiscovery which includes the public IP and the type
 *         of NAT or NULL is discovery would block
 */
PurpleStunNatDiscovery *purple_stun_discover(StunCallback cb);

void purple_stun_init(void);

/*@}*/

#ifdef __cplusplus
}
#endif
