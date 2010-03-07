# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.
AC_PREREQ(2.65)
AC_INIT([PurpleBee],[0.1],[purplebee@xinutec.org], [], [http://purplebee.xinutec.org])
AC_CONFIG_AUX_DIR(autoconf)
AC_CONFIG_SRCDIR(autoconf.h.in)
AC_CONFIG_MACRO_DIR(m4)
AC_CONFIG_HEADERS(autoconf.h)

AC_LANG(C++)

# libtool
LT_INIT([disable-static])
LT_LANG([C++])

# automake
AM_INIT_AUTOMAKE([silent-rules gnits])
AM_SILENT_RULES
AM_DEFAULT_VERBOSITY=0

# C++ feature requirements
CPPFLAGS="$CPPFLAGS -std=c++0x"
AC_MSG_CHECKING([for variadic template support])
AC_COMPILE_IFELSE(
   [AC_LANG_PROGRAM([[
      template<typename... Args>
      struct variadic;
   ]])],
   [AC_MSG_RESULT([yes])],
   [AC_MSG_ERROR([your compiler does not support C++ variadic templates])]
)

AC_MSG_CHECKING([for lambda expression support])
AC_COMPILE_IFELSE(
   [AC_LANG_PROGRAM([[
      auto lambda = [](char const* msg) { };
      void test () {
         lambda ("Hello");
      }
   ]])],
   [AC_MSG_RESULT([yes])
    AC_DEFINE([HAVE_LAMBDA], 1, [Define if your compiler supports C++ lambda expressions])
   ],
   [AC_MSG_RESULT([no])]
)

# C++ library requirements
AC_CHECK_HEADERS([tuple unordered_map type_traits boost/bimap.hpp])

# debugging
AC_CHECK_HEADERS([valgrind/valgrind.h valgrind/memcheck.h bfd.h execinfo.h])

# argument parsing
AC_CHECK_HEADER([argtable2.h], [], [AC_MSG_ERROR([You need to have libargtable2-dev installed])])

# pkg-config
AC_PATH_PROG(PKG_CONFIG, pkg-config, no)

# libpurple
AC_MSG_CHECKING(purple >= 0.22)
if $PKG_CONFIG purple --atleast-version 0.22; then
   CXXFLAGS="$CXXFLAGS `$PKG_CONFIG purple --cflags`"
   LIBS="$LIBS `$PKG_CONFIG purple --libs`"
   AC_MSG_RESULT(ok)
else
   AC_MSG_ERROR(no)
fi

# perl
AC_PATH_PROG(PERL, perl5.10.1)
if test -z "$PERL"; then
   AC_PATH_PROG(PERL, perl5.10.0)
   if test -z "$PERL"; then
      AC_PATH_PROG(PERL, perl)
      if test -z "$PERL"; then
         AC_MSG_ERROR([perl 5.10 or higher must be in your PATH, check the README])
      fi
   fi
fi

for module_vers in		\
   "AnyEvent 5.2"		\
   "common::sense 3.0"		\
; do
   set -- $module_vers
   module=$1
   minvers=$2
   AC_MSG_CHECKING(for $module perl module version $minvers or higher)
   if $PERL -M$module -e0 >/dev/null 2>&1; then
      version=`$PERL -M$module -e "print \\$$module::VERSION"`
      if $PERL -M$module -e "\$$module::VERSION >= $minvers or die" >/dev/null 2>&1; then
         AC_MSG_RESULT([ok, version $version])
      else
         AC_MSG_ERROR([no, installed version is $version])
      fi
   else
      AC_MSG_ERROR([no, cannot load module $module])
   fi
done

# libperl
AC_MSG_CHECKING(for $PERL suitability)
if $PERL -MExtUtils::Embed -e "use 5.10.0" >/dev/null 2>&1; then
  save_CXXFLAGS="$CXXFLAGS"
  save_LIBS="$LIBS"
  xPERLFLAGS="`$PERL -MExtUtils::Embed -e ccopts`"
  CXXFLAGS="$CXXFLAGS $xPERLFLAGS"
  LIBS="$LIBS `$PERL -MExtUtils::Embed -e ldopts`"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[
#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>
]], [[
  PerlInterpreter *perl = perl_alloc ();
]])],[perl_link=yes],[perl_link=no])
  CXXFLAGS="$save_CXXFLAGS"
  LIBS="$save_LIBS"

  if test x$perl_link = xyes; then
     AC_MSG_RESULT(ok)
     PERLFLAGS="$xPERLFLAGS"
     PERLLIB="`$PERL -MExtUtils::Embed -e ldopts`"
     PERLPRIVLIBEXP="`$PERL -MConfig -e 'print $Config{privlibexp}'`"
     CPPFLAGS="$CPPFLAGS $PERLFLAGS"
  else
     AC_MSG_ERROR([no, unable to link test program])
  fi
else
  AC_MSG_ERROR([no working perl found, or perl not version >= 5.10])
fi
AC_SUBST(PERLLIB)
AC_SUBST(PERLFLAGS)
AC_SUBST(PERLPRIVLIBEXP)
AC_SUBST(PERL)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
