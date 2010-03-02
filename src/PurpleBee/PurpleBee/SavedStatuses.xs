MODULE = PurpleBee      PACKAGE = PurpleBee::SavedStatuses              PREFIX = purple_savedstatuses_


GList*
purple_savedstatuses_get_all ();

GList*
purple_savedstatuses_get_popular (unsigned int how_many);

void*
purple_savedstatuses_get_handle ();

void
purple_savedstatuses_init ();

void
purple_savedstatuses_uninit ();
