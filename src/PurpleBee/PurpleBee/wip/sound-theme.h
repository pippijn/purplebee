GType
purple_sound_theme_get_type ();

gchar const*
purple_sound_theme_get_file (PurpleSoundTheme* theme, gchar const* event);

gchar*
purple_sound_theme_get_file_full (PurpleSoundTheme* theme, gchar const* event);

void
purple_sound_theme_set_file (PurpleSoundTheme* theme, gchar const* event, gchar const* filename);
