/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

namespace uiops
{
  struct roomlist
  {
    static void show_with_account (PurpleAccount* account);
    static void create (PurpleRoomlist* list);
    static void set_fields (PurpleRoomlist* list, GList* fields);
    static void add_room (PurpleRoomlist* list, PurpleRoomlistRoom* room);
    static void in_progress (PurpleRoomlist* list, gboolean flag);
    static void destroy (PurpleRoomlist* list);

    static PurpleRoomlistUiOps create ();
    static void destroy (PurpleRoomlistUiOps& ops);
  };
}
