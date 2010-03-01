PurpleStringref* purple_stringref_new (const char* value);
PurpleStringref* purple_stringref_new_noref (const char* value);
PurpleStringref* purple_stringref_printf (const char* format, ...);
PurpleStringref* purple_stringref_ref (PurpleStringref* stringref);
void purple_stringref_unref (PurpleStringref* stringref);
const char* purple_stringref_value (const PurpleStringref* stringref);
int purple_stringref_cmp (const PurpleStringref* s1, const PurpleStringref* s2);
size_t purple_stringref_len (const PurpleStringref* stringref);
