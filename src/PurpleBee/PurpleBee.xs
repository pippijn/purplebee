#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#include <purple.h>

#include "PurpleBee.h"
#include "PurpleBee/stash.h"

template<typename T>
static void
const_val (HV* stash, char const* name, T v)
{
  newCONSTSUB (stash, (char*)name, server->to_sv (v));
}

#include "PurpleBee/Callback.h"

MODULE = PurpleBee      PACKAGE = PurpleBee

BOOT:
{
    stash::PurpleBee             = gv_stashpv ("PurpleBee", 1);
    stash::Callback              = gv_stashpv ("PurpleBee::Callback", 1);
#define PTYPE(T) \
    stash::PASTE (PurpleBee_, T) = gv_stashpv ("PurpleBee::" STRINGIZE (T), 1);
#include "PurpleBee/types.h"
#define const_val(value) const_val (stash::PurpleBee, #value, value)
    const_val (PACKAGE);
    const_val (PACKAGE_BUGREPORT);
    const_val (PACKAGE_NAME);
    const_val (PACKAGE_STRING);
    const_val (PACKAGE_TARNAME);
    const_val (PACKAGE_URL);
    const_val (PACKAGE_VERSION);

    const_val (BINDIR);
    const_val (SBINDIR);
    const_val (LIBEXECDIR);
    const_val (DATAROOTDIR);
    const_val (DATADIR);
    const_val (SYSCONFDIR);
    const_val (SHAREDSTATEDIR);
    const_val (LOCALSTATEDIR);
    const_val (INCLUDEDIR);
    const_val (OLDINCLUDEDIR);
    const_val (DOCDIR);
    const_val (INFODIR);
    const_val (HTMLDIR);
    const_val (DVIDIR);
    const_val (PDFDIR);
    const_val (PSDIR);
    const_val (LIBDIR);
    const_val (LOCALEDIR);
    const_val (MANDIR);
#undef const_val
}

INCLUDE: PurpleBee/wip/account.h
INCLUDE: PurpleBee/wip/accountopt.h
INCLUDE: PurpleBee/wip/blist.h
INCLUDE: PurpleBee/wip/buddyicon.h
INCLUDE: PurpleBee/wip/certificate.h
INCLUDE: PurpleBee/wip/cipher.h
INCLUDE: PurpleBee/wip/cmds.h
INCLUDE: PurpleBee/wip/connection.h
INCLUDE: PurpleBee/wip/conversation.h
INCLUDE: PurpleBee/wip/core.h
INCLUDE: PurpleBee/wip/debug.h
INCLUDE: PurpleBee/wip/dnsquery.h
INCLUDE: PurpleBee/wip/dnssrv.h
INCLUDE: PurpleBee/wip/eventloop.h
INCLUDE: PurpleBee/wip/ft.h
INCLUDE: PurpleBee/wip/idle.h
INCLUDE: PurpleBee/wip/imgstore.h
INCLUDE: PurpleBee/wip/log.h
INCLUDE: PurpleBee/wip/mime.h
INCLUDE: PurpleBee/wip/network.h
INCLUDE: PurpleBee/wip/notify.h
INCLUDE: PurpleBee/wip/ntlm.h
INCLUDE: PurpleBee/wip/pounce.h
INCLUDE: PurpleBee/wip/prefs.h
INCLUDE: PurpleBee/wip/privacy.h
INCLUDE: PurpleBee/wip/proxy.h
INCLUDE: PurpleBee/wip/request.h
INCLUDE: PurpleBee/wip/roomlist.h
INCLUDE: PurpleBee/wip/savedstatuses.h
INCLUDE: PurpleBee/wip/smiley.h
INCLUDE: PurpleBee/wip/sound.h
INCLUDE: PurpleBee/wip/sound-theme.h
INCLUDE: PurpleBee/wip/sslconn.h
INCLUDE: PurpleBee/wip/status.h
INCLUDE: PurpleBee/wip/stringref.h
INCLUDE: PurpleBee/wip/util.h
INCLUDE: PurpleBee/wip/value.h
INCLUDE: PurpleBee/wip/version.h
INCLUDE: PurpleBee/wip/whiteboard.h

INCLUDE: PurpleBee/Callback.xs
