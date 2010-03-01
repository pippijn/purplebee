GType purple_sound_theme_get_type (void);
const gchar* purple_sound_theme_get_file (PurpleSoundTheme* theme, const gchar* event);
gchar* purple_sound_theme_get_file_full (PurpleSoundTheme* theme, const gchar* event);
void purple_sound_theme_set_file (PurpleSoundTheme* theme, const gchar* event, const gchar* filename);
