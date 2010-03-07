/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/roomlist.h"

#define OPS "UiOps::Roomlist::"

namespace uiops
{
  void
  roomlist::show_with_account (PurpleAccount* account)
  {
    return perl_call<void> (OPS "show_with_account", account);
  }

  void
  roomlist::create (PurpleRoomlist* list)
  {
    return perl_call<void> (OPS "create", list);
  }

  void
  roomlist::set_fields (PurpleRoomlist* list, GList* fields)
  {
    return perl_call<void> (OPS "set_fields", list, fields);
  }

  void
  roomlist::add_room (PurpleRoomlist* list, PurpleRoomlistRoom* room)
  {
    return perl_call<void> (OPS "add_room", list, room);
  }

  void
  roomlist::in_progress (PurpleRoomlist* list, gboolean flag)
  {
    return perl_call<void> (OPS "in_progress", list, flag);
  }

  void
  roomlist::destroy (PurpleRoomlist* list)
  {
    return perl_call<void> (OPS "destroy", list);
  }

  PurpleRoomlistUiOps
  roomlist::create ()
  {
    return {
      show_with_account,
      create,
      set_fields,
      add_room,
      in_progress,
      destroy,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }
}
