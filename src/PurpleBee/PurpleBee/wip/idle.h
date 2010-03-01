void
purple_idle_touch ();

void
purple_idle_set (time_t time);

void
purple_idle_set_ui_ops (PurpleIdleUiOps* ops);

PurpleIdleUiOps*
purple_idle_get_ui_ops ();

void
purple_idle_init ();

void
purple_idle_uninit ();
