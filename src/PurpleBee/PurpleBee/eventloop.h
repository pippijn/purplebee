guint purple_timeout_add (guint interval, GSourceFunc function, gpointer data);
guint purple_timeout_add_seconds (guint interval, GSourceFunc function, gpointer data);
gboolean purple_timeout_remove (guint handle);
guint purple_input_add (int fd, PurpleInputCondition cond, PurpleInputFunction func, gpointer user_data);
gboolean purple_input_remove (guint handle);
int purple_input_get_error (int fd, int* error);
