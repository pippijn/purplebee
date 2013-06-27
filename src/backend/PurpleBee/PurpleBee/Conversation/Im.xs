MODULE = PurpleBee      PACKAGE = PurpleBee::Conversation::Im           PREFIX = purple_conv_im_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurpleConversation*
purple_conv_im_get_conversation (PurpleConvIm* im);

void
purple_conv_im_set_icon (PurpleConvIm* im, PurpleBuddyIcon* icon);

PurpleBuddyIcon*
purple_conv_im_get_icon (PurpleConvIm* im);

void
purple_conv_im_set_typing_state (PurpleConvIm* im, PurpleTypingState state);

PurpleTypingState
purple_conv_im_get_typing_state (PurpleConvIm* im);

void
purple_conv_im_start_typing_timeout (PurpleConvIm* im, int timeout);

void
purple_conv_im_stop_typing_timeout (PurpleConvIm* im);

guint
purple_conv_im_get_typing_timeout (PurpleConvIm* im);

void
purple_conv_im_set_type_again (PurpleConvIm* im, unsigned int val);

time_t
purple_conv_im_get_type_again (PurpleConvIm* im);

void
purple_conv_im_start_send_typed_timeout (PurpleConvIm* im);

void
purple_conv_im_stop_send_typed_timeout (PurpleConvIm* im);

guint
purple_conv_im_get_send_typed_timeout (PurpleConvIm* im);

void
purple_conv_im_update_typing (PurpleConvIm* im);

void
purple_conv_im_write (PurpleConvIm* im, char const* who, char const* message, PurpleMessageFlags flags, time_t mtime);

void
purple_conv_im_send (PurpleConvIm* im, char const* message);

void
purple_conv_im_send_with_flags (PurpleConvIm* im, char const* message, PurpleMessageFlags flags);
