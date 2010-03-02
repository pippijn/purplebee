MODULE = PurpleBee      PACKAGE = PurpleBee::Mime::Part                 PREFIX = purple_mime_part_


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
