/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#include <purple.h>

#include "common/debug/backtrace.h"
#include "common/perl/util.h"
#include "common/util/preprocessor.h"

#include "backend/PurpleBee.h"
#include "backend/PurpleBee/Closure.h"
#include "backend/PurpleBee/callbacks.h"

#define const_val(value)                                                \
  if (0)                                                                \
  printf ( "newCONSTSUB (%s, %d)\n"                                     \
         , STRINGIZE (TYPE) #value                                      \
         , PASTE3 (PURPLE_, TYPE, value)                                \
         );                                                             \
  newCONSTSUB                                                           \
    ( perl_package<decltype (PASTE3 (PURPLE_, TYPE, value))>::stash     \
    , #value                                                            \
    , server->to_sv (PASTE3 (PURPLE_, TYPE, value))                     \
    )

MODULE = PurpleBee      PACKAGE = PurpleBee

BOOT:
    server->boot ();

void
PurpleBee::print_backtrace ()
    CODE:
{
#if HAVE_LAMBDA
    print_backtrace ([](char const* msg) { purple_debug_info ("backtrace", "%s", msg); });
#else
    print_backtrace ();
#endif
}

char const*
PurpleBee::package ()

void
PurpleBee::valgrind (bool full = false)

void
PurpleBee::fault (int kind = 0)

#INCLUDE: PurpleBee/wip/blist.h
#INCLUDE: PurpleBee/wip/conversation.h
#INCLUDE: PurpleBee/wip/core.h
#INCLUDE: PurpleBee/wip/pounce.h
#INCLUDE: PurpleBee/wip/proxy.h
#INCLUDE: PurpleBee/wip/util.h
#INCLUDE: PurpleBee/wip/version.h

INCLUDE: PurpleBee/Closure.xs

INCLUDE: PurpleBee/Account/Option.xs
INCLUDE: PurpleBee/Account/UserSplit.xs
INCLUDE: PurpleBee/Account.xs
INCLUDE: PurpleBee/Accounts.xs
INCLUDE: PurpleBee/Buddy/Icon.xs
INCLUDE: PurpleBee/Buddy/Icons.xs
INCLUDE: PurpleBee/Buddy.xs
INCLUDE: PurpleBee/BuddyList.xs
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
INCLUDE: PurpleBee/NTLM.xs
INCLUDE: PurpleBee/Network.xs
INCLUDE: PurpleBee/Notify.xs
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
INCLUDE: PurpleBee/Status/Attr.xs
INCLUDE: PurpleBee/Status/Primitive.xs
INCLUDE: PurpleBee/Status/Type.xs
INCLUDE: PurpleBee/Status.xs
INCLUDE: PurpleBee/StoredImage.xs
INCLUDE: PurpleBee/Stringref.xs
INCLUDE: PurpleBee/Value.xs
INCLUDE: PurpleBee/Whiteboard.xs
INCLUDE: PurpleBee/Xfer.xs
INCLUDE: PurpleBee/Xfers.xs
