#ifdef __cplusplus
extern "C" {
#endif

/**
 * Checks that the libpurple version is compatible with the requested
 * version
 *
 * @param required_major: the required major version.
 * @param required_minor: the required minor version.
 * @param required_micro: the required micro version.
 *
 * @return NULL if the versions are compatible, or a string describing
 *         the version mismatch if not compatible.
 */
const char *purple_version_check(guint required_major, guint required_minor, guint required_micro);

/**
 * The major version of the running libpurple.  Contrast with
 * #PURPLE_MAJOR_VERSION, which expands at compile time to the major version of
 * libpurple being compiled against.
 *
 * @since 2.4.0
 */
extern const guint purple_major_version;

/**
 * The minor version of the running libpurple.  Contrast with
 * #PURPLE_MINOR_VERSION, which expands at compile time to the minor version of
 * libpurple being compiled against.
 *
 * @since 2.4.0
 */
extern const guint purple_minor_version;

/**
 *
 * The micro version of the running libpurple.  Contrast with
 * #PURPLE_MICRO_VERSION, which expands at compile time to the micro version of
 * libpurple being compiled against.
 *
 * @since 2.4.0
 */
extern const guint purple_micro_version;

#ifdef __cplusplus
}
#endif
