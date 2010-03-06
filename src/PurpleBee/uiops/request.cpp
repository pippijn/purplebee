/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "PurpleBee.h"
#include "perl/call.tcc"
#include "uiops/request.h"

#define OPS "UiOps::Request::"

namespace uiops
{
  void*
  request::request_input (const char* title, const char* primary, const char* secondary, const char* default_value, gboolean multiline, gboolean masked, gchar* hint, const char* ok_text, GCallback ok_cb, const char* cancel_text, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
    return perl_call<void*> (OPS "request_input", title, primary, secondary, default_value, multiline, masked, hint, ok_text, ok_cb, cancel_text, cancel_cb, account, who, conv, user_data);
  }

  void*
  request::request_choice (const char* title, const char* primary, const char* secondary, int default_value, const char* ok_text, GCallback ok_cb, const char* cancel_text, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data, va_list choices)
  {
    return perl_call<void*> (OPS "request_choice", title, primary, secondary, default_value, ok_text, ok_cb, cancel_text, cancel_cb, account, who, conv, user_data, choices);
  }

  void*
  request::request_action (const char* title, const char* primary, const char* secondary, int default_action, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data, size_t action_count, va_list actions)
  {
    return perl_call<void*> (OPS "request_action", title, primary, secondary, default_action, account, who, conv, user_data, action_count, actions);
  }

  void*
  request::request_fields (const char* title, const char* primary, const char* secondary, PurpleRequestFields* fields, const char* ok_text, GCallback ok_cb, const char* cancel_text, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
    return perl_call<void*> (OPS "request_fields", title, primary, secondary, fields, ok_text, ok_cb, cancel_text, cancel_cb, account, who, conv, user_data);
  }

  void*
  request::request_file (const char* title, const char* filename, gboolean savedialog, GCallback ok_cb, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
    return perl_call<void*> (OPS "request_file", title, filename, savedialog, ok_cb, cancel_cb, account, who, conv, user_data);
  }

  void
  request::close_request (PurpleRequestType type, void* ui_handle)
  {
    return perl_call<void> (OPS "close_request", type, ui_handle);
  }

  void*
  request::request_folder (const char* title, const char* dirname, GCallback ok_cb, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
    return perl_call<void*> (OPS "request_folder", title, dirname, ok_cb, cancel_cb, account, who, conv, user_data);
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
}
