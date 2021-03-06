/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/blist.h"

#define OPS "UiOps::Blist::"

namespace uiops
{
  void
  blist::new_list (PurpleBuddyList* list)
  {
    return perl_call<void> (OPS "new_list", list);
  }

  void
  blist::new_node (PurpleBlistNode* node)
  {
    return perl_call<void> (OPS "new_node", node);
  }

  void
  blist::show (PurpleBuddyList* list)
  {
    return perl_call<void> (OPS "show", list);
  }

  void
  blist::update (PurpleBuddyList* list, PurpleBlistNode* node)
  {
    return perl_call<void> (OPS "update", list, node);
  }

  void
  blist::remove (PurpleBuddyList* list, PurpleBlistNode* node)
  {
    return perl_call<void> (OPS "remove", list, node);
  }

  void
  blist::destroy (PurpleBuddyList* list)
  {
    return perl_call<void> (OPS "destroy", list);
  }

  void
  blist::set_visible (PurpleBuddyList* list, gboolean show)
  {
    return perl_call<void> (OPS "set_visible", list, show);
  }

  void
  blist::request_add_buddy (PurpleAccount* account, char const* username, char const* group, char const* alias)
  {
    return perl_call<void> (OPS "request_add_buddy", account, username, group, alias);
  }

  void
  blist::request_add_chat (PurpleAccount* account, PurpleGroup* group, char const* alias, char const* name)
  {
    return perl_call<void> (OPS "request_add_chat", account, group, alias, name);
  }

  void
  blist::request_add_group (void)
  {
    return perl_call<void> (OPS "request_add_group");
  }

  void
  blist::save_node (PurpleBlistNode* node)
  {
    return perl_call<void> (OPS "save_node", node);
  }

  void
  blist::remove_node (PurpleBlistNode* node)
  {
    return perl_call<void> (OPS "remove_node", node);
  }

  void
  blist::save_account (PurpleAccount* account)
  {
    return perl_call<void> (OPS "save_account", account);
  }

  PurpleBlistUiOps
  blist::create ()
  {
    return {
      new_list,
      new_node,
      show,
      update,
      remove,
      destroy,
      set_visible,
      request_add_buddy,
      request_add_chat,
      request_add_group,
      save_node,
      remove_node,
      save_account,

      // reserved
      NULL,
    };
  }

  void
  blist::destroy (G_GNUC_UNUSED PurpleBlistUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying blist callbacks");
  }
}
