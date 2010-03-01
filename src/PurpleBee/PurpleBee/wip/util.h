PurpleMenuAction*
purple_menu_action_new (char const* label, PurpleCallback callback, gpointer data, GList* children);

void
purple_menu_action_free (PurpleMenuAction* act);

void
purple_util_set_current_song (char const* title, char const* artist, char const* album);

char*
purple_util_format_song_info (char const* title, char const* artist, char const* album, gpointer unused);

void
purple_util_init ();

void
purple_util_uninit ();

gchar*
purple_base16_encode (guchar const* data, gsize len);

guchar*
purple_base16_decode (char const* str, gsize* ret_len);

gchar*
purple_base16_encode_chunked (guchar const* data, gsize len);

gchar*
purple_base64_encode (guchar const* data, gsize len);

guchar*
purple_base64_decode (char const* str, gsize* ret_len);

guchar*
purple_quotedp_decode (char const* str, gsize* ret_len);

char*
purple_mime_decode_field (char const* str);

char const*
purple_utf8_strftime (char const* format, struct tm* tm);

char const*
purple_get_tzoff_str (struct tm* tm, gboolean iso);

char const*
purple_date_format_short (struct tm* tm);

char const*
purple_date_format_long (struct tm* tm);

char const*
purple_date_format_full (struct tm* tm);

char const*
purple_time_format (struct tm* tm);

time_t
purple_time_build (int year, int month, int day, int hour, int min, int sec);

time_t
purple_str_to_time (char const* timestamp, gboolean utc, struct tm* tm, long* tz_off, char const** rest);

gchar*
purple_markup_escape_text (gchar const* text, gssize length);

gboolean
purple_markup_find_tag (char const* needle, char const* haystack, char const** start, char const** end, GData** attributes);

gboolean
purple_markup_extract_info_field (char const* str, int len, PurpleNotifyUserInfo* user_info, char const* start_token, int skip, char const* end_token, char check_value, char const* no_value_token, char const* display_name, gboolean is_link, char const* link_prefix, PurpleInfoFieldFormatCallback format_cb);

void
purple_markup_html_to_xhtml (char const* html, char** dest_xhtml, char** dest_plain);

char*
purple_markup_strip_html (char const* str);

char*
purple_markup_linkify (char const* str);

char*
purple_unescape_html (char const* html);

char*
purple_markup_slice (char const* str, guint x, guint y);

char*
purple_markup_get_tag_name (char const* tag);

char const*
purple_markup_unescape_entity (char const* text, int* length);

char*
purple_markup_get_css_property (gchar const* style, gchar const* opt);

gboolean
purple_markup_is_rtl (char const* html);

gchar const*
purple_home_dir ();

char const*
purple_user_dir ();

void
purple_util_set_user_dir (char const* dir);

int
purple_build_dir (char const* path, int mode);

gboolean
purple_util_write_data_to_file (char const* filename, char const* data, gssize size);

gboolean
purple_util_write_data_to_file_absolute (char const* filename_full, char const* data, gssize size);

FILE*
purple_mkstemp (char** path, gboolean binary);

char const*
purple_util_get_image_extension (gconstpointer data, size_t len);

char*
purple_util_get_image_checksum (gconstpointer image_data, size_t image_len);

char*
purple_util_get_image_filename (gconstpointer image_data, size_t image_len);

gboolean
purple_program_is_valid (char const* program);

gboolean
purple_running_gnome ();

gboolean
purple_running_kde ();

gboolean
purple_running_osx ();

char*
purple_fd_get_ip (int fd);

gboolean
purple_strequal (gchar const* left, gchar const* right);

char const*
purple_normalize (PurpleAccount* account, char const* str);

char const*
purple_normalize_nocase (PurpleAccount* account, char const* str);

gboolean
purple_str_has_prefix (char const* s, char const* p);

gboolean
purple_str_has_suffix (char const* s, char const* x);

gchar*
purple_strdup_withhtml (gchar const* src);

char*
purple_str_add_cr (char const* str);

void
purple_str_strip_char (char* str, char thechar);

void
purple_util_chrreplace (char* string, char delimiter, char replacement);

gchar*
purple_strreplace (char const* string, char const* delimiter, char const* replacement);

char*
purple_utf8_ncr_encode (char const* in);

char*
purple_utf8_ncr_decode (char const* in);

gchar*
purple_strcasereplace (char const* string, char const* delimiter, char const* replacement);

char const*
purple_strcasestr (char const* haystack, char const* needle);

char*
purple_str_size_to_units (size_t size);

char*
purple_str_seconds_to_string (guint sec);

char*
purple_str_binary_to_ascii (unsigned char const* binary, guint len);

void
purple_got_protocol_handler_uri (char const* uri);

gboolean
purple_url_parse (char const* url, char** ret_host, int* ret_port, char** ret_path, char** ret_user, char** ret_passwd);

PurpleUtilFetchUrlData*
purple_util_fetch_url (gchar const* url, gboolean full, gchar const* user_agent, gboolean http11, PurpleUtilFetchUrlCallback callback, gpointer data);

PurpleUtilFetchUrlData*
purple_util_fetch_url_request (gchar const* url, gboolean full, gchar const* user_agent, gboolean http11, gchar const* request, gboolean include_headers, PurpleUtilFetchUrlCallback callback, gpointer data);

PurpleUtilFetchUrlData*
purple_util_fetch_url_request_len (gchar const* url, gboolean full, gchar const* user_agent, gboolean http11, gchar const* request, gboolean include_headers, gssize max_len, PurpleUtilFetchUrlCallback callback, gpointer data);

PurpleUtilFetchUrlData*
purple_util_fetch_url_len (gchar const* url, gboolean full, gchar const* user_agent, gboolean http11, gssize max_len, PurpleUtilFetchUrlCallback callback, gpointer data);

PurpleUtilFetchUrlData*
purple_util_fetch_url_request_len_with_account (PurpleAccount* account, gchar const* url, gboolean full, gchar const* user_agent, gboolean http11, gchar const* request, gboolean include_headers, gssize max_len, PurpleUtilFetchUrlCallback callback, gpointer data);

void
purple_util_fetch_url_cancel (PurpleUtilFetchUrlData* url_data);

char const*
purple_url_decode (char const* str);

char const*
purple_url_encode (char const* str);

gboolean
purple_email_is_valid (char const* address);

gboolean
purple_ip_address_is_valid (char const* ip);

gboolean
purple_ipv4_address_is_valid (char const* ip);

gboolean
purple_ipv6_address_is_valid (char const* ip);

GList*
purple_uri_list_extract_uris (gchar const* uri_list);

GList*
purple_uri_list_extract_filenames (gchar const* uri_list);

gchar*
purple_utf8_try_convert (char const* str);

gchar*
purple_utf8_salvage (char const* str);

gchar*
purple_utf8_strip_unprintables (gchar const* str);

gchar const*
purple_gai_strerror (gint errnum);

int
purple_utf8_strcasecmp (char const* a, char const* b);

gboolean
purple_utf8_has_word (char const* haystack, char const* needle);

void
purple_print_utf8_to_console (FILE* filestream, char* message);

gboolean
purple_message_meify (char* message, gssize len);

char*
purple_text_strip_mnemonic (char const* in);

char const*
purple_unescape_filename (char const* str);

char const*
purple_escape_filename (char const* str);

char const*
_purple_oscar_convert (char const* act, char const* protocol);

void
purple_restore_default_signal_handlers ();

gchar const*
purple_get_host_name ();
