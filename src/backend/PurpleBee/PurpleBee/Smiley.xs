MODULE = PurpleBee      PACKAGE = PurpleBee::Smiley             PREFIX = purple_smiley_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

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
purple_smiley_get_data (PurpleSmiley* smiley, size_t& len);
    OUTPUT:
    len

char const*
purple_smiley_get_extension (PurpleSmiley* smiley);

char*
purple_smiley_get_full_path (PurpleSmiley* smiley);
