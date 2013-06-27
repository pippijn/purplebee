/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

namespace uiops
{
  struct account
  {
    static void notify_added (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message);
    static void status_changed (PurpleAccount* account, PurpleStatus* status);
    static void request_add (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message);
    static void* request_authorize (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message, gboolean on_list, PurpleAccountRequestAuthorizationCb authorize_cb, PurpleAccountRequestAuthorizationCb deny_cb, void* user_data);
    static void close_account_request (void* ui_handle);

    static PurpleAccountUiOps create ();
    static void destroy (PurpleAccountUiOps& ops);
  };
}
