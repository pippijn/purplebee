MODULE = PurpleBee      PACKAGE = PurpleBee::Connections        PREFIX = purple_connections_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


void
purple_connections_disconnect_all ();

GList*
purple_connections_get_all ();

GList*
purple_connections_get_connecting ();

void
purple_connections_set_ui_ops (PurpleConnectionUiOps* ops);

PurpleConnectionUiOps*
purple_connections_get_ui_ops ();

void
purple_connections_init ();

void
purple_connections_uninit ();

void*
purple_connections_get_handle ();
