void
purple_debug (PurpleDebugLevel level, char const* category, char const* format, ...);

void
purple_debug_misc (char const* category, char const* format, ...);

void
purple_debug_info (char const* category, char const* format, ...);

void
purple_debug_warning (char const* category, char const* format, ...);

void
purple_debug_error (char const* category, char const* format, ...);

void
purple_debug_fatal (char const* category, char const* format, ...);

void
purple_debug_set_enabled (gboolean enabled);

gboolean
purple_debug_is_enabled ();

void
purple_debug_set_verbose (gboolean verbose);

gboolean
purple_debug_is_verbose ();

void
purple_debug_set_unsafe (gboolean unsafe);

gboolean
purple_debug_is_unsafe ();

void
purple_debug_set_ui_ops (PurpleDebugUiOps* ops);

PurpleDebugUiOps*
purple_debug_get_ui_ops ();

void
purple_debug_init ();
