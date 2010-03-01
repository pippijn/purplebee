PurpleSrvQueryData* purple_srv_resolve (const char* protocol, const char* transport, const char* domain, PurpleSrvCallback cb, gpointer extradata);
void purple_srv_cancel (PurpleSrvQueryData* query_data);
PurpleSrvQueryData* purple_txt_resolve (const char* owner, const char* domain, PurpleTxtCallback cb, gpointer extradata);
void purple_txt_cancel (PurpleSrvQueryData* query_data);
const gchar* purple_txt_response_get_content (PurpleTxtResponse* response);
void purple_txt_response_destroy (PurpleTxtResponse* response);
