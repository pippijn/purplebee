gboolean
purple_privacy_permit_add (PurpleAccount* account, char const* name, gboolean local_only);

gboolean
purple_privacy_permit_remove (PurpleAccount* account, char const* name, gboolean local_only);

gboolean
purple_privacy_deny_add (PurpleAccount* account, char const* name, gboolean local_only);

gboolean
purple_privacy_deny_remove (PurpleAccount* account, char const* name, gboolean local_only);

void
purple_privacy_allow (PurpleAccount* account, char const* who, gboolean local, gboolean restore);

void
purple_privacy_deny (PurpleAccount* account, char const* who, gboolean local, gboolean restore);

gboolean
purple_privacy_check (PurpleAccount* account, char const* who);

void
purple_privacy_set_ui_ops (PurplePrivacyUiOps* ops);

PurplePrivacyUiOps*
purple_privacy_get_ui_ops ();

void
purple_privacy_init ();
