PurpleSrvQueryData*
purple_srv_resolve (char const* protocol, char const* transport, char const* domain, PurpleSrvCallback cb, gpointer extradata);

void
purple_srv_cancel (PurpleSrvQueryData* query_data);

PurpleSrvQueryData*
purple_txt_resolve (char const* owner, char const* domain, PurpleTxtCallback cb, gpointer extradata);

void
purple_txt_cancel (PurpleSrvQueryData* query_data);

gchar const*
purple_txt_response_get_content (PurpleTxtResponse* response);

void
purple_txt_response_destroy (PurpleTxtResponse* response);
