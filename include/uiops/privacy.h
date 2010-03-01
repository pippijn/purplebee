#pragma once

#include <purple.h>

namespace uiops
{
  struct privacy
  {
    static void permit_added (PurpleAccount* account, const char* name);
    static void permit_removed (PurpleAccount* account, const char* name);
    static void deny_added (PurpleAccount* account, const char* name);
    static void deny_removed (PurpleAccount* account, const char* name);

    static PurplePrivacyUiOps create ();
  };
}
