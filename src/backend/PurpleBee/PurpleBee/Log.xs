MODULE = PurpleBee      PACKAGE = PurpleBee::Log                        PREFIX = purple_log_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    LOG_
  const_val (IM);
  const_val (CHAT);
  const_val (SYSTEM);

  const_val (READ_NO_NEWLINE);
#undef TYPE
}

PurpleLog*
purple_log_new (PurpleLogType type, char const* name, PurpleAccount* account, PurpleConversation* conv, time_t time, struct tm* tm);

void
purple_log_free (PurpleLog* log);

void
purple_log_write (PurpleLog* log, PurpleMessageFlags type, char const* from, time_t time, char const* message);

char*
purple_log_read (PurpleLog* log, PurpleLogReadFlags& flags);
    OUTPUT:
    flags

GList*
purple_log_get_logs (PurpleLogType type, char const* name, PurpleAccount* account);

GHashTable*
purple_log_get_log_sets ();

GList*
purple_log_get_system_logs (PurpleAccount* account);

int
purple_log_get_size (PurpleLog* log);

int
purple_log_get_total_size (PurpleLogType type, char const* name, PurpleAccount* account);

int
purple_log_get_activity_score (PurpleLogType type, char const* name, PurpleAccount* account);

gboolean
purple_log_is_deletable (PurpleLog* log);

gboolean
purple_log_delete (PurpleLog* log);

char*
purple_log_get_log_dir (PurpleLogType type, char const* name, PurpleAccount* account);

gint
purple_log_compare (gconstpointer y, gconstpointer z);

gint
purple_log_set_compare (gconstpointer y, gconstpointer z);

void
purple_log_set_free (PurpleLogSet* set);

void
purple_log_common_writer (PurpleLog* log, char const* ext);

GList*
purple_log_common_lister (PurpleLogType type, char const* name, PurpleAccount* account, char const* ext, PurpleLogLogger* logger);

int
purple_log_common_total_sizer (PurpleLogType type, char const* name, PurpleAccount* account, char const* ext);

int
purple_log_common_sizer (PurpleLog* log);

gboolean
purple_log_common_deleter (PurpleLog* log);

gboolean
purple_log_common_is_deletable (PurpleLog* log);

#PurpleLogLogger*
#purple_log_logger_new (char const* id, char const* name, int functions, ...);

void
purple_log_logger_free (PurpleLogLogger* logger);

void
purple_log_logger_add (PurpleLogLogger* logger);

void
purple_log_logger_remove (PurpleLogLogger* logger);

void
purple_log_logger_set (PurpleLogLogger* logger);

PurpleLogLogger*
purple_log_logger_get ();

GList*
purple_log_logger_get_options ();

void
purple_log_init ();

void*
purple_log_get_handle ();

void
purple_log_uninit ();
