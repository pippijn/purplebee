void purple_debug (PurpleDebugLevel level, const char* category, const char* format, ...);
void purple_debug_misc (const char* category, const char* format, ...);
void purple_debug_info (const char* category, const char* format, ...);
void purple_debug_warning (const char* category, const char* format, ...);
void purple_debug_error (const char* category, const char* format, ...);
void purple_debug_fatal (const char* category, const char* format, ...);
void purple_debug_set_enabled (gboolean enabled);
gboolean purple_debug_is_enabled (void);
void purple_debug_set_verbose (gboolean verbose);
gboolean purple_debug_is_verbose (void);
void purple_debug_set_unsafe (gboolean unsafe);
gboolean purple_debug_is_unsafe (void);
