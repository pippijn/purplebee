/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/marshal.h"
#include "common/util/va_list_unpack0.h"
#include "common/util/va_list_unpackN.h"

#include "backend/PurpleBee/callbacks.h"
#include "backend/PurpleBee/make_closure.h"
#include "backend/PurpleBee/make_closure_each.h"
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/request.h"

#define OPS "UiOps::Request::"

namespace uiops
{
  void*
  request::request_input ( char const* title
                         , char const* primary
                         , char const* secondary
                         , char const* default_value
                         , gboolean multiline
                         , gboolean masked
                         , gchar* hint
                         , char const* ok_text
                         , GCallback ok_cb
                         , char const* cancel_text
                         , GCallback cancel_cb
                         , PurpleAccount* account
                         , char const* who
                         , PurpleConversation* conv
                         , void* user_data
                         )
  {
    return perl_call<handle> ( OPS "request_input"
                             , title
                             , primary
                             , secondary
                             , default_value
                             , multiline
                             , masked
                             , hint
                             , ok_text
                             , make_closure<1> (PurpleRequestInputCb (ok_cb), user_data, (char const*)0)
                             , cancel_text
                             , make_closure<1> (PurpleRequestInputCb (cancel_cb), user_data, (char const*)0)
                             , account
                             , who
                             , conv
                             );
  }

  void*
  request::request_choice ( char const* title
                          , char const* primary
                          , char const* secondary
                          , int default_value
                          , char const* ok_text
                          , GCallback ok_cb
                          , char const* cancel_text
                          , GCallback cancel_cb
                          , PurpleAccount* account
                          , char const* who
                          , PurpleConversation* conv
                          , void* user_data
                          , va_list choices
                          )
  {
    return perl_call<handle> ( OPS "request_choice"
                             , title
                             , primary
                             , secondary
                             , default_value
                             , ok_text
                             , make_closure<1> (PurpleRequestChoiceCb (ok_cb), user_data, 0)
                             , cancel_text
                             , make_closure<1> (PurpleRequestChoiceCb (cancel_cb), user_data, 0)
                             , account
                             , who
                             , conv
                             , wrap_va_list<char const*, int> (choices).unpack ()
                             );
  }

  void*
  request::request_action ( char const* title
                          , char const* primary
                          , char const* secondary
                          , int default_action
                          , PurpleAccount* account
                          , char const* who
                          , PurpleConversation* conv
                          , void* user_data
                          , size_t action_count
                          , va_list actions
                          )
  {
    auto va_wrap = wrap_va_list<size_t, char const*, PurpleRequestActionCb>
                      ( action_count
                      , actions
                      );
    return perl_call<handle> ( OPS "request_action"
                             , title
                             , primary
                             , secondary
                             , default_action
                             , account
                             , who
                             , conv
                             , va_wrap.unpack<0> ()
                             , make_closure_each<1>
                                  ( va_wrap.unpack<1> ()
                                  , user_data
                                  , 0
                                  )
                             );
  }

  void*
  request::request_fields ( char const* title
                          , char const* primary
                          , char const* secondary
                          , PurpleRequestFields* fields
                          , char const* ok_text
                          , GCallback ok_cb
                          , char const* cancel_text
                          , GCallback cancel_cb
                          , PurpleAccount* account
                          , char const* who
                          , PurpleConversation* conv
                          , void* user_data
                          )
  {
    return perl_call<handle> ( OPS "request_fields"
                             , title
                             , primary
                             , secondary
                             , fields
                             , ok_text
                             , make_closure<1> (PurpleRequestFieldsCb (ok_cb), user_data, (PurpleRequestFields*)0)
                             , cancel_text
                             , make_closure<1> (PurpleRequestFieldsCb (cancel_cb), user_data, (PurpleRequestFields*)0)
                             , account
                             , who
                             , conv
                             );
  }

  void*
  request::request_file ( char const* title
                        , char const* filename
                        , gboolean savedialog
                        , GCallback ok_cb
                        , GCallback cancel_cb
                        , PurpleAccount* account
                        , char const* who
                        , PurpleConversation* conv
                        , void* user_data
                        )
  {
    return perl_call<handle> ( OPS "request_file"
                             , title
                             , filename
                             , savedialog
                             , make_closure<1> (PurpleRequestFileCb (ok_cb), user_data, (char const*)0)
                             , make_closure<1> (PurpleRequestFileCb (cancel_cb), user_data, (char const*)0)
                             , account
                             , who
                             , conv
                             );
  }

  void
  request::close_request (PurpleRequestType type, void* ui_handle)
  {
    return perl_call<void> (OPS "close_request", type, handle (ui_handle));
  }

  void*
  request::request_folder ( char const* title
                          , char const* dirname
                          , GCallback ok_cb
                          , GCallback cancel_cb
                          , PurpleAccount* account
                          , char const* who
                          , PurpleConversation* conv
                          , void* user_data
                          )
  {
    return perl_call<handle> ( OPS "request_folder"
                             , title
                             , dirname
                             , make_closure<1> (PurpleRequestFolderCb (ok_cb), user_data, (char const*)0)
                             , make_closure<1> (PurpleRequestFolderCb (cancel_cb), user_data, (char const*)0)
                             , account
                             , who
                             , conv
                             );
  }

  PurpleRequestUiOps
  request::create ()
  {
    return {
      request_input,
      request_choice,
      request_action,
      request_fields,
      request_file,
      close_request,
      request_folder,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }

  void
  request::destroy (G_GNUC_UNUSED PurpleRequestUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying request callbacks");
  }
}
