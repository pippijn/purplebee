/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/preprocessor.h"

// This file contains all types that are passed between C++ and perl with
// their type and, respectively, their package name.
//
// PTYPE is an opaque pointer type.
// OTYPE is an object type that intrusively contains the perl object that
//       represents it.
// ITYPE is an integral type. It is usually an enum.
// FTYPE is a function pointer type. These should go away, later, and be
//       wrapped in a closure<>.

#if !defined (PTYPE) && !defined (ITYPE) && !defined (FTYPE)
# error Need to define at least one of PTYPE, ITYPE, FTYPE
#endif

#ifndef PTYPE
# define PTYPE(T, P)
#endif
#ifndef OTYPE
# define OTYPE(T, P) PTYPE(T, P)
#endif
#ifndef ITYPE
# define ITYPE(T, P)
#endif
#ifndef FTYPE
# define FTYPE(T, P)
#endif

#define PKG PACKAGE_NAME "::"

PTYPE (Bee,                             "PurpleBee")
OTYPE (BeeClosure,                      PKG "Closure")

PTYPE (Account,                         PKG "Account")
PTYPE (AccountOption,                   PKG "Account::Option")
PTYPE (AccountUiOps,                    PKG "Account::UiOps")
PTYPE (AccountUserSplit,                PKG "Account::UserSplit")
PTYPE (Buddy,                           PKG "Buddy")
PTYPE (BuddyIcon,                       PKG "Buddy::Icon")
PTYPE (BuddyIconSpec,                   PKG "Buddy::IconSpec")
PTYPE (BuddyList,                       PKG "BuddyList")
PTYPE (BlistNode,                       PKG "BuddyList::Node")
PTYPE (BlistUiOps,                      PKG "BuddyList::UiOps")
PTYPE (Certificate,                     PKG "Certificate")
PTYPE (CertificatePool,                 PKG "Certificate::Pool")
PTYPE (CertificateScheme,               PKG "Certificate::Scheme")
PTYPE (CertificateVerificationRequest,  PKG "Certificate::VerificationRequest")
PTYPE (CertificateVerifier,             PKG "Certificate::Verifier")
PTYPE (Chat,                            PKG "Chat")
PTYPE (Cipher,                          PKG "Cipher")
PTYPE (CipherContext,                   PKG "Cipher::Context")
PTYPE (CipherOps,                       PKG "Cipher::Ops")
PTYPE (Connection,                      PKG "Connection")
PTYPE (ConnectionErrorInfo,             PKG "Connection::ErrorInfo")
PTYPE (ConnectionUiOps,                 PKG "Connection::UiOps")
PTYPE (Contact,                         PKG "Contact")
PTYPE (ConvChatBuddy,                   PKG "Conversation::Chat::Buddy")
PTYPE (ConvChat,                        PKG "Conversation::Chat")
PTYPE (Conversation,                    PKG "Conversation")
PTYPE (ConversationUiOps,               PKG "Conversation::UiOps")
PTYPE (ConvIm,                          PKG "Conversation::Im")
PTYPE (ConvMessage,                     PKG "Conversation::Message")
PTYPE (Core,                            PKG "Core")
PTYPE (CoreUiOps,                       PKG "Core::UiOps")
PTYPE (DebugUiOps,                      PKG "Debug::UiOps")
PTYPE (DnsQueryData,                    PKG "DnsQuery::Data")
PTYPE (DnsQueryUiOps,                   PKG "DnsQuery::UiOps")
PTYPE (EventLoopUiOps,                  PKG "EventLoop::UiOps")
PTYPE (Group,                           PKG "Group")
PTYPE (IdleUiOps,                       PKG "Idle::UiOps")
PTYPE (Log,                             PKG "Log")
PTYPE (LogLogger,                       PKG "Log::Logger")
PTYPE (LogSet,                          PKG "Log::Set")
PTYPE (MenuAction,                      PKG "Menu::Action")
PTYPE (MimeDocument,                    PKG "Mime::Document")
PTYPE (MimePart,                        PKG "Mime::Part")
PTYPE (NetworkListenData,               PKG "Network::ListenData")
PTYPE (NotifySearchColumn,              PKG "Notify::SearchColumn")
PTYPE (NotifySearchResults,             PKG "Notify::SearchResults")
PTYPE (NotifyUiOps,                     PKG "Notify::UiOps")
PTYPE (NotifyUserInfoEntry,             PKG "Notify::UserInfo::Entry")
PTYPE (NotifyUserInfo,                  PKG "Notify::UserInfo")
PTYPE (Plugin,                          PKG "Plugin")
PTYPE (Pounce,                          PKG "Pounce")
PTYPE (Presence,                        PKG "Presence")
PTYPE (PrivacyUiOps,                    PKG "Privacy::UiOps")
PTYPE (ProxyConnectData,                PKG "Proxy::ConnectData")
PTYPE (ProxyInfo,                       PKG "Proxy::Info")
PTYPE (RequestFieldGroup,               PKG "Request::FieldGroup")
PTYPE (RequestField,                    PKG "Request::Field")
PTYPE (RequestFields,                   PKG "Request::Fields")
PTYPE (RequestUiOps,                    PKG "Request::UiOps")
PTYPE (Roomlist,                        PKG "Roomlist")
PTYPE (RoomlistField,                   PKG "Roomlist::Field")
PTYPE (RoomlistRoom,                    PKG "Roomlist::Room")
PTYPE (RoomlistUiOps,                   PKG "Roomlist::UiOps")
PTYPE (SavedStatus,                     PKG "SavedStatus")
PTYPE (SavedStatusSub,                  PKG "SavedStatus::Sub")
PTYPE (Smiley,                          PKG "Smiley")
PTYPE (SoundTheme,                      PKG "Sound::Theme")
PTYPE (SoundUiOps,                      PKG "Sound::UiOps")
PTYPE (SslConnection,                   PKG "Ssl::Connection")
PTYPE (SslOps,                          PKG "SslOps")
PTYPE (Status,                          PKG "Status")
PTYPE (StatusAttr,                      PKG "Status::Attr")
PTYPE (StatusType,                      PKG "Status::Type")
PTYPE (StoredImage,                     PKG "StoredImage")
PTYPE (Stringref,                       PKG "Stringref")
PTYPE (UtilFetchUrlData,                PKG "UtilFetchUrlData")
PTYPE (Value,                           PKG "Value")
PTYPE (Whiteboard,                      PKG "Whiteboard")
PTYPE (WhiteboardPrplOps,               PKG "Whiteboard::PrplOps")
PTYPE (WhiteboardUiOps,                 PKG "Whiteboard::UiOps")
PTYPE (Xfer,                            PKG "Xfer")
PTYPE (XferUiOps,                       PKG "Xfer::UiOps")

