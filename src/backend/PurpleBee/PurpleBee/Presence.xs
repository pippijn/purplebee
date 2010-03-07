MODULE = PurpleBee      PACKAGE = PurpleBee::Presence                   PREFIX = purple_presence_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurplePresence*
purple_presence_new (PurplePresenceContext context);

PurplePresence*
purple_presence_new_for_account (PurpleAccount* account);

PurplePresence*
purple_presence_new_for_conv (PurpleConversation* conv);

PurplePresence*
purple_presence_new_for_buddy (PurpleBuddy* buddy);

void
purple_presence_destroy (PurplePresence* presence);

void
purple_presence_set_status_active (PurplePresence* presence, char const* status_id, gboolean active);

void
purple_presence_switch_status (PurplePresence* presence, char const* status_id);

void
purple_presence_set_idle (PurplePresence* presence, gboolean idle, time_t idle_time);

void
purple_presence_set_login_time (PurplePresence* presence, time_t login_time);

PurplePresenceContext
purple_presence_get_context (PurplePresence* presence);

PurpleAccount*
purple_presence_get_account (PurplePresence* presence);

PurpleConversation*
purple_presence_get_conversation (PurplePresence* presence);

char const*
purple_presence_get_chat_user (PurplePresence* presence);

PurpleBuddy*
purple_presence_get_buddy (PurplePresence* presence);

GList*
purple_presence_get_statuses (PurplePresence* presence);

PurpleStatus*
purple_presence_get_status (PurplePresence* presence, char const* status_id);

PurpleStatus*
purple_presence_get_active_status (PurplePresence* presence);

gboolean
purple_presence_is_available (PurplePresence* presence);

gboolean
purple_presence_is_online (PurplePresence* presence);

gboolean
purple_presence_is_status_active (PurplePresence* presence, char const* status_id);

gboolean
purple_presence_is_status_primitive_active (PurplePresence* presence, PurpleStatusPrimitive primitive);

gboolean
purple_presence_is_idle (PurplePresence* presence);

time_t
purple_presence_get_idle_time (PurplePresence* presence);

time_t
purple_presence_get_login_time (PurplePresence* presence);

gint
purple_presence_compare (PurplePresence* presence1, PurplePresence* presence2);
