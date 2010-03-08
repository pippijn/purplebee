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

typedef void (*PurpleRequestInputCallback)(void* user_data, char const* input);
typedef void (*PurpleRequestChoiceCallback)(void* user_data, int choice);
typedef void (*PurpleRequestActionCallback)(void* user_data, int option);
typedef void (*PurpleRequestFieldsCallback)(void* user_data, PurpleRequestFields* fields);
typedef void (*PurpleRequestFileCallback)(void* user_data, char const* filename);
typedef void (*PurpleRequestFolderCallback)(void* user_data, char const* foldername);