ITYPE (AccountRequestType,              PKG "Account::RequestType")
ITYPE (BlistNodeFlags,                  PKG "BuddyList::Node::Flags")
ITYPE (BlistNodeType,                   PKG "BuddyList::Node::Type")
ITYPE (CertificateVerificationStatus,   PKG "Certificate::VerificationStatus")
ITYPE (CipherBatchMode,                 PKG "Cipher::BatchMode")
ITYPE (CipherCaps,                      PKG "Cipher::Caps")
ITYPE (CmdFlag,                         PKG "Cmd::Flag")
//ITYPE (CmdId,                           PKG "Cmd::Id")
ITYPE (CmdPriority,                     PKG "Cmd::Priority")
ITYPE (CmdRet,                          PKG "Cmd::Ret")
ITYPE (CmdStatus,                       PKG "Cmd::Status")
ITYPE (ConnectionError,                 PKG "Connection::Error")
ITYPE (ConnectionFlags,                 PKG "Connection::Flags")
ITYPE (ConnectionState,                 PKG "Connection::State")
ITYPE (ConvChatBuddyFlags,              PKG "Conversation::Chat::Buddy::Flags")
ITYPE (ConversationType,                PKG "Conversation::Type")
ITYPE (ConvUpdateType,                  PKG "Conversation::UpdateType")
ITYPE (DebugLevel,                      PKG "Debug::Level")
ITYPE (InputCondition,                  PKG "InputCondition")
ITYPE (LogReadFlags,                    PKG "Log::ReadFlags")
ITYPE (LogType,                         PKG "Log::Type")
ITYPE (MessageFlags,                    PKG "MessageFlags")
ITYPE (NotifyMsgType,                   PKG "Notify::MsgType")
ITYPE (NotifySearchButtonType,          PKG "Notify::SearchButtonType")
ITYPE (NotifyType,                      PKG "Notify::Type")
ITYPE (NotifyUserInfoEntryType,         PKG "Notify::UserInfoEntryType")
ITYPE (PounceEvent,                     PKG "Pounce::Event")
ITYPE (PounceOption,                    PKG "Pounce::Option")
ITYPE (PrefType,                        PKG "PrefType")
ITYPE (PresenceContext,                 PKG "Presence::Context")
ITYPE (PrivacyType,                     PKG "Privacy::Type")
ITYPE (ProxyType,                       PKG "Proxy::Type")
ITYPE (RequestFieldType,                PKG "Request::FieldType")
ITYPE (RequestType,                     PKG "Request::Type")
ITYPE (RoomlistFieldType,               PKG "Roomlist::FieldType")
ITYPE (RoomlistRoomType,                PKG "Roomlist::RoomType")
ITYPE (SoundEventID,                    PKG "Sound::EventID")
ITYPE (SslErrorType,                    PKG "Ssl::ErrorType")
ITYPE (StatusPrimitive,                 PKG "Status::Primitive")
ITYPE (SubType,                         PKG "SubType")
ITYPE (Type,                            PKG "Type")
ITYPE (TypingState,                     PKG "TypingState")
ITYPE (XferStatusType,                  PKG "Xfer::StatusType")
ITYPE (XferType,                        PKG "Xfer::Type")

