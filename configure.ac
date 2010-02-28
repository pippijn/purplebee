AC_PREREQ(2.61)
AC_INIT([PurpleBee], [0.1], [purplebee@xinutec.org])
AC_CONFIG_AUX_DIR(autoconf)
AC_CONFIG_SRCDIR(autoconf.h.in)
AC_CONFIG_MACRO_DIR(m4)
AC_CONFIG_HEADERS(autoconf.h)

# automake
LT_INIT
AM_INIT_AUTOMAKE([silent-rules gnits])
AM_SILENT_RULES
AM_DEFAULT_VERBOSITY=0

# build tools
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
