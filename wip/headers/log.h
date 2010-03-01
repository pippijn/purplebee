#ifdef __cplusplus
extern "C" {
#endif

/***************************************/
/** @name Log Functions                */
/***************************************/
/*@{*/

/**
 * Creates a new log
 *
 * @param type        The type of log this is.
 * @param name        The name of this conversation (buddy name, chat name,
 *                    etc.)
 * @param account     The account the conversation is occurring on
 * @param conv        The conversation being logged
 * @param time        The time this conversation started
 * @param tm          The time this conversation started, with timezone data,
 *                    if available and if struct tm has the BSD timezone fields.
 * @return            The new log
 */
PurpleLog *purple_log_new(PurpleLogType type, const char *name, PurpleAccount *account,
                      PurpleConversation *conv, time_t time, const struct tm *tm);

/**
 * Frees a log
 *
 * @param log         The log to destroy
 */
void purple_log_free(PurpleLog *log);

/**
 * Writes to a log file. Assumes you have checked preferences already.
 *
 * @param log          The log to write to
 * @param type         The type of message being logged
 * @param from         Whom this message is coming from, or @c NULL for
 *                     system messages
 * @param time         A timestamp in UNIX time
 * @param message      The message to log
 */
void purple_log_write(PurpleLog *log,
		    PurpleMessageFlags type,
		    const char *from,
		    time_t time,
		    const char *message);

/**
 * Reads from a log
 *
 * @param log   The log to read from
 * @param flags The returned logging flags.
 *
 * @return The contents of this log in Purple Markup.
 */
char *purple_log_read(PurpleLog *log, PurpleLogReadFlags *flags);

/**
 * Returns a list of all available logs
 *
 * @param type                The type of the log
 * @param name                The name of the log
 * @param account             The account
 * @return                    A sorted list of PurpleLogs
 */
GList *purple_log_get_logs(PurpleLogType type, const char *name, PurpleAccount *account);

/**
 * Returns a GHashTable of PurpleLogSets.
 *
 * A "log set" here means the information necessary to gather the
 * PurpleLogs for a given buddy/chat. This information would be passed
 * to purple_log_list to get a list of PurpleLogs.
 *
 * The primary use of this function is to get a list of everyone the
 * user has ever talked to (assuming he or she uses logging).
 *
 * The GHashTable that's returned will free all log sets in it when
 * destroyed. If a PurpleLogSet is removed from the GHashTable, it
 * must be freed with purple_log_set_free().
 *
 * @return A GHashTable of all available unique PurpleLogSets
 */
GHashTable *purple_log_get_log_sets(void);

/**
 * Returns a list of all available system logs
 *
 * @param account The account
 * @return        A sorted list of PurpleLogs
 */
GList *purple_log_get_system_logs(PurpleAccount *account);

/**
 * Returns the size of a log
 *
 * @param log                 The log
 * @return                    The size of the log, in bytes
 */
int purple_log_get_size(PurpleLog *log);

/**
 * Returns the size, in bytes, of all available logs in this conversation
 *
 * @param type                The type of the log
 * @param name                The name of the log
 * @param account             The account
 * @return                    The size in bytes
 */
int purple_log_get_total_size(PurpleLogType type, const char *name, PurpleAccount *account);

/**
 * Returns the activity score of a log, based on total size in bytes,
 * which is then decayed based on age
 *
 * @param type                The type of the log
 * @param name                The name of the log
 * @param account             The account
 * @return                    The activity score
 *
 * @since 2.6.0
 */
int purple_log_get_activity_score(PurpleLogType type, const char *name, PurpleAccount *account);

/**
 * Tests whether a log is deletable
 *
 * A return value of @c FALSE indicates that purple_log_delete() will fail on this
 * log, unless something changes between the two calls.  A return value of @c TRUE,
 * however, does not guarantee the log can be deleted.
 *
 * @param log                 The log
 * @return                    A boolean indicating if the log is deletable
 */
gboolean purple_log_is_deletable(PurpleLog *log);

/**
 * Deletes a log
 *
 * @param log                 The log
 * @return                    A boolean indicating success or failure
 */
gboolean purple_log_delete(PurpleLog *log);

/**
 * Returns the default logger directory Purple uses for a given account
 * and username.  This would be where Purple stores logs created by
 * the built-in text or HTML loggers.
 *
 * @param type                The type of the log.
 * @param name                The name of the log.
 * @param account             The account.
 * @return                    The default logger directory for Purple.
 */
char *purple_log_get_log_dir(PurpleLogType type, const char *name, PurpleAccount *account);

/**
 * Implements GCompareFunc for PurpleLogs
 *
 * @param y                   A PurpleLog
 * @param z                   Another PurpleLog
 * @return                    A value as specified by GCompareFunc
 */
gint purple_log_compare(gconstpointer y, gconstpointer z);

/**
 * Implements GCompareFunc for PurpleLogSets
 *
 * @param y                   A PurpleLogSet
 * @param z                   Another PurpleLogSet
 * @return                    A value as specified by GCompareFunc
 */
gint purple_log_set_compare(gconstpointer y, gconstpointer z);

/**
 * Frees a log set
 *
 * @param set         The log set to destroy
 */
void purple_log_set_free(PurpleLogSet *set);

/*@}*/

/******************************************/
/** @name Common Logger Functions         */
/******************************************/
/*@{*/

/**
 * Opens a new log file in the standard Purple log location
 * with the given file extension, named for the current time,
 * for writing.  If a log file is already open, the existing
 * file handle is retained.  The log's logger_data value is
 * set to a PurpleLogCommonLoggerData struct containing the log
 * file handle and log path.
 *
 * This function is intended to be used as a "common"
 * implementation of a logger's @c write function.
 * It should only be passed to purple_log_logger_new() and never
 * called directly.
 *
 * @param log   The log to write to.
 * @param ext   The file extension to give to this log file.
 */
void purple_log_common_writer(PurpleLog *log, const char *ext);

/**
 * Returns a sorted GList of PurpleLogs of the requested type.
 *
 * This function should only be used with logs that are written
 * with purple_log_common_writer().  It's intended to be used as
 * a "common" implementation of a logger's @c list function.
 * It should only be passed to purple_log_logger_new() and never
 * called directly.
 *
 * @param type     The type of the logs being listed.
 * @param name     The name of the log.
 * @param account  The account of the log.
 * @param ext      The file extension this log format uses.
 * @param logger   A reference to the logger struct for this log.
 *
 * @return A sorted GList of PurpleLogs matching the parameters.
 */
GList *purple_log_common_lister(PurpleLogType type, const char *name,
							  PurpleAccount *account, const char *ext,
							  PurpleLogLogger *logger);

/**
 * Returns the total size of all the logs for a given user, with
 * a given extension.
 *
 * This function should only be used with logs that are written
 * with purple_log_common_writer().  It's intended to be used as
 * a "common" implementation of a logger's @c total_size function.
 * It should only be passed to purple_log_logger_new() and never
 * called directly.
 *
 * @param type     The type of the logs being sized.
 * @param name     The name of the logs to size
 *                 (e.g. the username or chat name).
 * @param account  The account of the log.
 * @param ext      The file extension this log format uses.
 *
 * @return The size of all the logs with the specified extension
 *         for the specified user.
 */
int purple_log_common_total_sizer(PurpleLogType type, const char *name,
								PurpleAccount *account, const char *ext);

/**
 * Returns the size of a given PurpleLog.
 *
 * This function should only be used with logs that are written
 * with purple_log_common_writer().  It's intended to be used as
 * a "common" implementation of a logger's @c size function.
 * It should only be passed to purple_log_logger_new() and never
 * called directly.
 *
 * @param log      The PurpleLog to size.
 *
 * @return An integer indicating the size of the log in bytes.
 */
int purple_log_common_sizer(PurpleLog *log);

/**
 * Deletes a log
 *
 * This function should only be used with logs that are written
 * with purple_log_common_writer().  It's intended to be used as
 * a "common" implementation of a logger's @c delete function.
 * It should only be passed to purple_log_logger_new() and never
 * called directly.
 *
 * @param log      The PurpleLog to delete.
 *
 * @return A boolean indicating success or failure.
 */
gboolean purple_log_common_deleter(PurpleLog *log);

/**
 * Checks to see if a log is deletable
 *
 * This function should only be used with logs that are written
 * with purple_log_common_writer().  It's intended to be used as
 * a "common" implementation of a logger's @c is_deletable function.
 * It should only be passed to purple_log_logger_new() and never
 * called directly.
 *
 * @param log      The PurpleLog to check.
 *
 * @return A boolean indicating if the log is deletable.
 */
gboolean purple_log_common_is_deletable(PurpleLog *log);

/*@}*/

/******************************************/
/** @name Logger Functions                */
/******************************************/
/*@{*/

/**
 * Creates a new logger
 *
 * @param id           The logger's id.
 * @param name         The logger's name.
 * @param functions    The number of functions being passed. The following
 *                     functions are currently available (in order): @c create,
 *                     @c write, @c finalize, @c list, @c read, @c size,
 *                     @c total_size, @c list_syslog, @c get_log_sets,
 *                     @c remove, @c is_deletable.
 *                     For details on these functions, see PurpleLogLogger.
 *                     Functions may not be skipped. For example, passing
 *                     @c create and @c write is acceptable (for a total of
 *                     two functions). Passing @c create and @c finalize,
 *                     however, is not. To accomplish that, the caller must
 *                     pass @c create, @c NULL (a placeholder for @c write),
 *                     and @c finalize (for a total of 3 functions).
 *
 * @return The new logger
 */
PurpleLogLogger *purple_log_logger_new(const char *id, const char *name, int functions, ...);

/**
 * Frees a logger
 *
 * @param logger       The logger to free
 */
void purple_log_logger_free(PurpleLogLogger *logger);

/**
 * Adds a new logger
 *
 * @param logger       The new logger to add
 */
void purple_log_logger_add (PurpleLogLogger *logger);

/**
 *
 * Removes a logger
 *
 * @param logger       The logger to remove
 */
void purple_log_logger_remove (PurpleLogLogger *logger);

/**
 *
 * Sets the current logger
 *
 * @param logger       The logger to set
 */
void purple_log_logger_set (PurpleLogLogger *logger);

/**
 *
 * Returns the current logger
 *
 * @return logger      The current logger
 */
PurpleLogLogger *purple_log_logger_get (void);

/**
 * Returns a GList containing the IDs and names of the registered
 * loggers.
 *
 * @return The list of IDs and names.
 */
GList *purple_log_logger_get_options(void);

/**************************************************************************/
/** @name Log Subsystem                                                   */
/**************************************************************************/
/*@{*/

/**
 * Initializes the log subsystem.
 */
void purple_log_init(void);

/**
 * Returns the log subsystem handle.
 *
 * @return The log subsystem handle.
 */
void *purple_log_get_handle(void);

/**
 * Uninitializes the log subsystem.
 */
void purple_log_uninit(void);

/*@}*/


#ifdef __cplusplus
}
#endif
