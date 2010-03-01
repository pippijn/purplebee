GType
purple_smiley_get_type ();

PurpleSmiley*
purple_smiley_new (PurpleStoredImage* img, char const* shortcut);

PurpleSmiley*
purple_smiley_new_from_file (char const* shortcut, char const* filepath);

void
purple_smiley_delete (PurpleSmiley* smiley);

gboolean
purple_smiley_set_shortcut (PurpleSmiley* smiley, char const* shortcut);

void
purple_smiley_set_data (PurpleSmiley* smiley, guchar* smiley_data, size_t smiley_data_len);

char const*
purple_smiley_get_shortcut (PurpleSmiley* smiley);

char const*
purple_smiley_get_checksum (PurpleSmiley* smiley);

PurpleStoredImage*
purple_smiley_get_stored_image (PurpleSmiley* smiley);

gconstpointer
purple_smiley_get_data (PurpleSmiley* smiley, size_t* len);

char const*
purple_smiley_get_extension (PurpleSmiley* smiley);

char*
purple_smiley_get_full_path (PurpleSmiley* smiley);

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
