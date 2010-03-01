#define PASTE(a, b) a##b

#if !defined (PTYPE) && !defined (ITYPE)
# error Need to define at least one of PTYPE, ITYPE
#endif

#ifndef PTYPE
# define PTYPE(T)
#endif
#ifndef ITYPE
# define ITYPE(T)
#endif

PTYPE (Account)
PTYPE (AccountOption)
PTYPE (AccountUserSplit)
PTYPE (BlistNode)
PTYPE (Buddy)
PTYPE (BuddyIcon)
PTYPE (BuddyIconSpec)
PTYPE (BuddyList)
PTYPE (Chat)
PTYPE (Connection)
PTYPE (Conversation)
PTYPE (Contact)
PTYPE (DnsQueryData)
PTYPE (Group)
PTYPE (NotifySearchResults)
PTYPE (NotifyUserInfo)
PTYPE (Presence)
PTYPE (RequestFields)
PTYPE (Roomlist)
PTYPE (RoomlistRoom)
PTYPE (Status)
PTYPE (StoredImage)
PTYPE (Whiteboard)
PTYPE (Xfer)

ITYPE (BlistNodeType)
ITYPE (BlistNodeFlags)
ITYPE (ConnectionError)
ITYPE (DebugLevel)
ITYPE (InputCondition)
ITYPE (MessageFlags)
ITYPE (NotifyMsgType)
ITYPE (NotifyType)
ITYPE (PrefType)
ITYPE (RequestType)
ITYPE (SoundEventID)

#undef PTYPE
#undef ITYPE
