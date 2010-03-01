#pragma once

#include <purple.h>

namespace uiops
{
  struct blist
  {
    static void new_list (PurpleBuddyList* list);
    static void new_node (PurpleBlistNode* node);
    static void show (PurpleBuddyList* list);
    static void update (PurpleBuddyList* list, PurpleBlistNode* node);
    static void remove (PurpleBuddyList* list, PurpleBlistNode* node);
    static void destroy (PurpleBuddyList* list);
    static void set_visible (PurpleBuddyList* list, gboolean show);
    static void request_add_buddy (PurpleAccount* account, const char* username, const char* group, const char* alias);
    static void request_add_chat (PurpleAccount* account, PurpleGroup* group, const char* alias, const char* name);
    static void request_add_group (void);
    static void save_node (PurpleBlistNode* node);
    static void remove_node (PurpleBlistNode* node);
    static void save_account (PurpleAccount* account);

    static PurpleBlistUiOps create ();
  };
}
