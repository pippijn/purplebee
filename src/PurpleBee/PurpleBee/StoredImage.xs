MODULE = PurpleBee      PACKAGE = PurpleBee::StoredImage        PREFIX = purple_imgstore_


PurpleStoredImage*
purple_imgstore_add (gpointer data, size_t size, char const* filename);

PurpleStoredImage*
purple_imgstore_new_from_file (char const* path);

int
purple_imgstore_add_with_id (gpointer data, size_t size, char const* filename);

PurpleStoredImage*
purple_imgstore_find_by_id (int id);

gconstpointer
purple_imgstore_get_data (PurpleStoredImage* img);

size_t
purple_imgstore_get_size (PurpleStoredImage* img);

char const*
purple_imgstore_get_filename (PurpleStoredImage* img);

char const*
purple_imgstore_get_extension (PurpleStoredImage* img);

PurpleStoredImage*
purple_imgstore_ref (PurpleStoredImage* img);

PurpleStoredImage*
purple_imgstore_unref (PurpleStoredImage* img);

void
purple_imgstore_ref_by_id (int id);

void
purple_imgstore_unref_by_id (int id);

void*
purple_imgstore_get_handle ();

void
purple_imgstore_init ();

void
purple_imgstore_uninit ();