FTYPE (AccountRegistrationCb,           PKG "AccountRegistrationCb")
FTYPE (AccountRequestAuthorizationCb,   PKG "AccountRequestAuthorizationCb")
//FTYPE (AccountUnregistrationCb,         PKG "AccountUnregistrationCb")
//FTYPE (Callback,                        PKG "Callback")
FTYPE (CertificateVerifiedCallback,     PKG "CertificateVerifiedCallback")
FTYPE (CmdFunc,                         PKG "CmdFunc")
FTYPE (ConversationFunction,            PKG "ConversationFunction")
FTYPE (DnsQueryConnectFunction,         PKG "DnsQueryConnectFunction")
FTYPE (FilterAccountFunc,               PKG "FilterAccountFunc")
FTYPE (InfoFieldFormatCallback,         PKG "InfoFieldFormatCallback")
FTYPE (InputFunction,                   PKG "InputFunction")
FTYPE (NetworkListenCallback,           PKG "NetworkListenCallback")
//FTYPE (NotifyCloseCallback,             PKG "NotifyCloseCallback")
FTYPE (NotifySearchResultsCallback,     PKG "NotifySearchResultsCallback")
FTYPE (PounceCb,                        PKG "PounceCb")
FTYPE (PounceFunction,                  PKG "PounceFunction")
FTYPE (PrefCallback,                    PKG "PrefCallback")
FTYPE (ProxyConnectFunction,            PKG "Proxy::ConnectFunction")
FTYPE (SslErrorFunction,                PKG "SslErrorFunction")
FTYPE (SslInputFunction,                PKG "SslInputFunction")
FTYPE (UtilFetchUrlCallback,            PKG "UtilFetchUrlCallback")
FTYPE (XferAckFunction,                 PKG "XferAckFunction")
FTYPE (XferFunction,                    PKG "XferFunction")
FTYPE (XferReadFunction,                PKG "XferReadFunction")
FTYPE (XferWriteFunction,               PKG "XferWriteFunction")

#undef PKG

#undef PTYPE
#undef OTYPE
#undef ITYPE
#undef FTYPE
