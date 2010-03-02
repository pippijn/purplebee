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
#define PTYPE(T, P) \
    stash::PASTE (PurpleBee_, T) = gv_stashpv ("PurpleBee::" P, 1);
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

char const*
PurpleBee::package ()
    CODE:
    RETVAL = THIS->package ();
    OUTPUT:
    RETVAL

#INCLUDE: PurpleBee/wip/blist.h
#INCLUDE: PurpleBee/wip/conversation.h
#INCLUDE: PurpleBee/wip/core.h
#INCLUDE: PurpleBee/wip/pounce.h
#INCLUDE: PurpleBee/wip/proxy.h
#INCLUDE: PurpleBee/wip/util.h
#INCLUDE: PurpleBee/wip/version.h

INCLUDE: PurpleBee/Callback.xs

INCLUDE: PurpleBee/Account/Option.xs
INCLUDE: PurpleBee/Account/UserSplit.xs
INCLUDE: PurpleBee/Account.xs
INCLUDE: PurpleBee/Accounts.xs
INCLUDE: PurpleBee/Buddy/Icon.xs
INCLUDE: PurpleBee/Buddy/Icons.xs
INCLUDE: PurpleBee/Buddy/List.xs
INCLUDE: PurpleBee/Buddy.xs
INCLUDE: PurpleBee/Certificate.xs
INCLUDE: PurpleBee/Chat.xs
INCLUDE: PurpleBee/Cipher.xs
INCLUDE: PurpleBee/Ciphers.xs
INCLUDE: PurpleBee/Cmd.xs
INCLUDE: PurpleBee/Cmds.xs
INCLUDE: PurpleBee/Connection.xs
INCLUDE: PurpleBee/Connections.xs
INCLUDE: PurpleBee/Contact.xs
INCLUDE: PurpleBee/Conversation/Chat.xs
INCLUDE: PurpleBee/Conversation/Im.xs
INCLUDE: PurpleBee/Conversation.xs
INCLUDE: PurpleBee/Conversations.xs
INCLUDE: PurpleBee/Core.xs
INCLUDE: PurpleBee/Debug.xs
INCLUDE: PurpleBee/DnsQuery.xs
INCLUDE: PurpleBee/EventLoop.xs
INCLUDE: PurpleBee/Group.xs
INCLUDE: PurpleBee/Idle.xs
INCLUDE: PurpleBee/Log.xs
INCLUDE: PurpleBee/Mime/Document.xs
INCLUDE: PurpleBee/Mime/Part.xs
INCLUDE: PurpleBee/Network.xs
INCLUDE: PurpleBee/Notify.xs
INCLUDE: PurpleBee/NTLM.xs
INCLUDE: PurpleBee/Pounce.xs
INCLUDE: PurpleBee/Pounces.xs
INCLUDE: PurpleBee/Prefs.xs
INCLUDE: PurpleBee/Presence.xs
INCLUDE: PurpleBee/Privacy.xs
INCLUDE: PurpleBee/Proxy.xs
INCLUDE: PurpleBee/Request/Field.xs
INCLUDE: PurpleBee/Request/Fields.xs
INCLUDE: PurpleBee/Request.xs
INCLUDE: PurpleBee/Roomlist/Field.xs
INCLUDE: PurpleBee/Roomlist/Room.xs
INCLUDE: PurpleBee/Roomlist.xs
INCLUDE: PurpleBee/SavedStatus.xs
INCLUDE: PurpleBee/SavedStatuses.xs
INCLUDE: PurpleBee/Smiley.xs
INCLUDE: PurpleBee/Smileys.xs
INCLUDE: PurpleBee/Sound/Theme.xs
INCLUDE: PurpleBee/Sound.xs
INCLUDE: PurpleBee/Sounds.xs
INCLUDE: PurpleBee/Ssl/Connection.xs
INCLUDE: PurpleBee/Ssl.xs
INCLUDE: PurpleBee/Status/Primitive.xs
INCLUDE: PurpleBee/Status.xs
INCLUDE: PurpleBee/StoredImage.xs
INCLUDE: PurpleBee/Stringref.xs
INCLUDE: PurpleBee/Value.xs
INCLUDE: PurpleBee/Whiteboard.xs
INCLUDE: PurpleBee/Xfer.xs
INCLUDE: PurpleBee/Xfers.xs
