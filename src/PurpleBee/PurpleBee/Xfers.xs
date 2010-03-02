MODULE = PurpleBee      PACKAGE = PurpleBee::Xfers                      PREFIX = purple_xfers_


GList*
purple_xfers_get_all ();

void*
purple_xfers_get_handle ();

void
purple_xfers_init ();

void
purple_xfers_uninit ();

void
purple_xfers_set_ui_ops (PurpleXferUiOps* ops);

PurpleXferUiOps*
purple_xfers_get_ui_ops ();
