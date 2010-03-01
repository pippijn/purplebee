#include "PurpleBee.h"
#include "uiops/privacy.h"

#define OPS "Ops::Privacy::"

namespace uiops
{
  void
  privacy::permit_added (PurpleAccount* account, const char* name)
  {
  }

  void
  privacy::permit_removed (PurpleAccount* account, const char* name)
  {
  }

  void
  privacy::deny_added (PurpleAccount* account, const char* name)
  {
  }

  void
  privacy::deny_removed (PurpleAccount* account, const char* name)
  {
  }

  PurplePrivacyUiOps
  privacy::create ()
  {
  }
}
