/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/account.h"
#include "common/util/make_closure.h"

#define OPS "UiOps::Account::"

namespace uiops
{
  void
  account::notify_added ( PurpleAccount* account
                        , char const* remote_user
                        , char const* id
                        , char const* alias
                        , char const* message
                        )
  {
    return perl_call<void> (OPS "notify_added", account, remote_user, id, alias, message);
  }

  void
  account::status_changed ( PurpleAccount* account
                          , PurpleStatus* status
                          )
  {
    return perl_call<void> ( OPS "status_changed"
                           , account
                           , status
                           );
  }

  void
  account::request_add ( PurpleAccount* account
                       , char const* remote_user
                       , char const* id
                       , char const* alias
                       , char const* message
                       )
  {
    return perl_call<void> (OPS "request_add", account, remote_user, id, alias, message);
  }

  void*
  account::request_authorize ( PurpleAccount* account
                             , char const* remote_user
                             , char const* id
                             , char const* alias
                             , char const* message
                             , gboolean on_list
                             , PurpleAccountRequestAuthorizationCb authorize_cb
                             , PurpleAccountRequestAuthorizationCb deny_cb
                             , void* user_data
                             )
  {
    return perl_call<SV*> ( OPS "request_authorize"
                          , account
                          , remote_user
                          , id
                          , alias
                          , message
                          , on_list
                          , make_closure (authorize_cb, user_data)
                          , make_closure (deny_cb, user_data)
                          );
  }

  void
  account::close_account_request (void* ui_handle)
  {
    return perl_call<void> (OPS "close_account_request", (SV*)ui_handle);
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

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }

  void
  account::destroy (G_GNUC_UNUSED PurpleAccountUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying account callbacks");
  }
}
