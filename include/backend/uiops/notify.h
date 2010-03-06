/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

namespace uiops
{
  struct notify
  {
    static void* notify_message (PurpleNotifyMsgType type, const char* title, const char* primary, const char* secondary);
    static void* notify_email (PurpleConnection* gc, const char* subject, const char* from, const char* to, const char* url);
    static void* notify_emails (PurpleConnection* gc, size_t count, gboolean detailed, const char** subjects, const char** froms, const char** tos, const char** urls);
    static void* notify_formatted (const char* title, const char* primary, const char* secondary, const char* text);
    static void* notify_searchresults (PurpleConnection* gc, const char* title, const char* primary, const char* secondary, PurpleNotifySearchResults* results, gpointer user_data);
    static void notify_searchresults_new_rows (PurpleConnection* gc, PurpleNotifySearchResults* results, void* data);
    static void* notify_userinfo (PurpleConnection* gc, const char* who, PurpleNotifyUserInfo* user_info);
    static void* notify_uri (const char* uri);
    static void close_notify (PurpleNotifyType type, void* ui_handle);

    static PurpleNotifyUiOps create ();
  };
}
