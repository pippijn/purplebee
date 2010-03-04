#include "PurpleBee.h"
#include "perl/call.h"
#include "uiops/privacy.h"

#define OPS "UiOps::Privacy::"

namespace uiops
{
  void
  privacy::permit_added (PurpleAccount* account, const char* name)
  {
    return server->call<void> (OPS "permit_added", account, name);
  }

  void
  privacy::permit_removed (PurpleAccount* account, const char* name)
  {
    return server->call<void> (OPS "permit_removed", account, name);
  }

  void
  privacy::deny_added (PurpleAccount* account, const char* name)
  {
    return server->call<void> (OPS "deny_added", account, name);
  }

  void
  privacy::deny_removed (PurpleAccount* account, const char* name)
  {
    return server->call<void> (OPS "deny_removed", account, name);
  }

  PurplePrivacyUiOps
  privacy::create ()
  {
    return {
      permit_added,
      permit_removed,
      deny_added,
      deny_removed,
    };
  }
}
