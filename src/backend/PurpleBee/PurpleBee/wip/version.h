char const*
purple_version_check (guint required_major, guint required_minor, guint required_micro);

guint
purple_major_version ()
    CODE:       RETVAL = purple_major_version;
    OUTPUT:     RETVAL

guint
purple_minor_version ()
    CODE:       RETVAL = purple_minor_version;
    OUTPUT:     RETVAL

guint
purple_micro_version ()
    CODE:       RETVAL = purple_micro_version;
    OUTPUT:     RETVAL
