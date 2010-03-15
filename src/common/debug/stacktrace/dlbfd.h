#if DLBFD
# define bfd_init                       dbfd.init
# define bfd_map_over_sections          dbfd.map_over_sections
# define bfd_check_format               dbfd.check_format
# define bfd_check_format_matches       dbfd.check_format_matches
# define bfd_openr                      dbfd.openr
# define bfd_close                      dbfd.close
#endif
