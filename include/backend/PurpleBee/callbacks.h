/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <purple.h>

typedef gssize (*PurpleXferReadFunction)(guchar**, PurpleXfer*);
typedef gssize (*PurpleXferWriteFunction)(guchar const*, size_t, PurpleXfer*);
typedef void (*PurpleXferAckFunction)(PurpleXfer*, guchar const*, size_t);
typedef void (*PurpleXferFunction)(PurpleXfer*);
typedef PurpleXferFunction PurpleXferRequestDeniedFunction;
typedef void (*PurplePounceFunction)(PurplePounce* pounce);
typedef void (*PurpleConversationFunction)(PurpleConversation* conv);

typedef PurpleRequestFileCb PurpleRequestFolderCb;
