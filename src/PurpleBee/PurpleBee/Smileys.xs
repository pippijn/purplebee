MODULE = PurpleBee      PACKAGE = PurpleBee::Smileys            PREFIX = purple_smileys_


GList*
purple_smileys_get_all ();

PurpleSmiley*
purple_smileys_find_by_shortcut (char const* shortcut);

PurpleSmiley*
purple_smileys_find_by_checksum (char const* checksum);

char const*
purple_smileys_get_storing_dir ();

void
purple_smileys_init ();

void
purple_smileys_uninit ();
