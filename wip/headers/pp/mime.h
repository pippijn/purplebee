PurpleMimeDocument* purple_mime_document_new (void);






void purple_mime_document_free (PurpleMimeDocument* doc);
PurpleMimeDocument* purple_mime_document_parse (const char* buf);
PurpleMimeDocument* purple_mime_document_parsen (const char* buf, gsize len);
void purple_mime_document_write (PurpleMimeDocument* doc, GString* str);
GList* purple_mime_document_get_fields (PurpleMimeDocument* doc);
const char* purple_mime_document_get_field (PurpleMimeDocument* doc, const char* field);
void purple_mime_document_set_field (PurpleMimeDocument* doc, const char* field, const char* value);
GList* purple_mime_document_get_parts (PurpleMimeDocument* doc);
PurpleMimePart* purple_mime_part_new (PurpleMimeDocument* doc);
GList* purple_mime_part_get_fields (PurpleMimePart* part);
const char* purple_mime_part_get_field (PurpleMimePart* part, const char* field);
char* purple_mime_part_get_field_decoded (PurpleMimePart* part, const char* field);
void purple_mime_part_set_field (PurpleMimePart* part, const char* field, const char* value);
const char* purple_mime_part_get_data (PurpleMimePart* part);
void purple_mime_part_get_data_decoded (PurpleMimePart* part, guchar** data, gsize* len);
gsize purple_mime_part_get_length (PurpleMimePart* part);
void purple_mime_part_set_data (PurpleMimePart* part, const char* data);
