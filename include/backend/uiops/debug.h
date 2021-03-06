/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

namespace uiops
{
  struct debug
  {
    static void print (PurpleDebugLevel level, const char* category, const char* arg_s);
    static gboolean is_enabled (PurpleDebugLevel level, const char* category);

    static PurpleDebugUiOps create ();
    static void destroy (PurpleDebugUiOps& ops);
  };
}
