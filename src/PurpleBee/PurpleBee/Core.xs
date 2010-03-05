MODULE = PurpleBee      PACKAGE = PurpleBee::Core               PREFIX = purple_core_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


gboolean
purple_core_init (char const* ui);

void
purple_core_quit ();

gboolean
purple_core_quit_cb (gpointer unused);

char const*
purple_core_get_version ();

char const*
purple_core_get_ui ();

void
purple_core_set_ui_ops (PurpleCoreUiOps* ops);

PurpleCoreUiOps*
purple_core_get_ui_ops ();

gboolean
purple_core_migrate ();

gboolean
purple_core_ensure_single_instance ();

GHashTable*
purple_core_get_ui_info ();
