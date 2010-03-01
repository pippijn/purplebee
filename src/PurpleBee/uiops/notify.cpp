#include "PurpleBee.h"
#include "uiops/notify.h"

#define OPS "Ops::Notify::"

namespace uiops
{
  void*
  notify::notify_message (PurpleNotifyMsgType type, const char* title, const char* primary, const char* secondary)
  {
  }

  void*
  notify::notify_email (PurpleConnection* gc, const char* subject, const char* from, const char* to, const char* url)
  {
  }

  void*
  notify::notify_emails (PurpleConnection* gc, size_t count, gboolean detailed, const char** subjects, const char** froms, const char** tos, const char** urls)
  {
  }

  void*
  notify::notify_formatted (const char* title, const char* primary, const char* secondary, const char* text)
  {
  }

  void*
  notify::notify_searchresults (PurpleConnection* gc, const char* title, const char* primary, const char* secondary, PurpleNotifySearchResults* results, gpointer user_data)
  {
  }

  void
  notify::notify_searchresults_new_rows (PurpleConnection* gc, PurpleNotifySearchResults* results, void* data)
  {
  }

  void*
  notify::notify_userinfo (PurpleConnection* gc, const char* who, PurpleNotifyUserInfo* user_info)
  {
  }

  void*
  notify::notify_uri (const char* uri)
  {
  }

  void
  notify::close_notify (PurpleNotifyType type, void* ui_handle)
  {
  }

  PurpleNotifyUiOps
  notify::create ()
  {
  }
}
