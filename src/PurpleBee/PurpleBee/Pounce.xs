MODULE = PurpleBee      PACKAGE = PurpleBee::Pounce                     PREFIX = purple_pounce_


PurplePounce*
purple_pounce_new (char const* ui_type, PurpleAccount* pouncer, char const* pouncee, PurplePounceEvent event, PurplePounceOption option);

void
purple_pounce_destroy (PurplePounce* pounce);

void
purple_pounce_destroy_all_by_account (PurpleAccount* account);

void
purple_pounce_set_events (PurplePounce* pounce, PurplePounceEvent events);

void
purple_pounce_set_options (PurplePounce* pounce, PurplePounceOption options);

void
purple_pounce_set_pouncer (PurplePounce* pounce, PurpleAccount* pouncer);

void
purple_pounce_set_pouncee (PurplePounce* pounce, char const* pouncee);

void
purple_pounce_set_save (PurplePounce* pounce, gboolean save);

void
purple_pounce_action_register (PurplePounce* pounce, char const* name);

void
purple_pounce_action_set_enabled (PurplePounce* pounce, char const* action, gboolean enabled);

void
purple_pounce_action_set_attribute (PurplePounce* pounce, char const* action, char const* attr, char const* value);

void
purple_pounce_set_data (PurplePounce* pounce, void* data);

PurplePounceEvent
purple_pounce_get_events (PurplePounce* pounce);

PurplePounceOption
purple_pounce_get_options (PurplePounce* pounce);

PurpleAccount*
purple_pounce_get_pouncer (PurplePounce* pounce);

char const*
purple_pounce_get_pouncee (PurplePounce* pounce);

gboolean
purple_pounce_get_save (PurplePounce* pounce);

gboolean
purple_pounce_action_is_enabled (PurplePounce* pounce, char const* action);

char const*
purple_pounce_action_get_attribute (PurplePounce* pounce, char const* action, char const* attr);

void*
purple_pounce_get_data (PurplePounce* pounce);

void
purple_pounce_execute (PurpleAccount* pouncer, char const* pouncee, PurplePounceEvent events);
