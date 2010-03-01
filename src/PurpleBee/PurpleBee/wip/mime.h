PurpleMimeDocument*
purple_mime_document_new ();

void
purple_mime_document_free (PurpleMimeDocument* doc);

PurpleMimeDocument*
purple_mime_document_parse (char const* buf);

PurpleMimeDocument*
purple_mime_document_parsen (char const* buf, gsize len);

void
purple_mime_document_write (PurpleMimeDocument* doc, GString* str);

GList*
purple_mime_document_get_fields (PurpleMimeDocument* doc);

char const*
purple_mime_document_get_field (PurpleMimeDocument* doc, char const* field);

void
purple_mime_document_set_field (PurpleMimeDocument* doc, char const* field, char const* value);

GList*
purple_mime_document_get_parts (PurpleMimeDocument* doc);

PurpleMimePart*
purple_mime_part_new (PurpleMimeDocument* doc);

GList*
purple_mime_part_get_fields (PurpleMimePart* part);

char const*
purple_mime_part_get_field (PurpleMimePart* part, char const* field);

char*
purple_mime_part_get_field_decoded (PurpleMimePart* part, char const* field);

void
purple_mime_part_set_field (PurpleMimePart* part, char const* field, char const* value);

char const*
purple_mime_part_get_data (PurpleMimePart* part);

void
purple_mime_part_get_data_decoded (PurpleMimePart* part, guchar** data, gsize* len);

gsize
purple_mime_part_get_length (PurpleMimePart* part);

void
purple_mime_part_set_data (PurpleMimePart* part, char const* data);
