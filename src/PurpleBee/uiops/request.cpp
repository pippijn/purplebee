#include "PurpleBee.h"
#include "uiops/request.h"

#define OPS "Ops::Request::"

namespace uiops
{
  void*
  request::request_input (const char* title, const char* primary, const char* secondary, const char* default_value, gboolean multiline, gboolean masked, gchar* hint, const char* ok_text, GCallback ok_cb, const char* cancel_text, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
  }

  void*
  request::request_choice (const char* title, const char* primary, const char* secondary, int default_value, const char* ok_text, GCallback ok_cb, const char* cancel_text, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data, va_list choices)
  {
  }

  void*
  request::request_action (const char* title, const char* primary, const char* secondary, int default_action, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data, size_t action_count, va_list actions)
  {
  }

  void*
  request::request_fields (const char* title, const char* primary, const char* secondary, PurpleRequestFields* fields, const char* ok_text, GCallback ok_cb, const char* cancel_text, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
  }

  void*
  request::request_file (const char* title, const char* filename, gboolean savedialog, GCallback ok_cb, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
  }

  void
  request::close_request (PurpleRequestType type, void* ui_handle)
  {
  }

  void*
  request::request_folder (const char* title, const char* dirname, GCallback ok_cb, GCallback cancel_cb, PurpleAccount* account, const char* who, PurpleConversation* conv, void* user_data)
  {
  }

  PurpleRequestUiOps
  request::create ()
  {
  }
}
