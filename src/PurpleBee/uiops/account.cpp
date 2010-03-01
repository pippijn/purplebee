#include "PurpleBee.h"
#include "uiops/account.h"
#include "util/make_closure.h"

#define OPS "Ops::Account::"

namespace uiops
{
  void
  account::notify_added (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message)
  {
    return server->call<void> (OPS "notify_added", account, remote_user, id, alias, message);
  }

  void
  account::status_changed (PurpleAccount* account, PurpleStatus* status)
  {
    return server->call<void> (OPS "status_changed", account, status);
  }

  void
  account::request_add (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message)
  {
    return server->call<void> (OPS "request_add", account, remote_user, id, alias, message);
  }

  void*
  account::request_authorize (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message, gboolean on_list, PurpleAccountRequestAuthorizationCb authorize_cb, PurpleAccountRequestAuthorizationCb deny_cb, void* user_data)
  {
    return server->call<void*> (OPS "request_authorize", account, remote_user, id, alias, message, on_list, make_closure (authorize_cb, user_data), make_closure (deny_cb, user_data), user_data);
  }

  void
  account::close_account_request (void* ui_handle)
  {
    return server->call<void> (OPS "close_account_request", ui_handle);
  }

  PurpleAccountUiOps
  account::create ()
  {
    return {
      notify_added,
      status_changed,
      request_add,
      request_authorize,
      close_account_request,
    };
  }
}
