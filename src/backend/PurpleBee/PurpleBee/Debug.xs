MODULE = PurpleBee      PACKAGE = PurpleBee::Debug                      PREFIX = purple_debug_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


void
purple_debug_print (PurpleDebugLevel level, char const* category, char const* format)
    CODE:
    purple_debug (level, category, "%s", format);

void
purple_debug_misc (char const* category, char const* format)
    CODE:
    purple_debug_misc (category, "%s", format);

void
purple_debug_info (char const* category, char const* format)
    CODE:
    purple_debug_info (category, "%s", format);

void
purple_debug_warning (char const* category, char const* format)
    CODE:
    purple_debug_warning (category, "%s", format);

void
purple_debug_error (char const* category, char const* format)
    CODE:
    purple_debug_error (category, "%s", format);

void
purple_debug_fatal (char const* category, char const* format)
    CODE:
    purple_debug_fatal (category, "%s", format);

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
