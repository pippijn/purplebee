# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.
AUTOMAKE_OPTIONS	= -Wall
ACLOCAL_AMFLAGS		= -I m4

lib_LTLIBRARIES		= # empty
bin_PROGRAMS		= # empty
data_DATA		= # empty

BUILT_SOURCES		= # empty

EXTRA_DIST		= # empty

CLEANFILES		= # empty
DISTCLEANFILES		= # empty
MAINTAINERCLEANFILES	= # empty

OPTFLAGS		= -pipe -O3 -ggdb3
WARNINGS		= # empty
WARNINGS		+= -Wall -Wextra
WARNINGS		+= -Wpadded
WARNINGS		+= -Wpacked
#WARNINGS		+= -Wconversion
WARNINGS		+= -Wstrict-overflow=5
WARNINGS		+= -Wstrict-aliasing=1
WARNINGS		+= -Werror
WARNINGS		+= -Wno-error=padded
WARNINGS		+= -Wno-error=write-strings

AM_CFLAGS		= $(OPTFLAGS) $(WARNINGS)
AM_CXXFLAGS		= $(OPTFLAGS) $(WARNINGS) -std=c++0x
AM_CPPFLAGS		= -I$(srcdir)/include -I$(builddir)/include -include autoconf.h
AM_CPPFLAGS		+= -isystem /usr/lib/perl/5.10/CORE
AM_CPPFLAGS		+= -isystem /usr/lib/perl5/core_perl/CORE
AM_CPPFLAGS		+= -isystem /usr/include/libpurple
AM_LDFLAGS		= -Wl,-z,defs,-z,noexecstack,-z,now

AM_CPPFLAGS		+= -DBINDIR='"$(bindir)"'
AM_CPPFLAGS		+= -DSBINDIR='"$(sbindir)"'
AM_CPPFLAGS		+= -DLIBEXECDIR='"$(libexecdir)"'
AM_CPPFLAGS		+= -DDATAROOTDIR='"$(datarootdir)"'
AM_CPPFLAGS		+= -DDATADIR='"$(datadir)"'
AM_CPPFLAGS		+= -DSYSCONFDIR='"$(sysconfdir)"'
AM_CPPFLAGS		+= -DSHAREDSTATEDIR='"$(sharedstatedir)"'
AM_CPPFLAGS		+= -DLOCALSTATEDIR='"$(localstatedir)"'
AM_CPPFLAGS		+= -DINCLUDEDIR='"$(includedir)"'
AM_CPPFLAGS		+= -DOLDINCLUDEDIR='"$(oldincludedir)"'
AM_CPPFLAGS		+= -DDOCDIR='"$(docdir)"'
AM_CPPFLAGS		+= -DINFODIR='"$(infodir)"'
AM_CPPFLAGS		+= -DHTMLDIR='"$(htmldir)"'
AM_CPPFLAGS		+= -DDVIDIR='"$(dvidir)"'
AM_CPPFLAGS		+= -DPDFDIR='"$(pdfdir)"'
AM_CPPFLAGS		+= -DPSDIR='"$(psdir)"'
AM_CPPFLAGS		+= -DLIBDIR='"$(libdir)"'
AM_CPPFLAGS		+= -DLOCALEDIR='"$(localedir)"'
AM_CPPFLAGS		+= -DMANDIR='"$(mandir)"'

include src/Rules.am

-include prepare
prepare:	
