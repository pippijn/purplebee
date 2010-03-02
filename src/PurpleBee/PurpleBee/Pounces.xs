MODULE = PurpleBee      PACKAGE = PurpleBee::Pounces                    PREFIX = purple_pounces_


gboolean
purple_pounces_load ();

void
purple_pounces_register_handler (char const* ui, PurplePounceCb cb, PurplePounceFunction new_pounce, PurplePounceFunction free_pounce);

void
purple_pounces_unregister_handler (char const* ui);

GList*
purple_pounces_get_all ();

GList*
purple_pounces_get_all_for_ui (char const* ui);

void*
purple_pounces_get_handle ();

void
purple_pounces_init ();

void
purple_pounces_uninit ();
