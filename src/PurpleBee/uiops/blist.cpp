#include "PurpleBee.h"
#include "uiops/blist.h"

#define OPS "Ops::Blist::"

namespace uiops
{
  void
  blist::new_list (PurpleBuddyList* list)
  {
    return server->call<void> (OPS "new_list", list);
  }

  void
  blist::new_node (PurpleBlistNode* node)
  {
    return server->call<void> (OPS "new_node", node);
  }

  void
  blist::show (PurpleBuddyList* list)
  {
    return server->call<void> (OPS "show", list);
  }

  void
  blist::update (PurpleBuddyList* list, PurpleBlistNode* node)
  {
    return server->call<void> (OPS "update", list, node);
  }

  void
  blist::remove (PurpleBuddyList* list, PurpleBlistNode* node)
  {
    return server->call<void> (OPS "remove", list, node);
  }

  void
  blist::destroy (PurpleBuddyList* list)
  {
    return server->call<void> (OPS "destroy", list);
  }

  void
  blist::set_visible (PurpleBuddyList* list, gboolean show)
  {
    return server->call<void> (OPS "set_visible", list, show);
  }

  void
  blist::request_add_buddy (PurpleAccount* account, const char* username, const char* group, const char* alias)
  {
    return server->call<void> (OPS "request_add_buddy", account, username, group, alias);
  }

  void
  blist::request_add_chat (PurpleAccount* account, PurpleGroup* group, const char* alias, const char* name)
  {
    return server->call<void> (OPS "request_add_chat", account, group, alias, name);
  }

  void
  blist::request_add_group (void)
  {
    return server->call<void> (OPS "request_add_group");
  }

  void
  blist::save_node (PurpleBlistNode* node)
  {
    return server->call<void> (OPS "save_node", node);
  }

  void
  blist::remove_node (PurpleBlistNode* node)
  {
    return server->call<void> (OPS "remove_node", node);
  }

  void
  blist::save_account (PurpleAccount* account)
  {
    return server->call<void> (OPS "save_account", account);
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
    };
  }
}
