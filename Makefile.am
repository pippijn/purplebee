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

OPTFLAGS		= -pipe -O2 -ggdb3
WARNINGS		= # empty
#WARNINGS		+= -Wall -Wextra
#WARNINGS		+= -Wno-unused-parameter
#WARNINGS		+= -Wpadded
#WARNINGS		+= -Wpacked
#WARNINGS		+= -Wconversion
#WARNINGS		+= -Wstrict-overflow=5
#WARNINGS		+= -Wstrict-aliasing=1
#WARNINGS		+= -Werror

AM_CFLAGS		= $(OPTFLAGS) $(WARNINGS)
AM_CXXFLAGS		= $(OPTFLAGS) $(WARNINGS)
AM_CPPFLAGS		= -I$(srcdir)/include -I$(builddir)/include -DDATADIR='"$(datadir)"'
AM_LDFLAGS		= -Wl,-z,defs,-z,noexecstack,-z,now

include src/Rules.am

-include prepare
prepare:	
