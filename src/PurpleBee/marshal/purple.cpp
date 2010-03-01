#include <tuple>

#include "PurpleBee.h"
#include "PurpleBee/stash.h"
#include "perl/callback.h"
#include "util/xassert.h"

/*
 * T -> SV*
 */

template<>
SV*
perl_interpreter::to_sv (PurpleConversation* conv)
{
  return newSViv (0);
}

template<>
SV*
perl_interpreter::to_sv (PurpleMessageFlags flags)
{
  return newSViv (flags);
}

template<>
SV*
perl_interpreter::to_sv (PurpleInputCondition cond)
{
  return newSViv (cond);
}

template<>
SV*
perl_interpreter::to_sv (PurpleSoundEventID id)
{
  return newSViv (id);
}

template<>
SV*
perl_interpreter::to_sv (PurpleRequestType type)
{
  return newSViv (type);
}

template<>
SV*
perl_interpreter::to_sv (PurpleNotifyType type)
{
  return newSViv (type);
}

template<>
SV*
perl_interpreter::to_sv (PurpleNotifyMsgType type)
{
  return newSViv (type);
}

template<>
SV*
perl_interpreter::to_sv (PurpleConnectionError error)
{
  return newSViv (error);
}

template<>
SV*
perl_interpreter::to_sv (PurpleDebugLevel level)
{
  return newSViv (level);
}

template<>
SV*
perl_interpreter::to_sv (GCallback closure)
{
  return newSVptr (perl_callback::create (*this, std::make_tuple (closure)), newSV (0), stash::Callback);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleInputFunction, gpointer, int, PurpleInputCondition> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleAccountRequestAuthorizationCb, gpointer> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}

#if 0
template<>
SV*
perl_interpreter::to_sv (std::tuple<PurpleDnsQueryResolvedCallback, PurpleDnsQueryData*, char const*> closure)
{
  return newSVptr (perl_callback::create (*this, closure), newSV (0), stash::Callback);
}
#endif

template<> SV* perl_interpreter::to_sv (PurpleAccount* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_Account); }
template<> SV* perl_interpreter::to_sv (PurpleBlistNode* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_BlistNode); }
template<> SV* perl_interpreter::to_sv (PurpleBuddyList* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_BuddyList); }
template<> SV* perl_interpreter::to_sv (PurpleConnection* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_Connection); }
template<> SV* perl_interpreter::to_sv (PurpleDnsQueryData* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_DnsQueryData); }
template<> SV* perl_interpreter::to_sv (PurpleGroup* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_Group); }
template<> SV* perl_interpreter::to_sv (PurpleNotifySearchResults* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_NotifySearchResults); }
template<> SV* perl_interpreter::to_sv (PurpleNotifyUserInfo* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_NotifyUserInfo); }
template<> SV* perl_interpreter::to_sv (PurpleRequestFields* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_RequestFields); }
template<> SV* perl_interpreter::to_sv (PurpleRoomlist* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_Roomlist); }
template<> SV* perl_interpreter::to_sv (PurpleRoomlistRoom* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_RoomlistRoom); }
template<> SV* perl_interpreter::to_sv (PurpleStatus* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_Status); }
template<> SV* perl_interpreter::to_sv (PurpleWhiteboard* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_Whiteboard); }
template<> SV* perl_interpreter::to_sv (PurpleXfer* ob) { return newSVptr (ob, newHV (), stash::PurpleBee_Xfer); }


/*
 * SV* -> T
 */

template<> PurpleAccount* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleAccount*> (SvPTR (v)); }
template<> PurpleBlistNode* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleBlistNode*> (SvPTR (v)); }
template<> PurpleBuddyList* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleBuddyList*> (SvPTR (v)); }
template<> PurpleConnection* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleConnection*> (SvPTR (v)); }
template<> PurpleDnsQueryData* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleDnsQueryData*> (SvPTR (v)); }
template<> PurpleGroup* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleGroup*> (SvPTR (v)); }
template<> PurpleNotifySearchResults* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleNotifySearchResults*> (SvPTR (v)); }
template<> PurpleNotifyUserInfo* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleNotifyUserInfo*> (SvPTR (v)); }
template<> PurpleRequestFields* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleRequestFields*> (SvPTR (v)); }
template<> PurpleRoomlist* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleRoomlist*> (SvPTR (v)); }
template<> PurpleRoomlistRoom* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleRoomlistRoom*> (SvPTR (v)); }
template<> PurpleStatus* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleStatus*> (SvPTR (v)); }
template<> PurpleWhiteboard* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleWhiteboard*> (SvPTR (v)); }
template<> PurpleXfer* perl_interpreter::sv_to (SV* v) { return static_cast<PurpleXfer*> (SvPTR (v)); }

// vim:ft=xs
