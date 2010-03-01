#include "PurpleBee.h"
#include "uiops/roomlist.h"

#define OPS "Ops::Roomlist::"

namespace uiops
{
  void
  roomlist::show_with_account (PurpleAccount* account)
  {
    return server->call<void> (OPS "show_with_account", account);
  }

  void
  roomlist::create (PurpleRoomlist* list)
  {
    return server->call<void> (OPS "create", list);
  }

  void
  roomlist::set_fields (PurpleRoomlist* list, GList* fields)
  {
    return server->call<void> (OPS "set_fields", list, fields);
  }

  void
  roomlist::add_room (PurpleRoomlist* list, PurpleRoomlistRoom* room)
  {
    return server->call<void> (OPS "add_room", list, room);
  }

  void
  roomlist::in_progress (PurpleRoomlist* list, gboolean flag)
  {
    return server->call<void> (OPS "in_progress", list, flag);
  }

  void
  roomlist::destroy (PurpleRoomlist* list)
  {
    return server->call<void> (OPS "destroy", list);
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
    };
  }
}
