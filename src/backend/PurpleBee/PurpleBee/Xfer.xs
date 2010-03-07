MODULE = PurpleBee      PACKAGE = PurpleBee::Xfer                       PREFIX = purple_xfer_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurpleXfer*
purple_xfer_new (PurpleAccount* account, PurpleXferType type, char const* who);

void
purple_xfer_ref (PurpleXfer* xfer);

void
purple_xfer_unref (PurpleXfer* xfer);

void
purple_xfer_request (PurpleXfer* xfer);

void
purple_xfer_request_accepted (PurpleXfer* xfer, char const* filename);

void
purple_xfer_request_denied (PurpleXfer* xfer);

PurpleXferType
purple_xfer_get_type (PurpleXfer* xfer);

PurpleAccount*
purple_xfer_get_account (PurpleXfer* xfer);

char const*
purple_xfer_get_remote_user (PurpleXfer* xfer);

PurpleXferStatusType
purple_xfer_get_status (PurpleXfer* xfer);

gboolean
purple_xfer_is_canceled (PurpleXfer* xfer);

gboolean
purple_xfer_is_completed (PurpleXfer* xfer);

char const*
purple_xfer_get_filename (PurpleXfer* xfer);

char const*
purple_xfer_get_local_filename (PurpleXfer* xfer);

size_t
purple_xfer_get_bytes_sent (PurpleXfer* xfer);

size_t
purple_xfer_get_bytes_remaining (PurpleXfer* xfer);

size_t
purple_xfer_get_size (PurpleXfer* xfer);

double
purple_xfer_get_progress (PurpleXfer* xfer);

unsigned int
purple_xfer_get_local_port (PurpleXfer* xfer);

char const*
purple_xfer_get_remote_ip (PurpleXfer* xfer);

unsigned int
purple_xfer_get_remote_port (PurpleXfer* xfer);

time_t
purple_xfer_get_start_time (PurpleXfer* xfer);

time_t
purple_xfer_get_end_time (PurpleXfer* xfer);

void
purple_xfer_set_completed (PurpleXfer* xfer, gboolean completed);

void
purple_xfer_set_message (PurpleXfer* xfer, char const* message);

void
purple_xfer_set_filename (PurpleXfer* xfer, char const* filename);

void
purple_xfer_set_local_filename (PurpleXfer* xfer, char const* filename);

void
purple_xfer_set_size (PurpleXfer* xfer, size_t size);

void
purple_xfer_set_bytes_sent (PurpleXfer* xfer, size_t bytes_sent);

PurpleXferUiOps*
purple_xfer_get_ui_ops (PurpleXfer* xfer);

void
purple_xfer_set_read_fnc (PurpleXfer * xfer, PurpleXferReadFunction fnc);

void
purple_xfer_set_write_fnc (PurpleXfer * xfer, PurpleXferWriteFunction fnc);

void
purple_xfer_set_ack_fnc (PurpleXfer * xfer, PurpleXferAckFunction fnc);

void
purple_xfer_set_request_denied_fnc (PurpleXfer * xfer, PurpleXferRequestDeniedFunction fnc);

void
purple_xfer_set_init_fnc (PurpleXfer * xfer, PurpleXferFunction fnc);

void
purple_xfer_set_start_fnc (PurpleXfer * xfer, PurpleXferFunction fnc);

void
purple_xfer_set_end_fnc (PurpleXfer * xfer, PurpleXferFunction fnc);

void
purple_xfer_set_cancel_send_fnc (PurpleXfer * xfer, PurpleXferFunction fnc);

void
purple_xfer_set_cancel_recv_fnc (PurpleXfer * xfer, PurpleXferFunction fnc);

gssize
purple_xfer_read (PurpleXfer* xfer, guchar*& buffer);
    OUTPUT:
    buffer

gssize
purple_xfer_write (PurpleXfer* xfer, guchar const* buffer, gsize size);

void
purple_xfer_start (PurpleXfer* xfer, int fd, char const* ip, unsigned int port);

void
purple_xfer_end (PurpleXfer* xfer);

void
purple_xfer_add (PurpleXfer* xfer);

void
purple_xfer_cancel_local (PurpleXfer* xfer);

void
purple_xfer_cancel_remote (PurpleXfer* xfer);

void
purple_xfer_error (PurpleXferType type, PurpleAccount* account, char const* who, char const* msg);

void
purple_xfer_update_progress (PurpleXfer* xfer);

void
purple_xfer_conversation_write (PurpleXfer* xfer, char* message, gboolean is_error);

void
purple_xfer_ui_ready (PurpleXfer* xfer);

void
purple_xfer_prpl_ready (PurpleXfer* xfer);
