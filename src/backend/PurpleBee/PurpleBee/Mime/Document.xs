MODULE = PurpleBee      PACKAGE = PurpleBee::Mime::Document             PREFIX = purple_mime_document_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


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
