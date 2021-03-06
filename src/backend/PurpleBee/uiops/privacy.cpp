/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "backend/PurpleBee/perl_call.h"
#include "backend/uiops/privacy.h"

#define OPS "UiOps::Privacy::"

namespace uiops
{
  void
  privacy::permit_added (PurpleAccount* account, char const* name)
  {
    return perl_call<void> (OPS "permit_added", account, name);
  }

  void
  privacy::permit_removed (PurpleAccount* account, char const* name)
  {
    return perl_call<void> (OPS "permit_removed", account, name);
  }

  void
  privacy::deny_added (PurpleAccount* account, char const* name)
  {
    return perl_call<void> (OPS "deny_added", account, name);
  }

  void
  privacy::deny_removed (PurpleAccount* account, char const* name)
  {
    return perl_call<void> (OPS "deny_removed", account, name);
  }

  PurplePrivacyUiOps
  privacy::create ()
  {
    return {
      permit_added,
      permit_removed,
      deny_added,
      deny_removed,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }

  void
  privacy::destroy (G_GNUC_UNUSED PurplePrivacyUiOps& ops)
  {
    purple_debug_info ("ffi", "destroying privacy callbacks");
  }
}
