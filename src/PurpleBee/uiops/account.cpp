#include "PurpleBee.h"
#include "uiops/account.h"

#define OPS "Ops::Account::"

namespace uiops
{
  void
  account::notify_added (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message)
  {
  }

  void
  account::status_changed (PurpleAccount* account, PurpleStatus* status)
  {
  }

  void
  account::request_add (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message)
  {
  }

  void*
  account::request_authorize (PurpleAccount* account, const char* remote_user, const char* id, const char* alias, const char* message, gboolean on_list, PurpleAccountRequestAuthorizationCb authorize_cb, PurpleAccountRequestAuthorizationCb deny_cb, void* user_data)
  {
  }

  void
  account::close_account_request (void* ui_handle)
  {
  }

  PurpleAccountUiOps
  account::create ()
  {
  }
}
