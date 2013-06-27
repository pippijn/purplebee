/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/notify.h"

#define OPS "UiOps::Notify::"

namespace uiops
{
  void*
  notify::notify_message (PurpleNotifyMsgType type, char const* title, char const* primary, char const* secondary)
  {
    return perl_call<void*> (OPS "notify_message", type, title, primary, secondary);
  }

  void*
  notify::notify_email (PurpleConnection* gc, char const* subject, char const* from, char const* to, char const* url)
  {
    return perl_call<void*> (OPS "notify_email", gc, subject, from, to, url);
  }

  void*
  notify::notify_emails (PurpleConnection* gc, size_t count, gboolean detailed, char const** subjects, char const** froms, char const** tos, char const** urls)
  {
    return perl_call<void*> (OPS "notify_emails", gc, count, detailed, std::make_tuple (count, subjects), std::make_tuple (count, froms), std::make_tuple (count, tos), std::make_tuple (count, urls));
  }

  void*
  notify::notify_formatted (char const* title, char const* primary, char const* secondary, char const* text)
  {
    return perl_call<void*> (OPS "notify_formatted", title, primary, secondary, text);
  }

  void*
  notify::notify_searchresults (PurpleConnection* gc, char const* title, char const* primary, char const* secondary, PurpleNotifySearchResults* results, gpointer user_data)
  {
    return perl_call<void*> (OPS "notify_searchresults", gc, title, primary, secondary, results, user_data);
  }

  void
  notify::notify_searchresults_new_rows (PurpleConnection* gc, PurpleNotifySearchResults* results, void* data)
  {
    return perl_call<void> (OPS "notify_searchresults_new_rows", gc, results, data);
  }

  void*
  notify::notify_userinfo (PurpleConnection* gc, char const* who, PurpleNotifyUserInfo* user_info)
  {
    return perl_call<void*> (OPS "notify_userinfo", gc, who, user_info);
  }

  void*
  notify::notify_uri (char const* uri)
  {
    return perl_call<void*> (OPS "notify_uri", uri);
  }

  void
  notify::close_notify (PurpleNotifyType type, void* ui_handle)
  {
    return perl_call<void> (OPS "close_notify", type, ui_handle);
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

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }

  void
  notify::destroy (G_GNUC_UNUSED PurpleNotifyUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying notify callbacks");
  }
}
