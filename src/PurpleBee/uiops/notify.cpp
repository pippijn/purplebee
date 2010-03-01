#include "PurpleBee.h"
#include "uiops/notify.h"

#define OPS "Ops::Notify::"

namespace uiops
{
  void*
  notify::notify_message (PurpleNotifyMsgType type, const char* title, const char* primary, const char* secondary)
  {
    return server->call<void*> (OPS "notify_message", type, title, primary, secondary);
  }

  void*
  notify::notify_email (PurpleConnection* gc, const char* subject, const char* from, const char* to, const char* url)
  {
    return server->call<void*> (OPS "notify_email", gc, subject, from, to, url);
  }

  void*
  notify::notify_emails (PurpleConnection* gc, size_t count, gboolean detailed, const char** subjects, const char** froms, const char** tos, const char** urls)
  {
    return server->call<void*> (OPS "notify_emails", gc, count, detailed, subjects, froms, tos, urls);
  }

  void*
  notify::notify_formatted (const char* title, const char* primary, const char* secondary, const char* text)
  {
    return server->call<void*> (OPS "notify_formatted", title, primary, secondary, text);
  }

  void*
  notify::notify_searchresults (PurpleConnection* gc, const char* title, const char* primary, const char* secondary, PurpleNotifySearchResults* results, gpointer user_data)
  {
    return server->call<void*> (OPS "notify_searchresults", gc, title, primary, secondary, results, user_data);
  }

  void
  notify::notify_searchresults_new_rows (PurpleConnection* gc, PurpleNotifySearchResults* results, void* data)
  {
    return server->call<void> (OPS "notify_searchresults_new_rows", gc, results, data);
  }

  void*
  notify::notify_userinfo (PurpleConnection* gc, const char* who, PurpleNotifyUserInfo* user_info)
  {
    return server->call<void*> (OPS "notify_userinfo", gc, who, user_info);
  }

  void*
  notify::notify_uri (const char* uri)
  {
    return server->call<void*> (OPS "notify_uri", uri);
  }

  void
  notify::close_notify (PurpleNotifyType type, void* ui_handle)
  {
    return server->call<void> (OPS "close_notify", type, ui_handle);
  }

  PurpleNotifyUiOps
  notify::create ()
  {
    return {
      notify_message,
      notify_email,
      notify_emails,
      notify_formatted,
      notify_searchresults,
      notify_searchresults_new_rows,
      notify_userinfo,
      notify_uri,
      close_notify,
    };
  }
}
