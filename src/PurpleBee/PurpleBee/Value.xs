MODULE = PurpleBee      PACKAGE = PurpleBee::Value              PREFIX = purple_value_


PurpleValue*
purple_value_new (PurpleType type, ...);

PurpleValue*
purple_value_new_outgoing (PurpleType type, ...);

void
purple_value_destroy (PurpleValue* value);

PurpleValue*
purple_value_dup (PurpleValue* value);

PurpleType
purple_value_get_type (PurpleValue* value);

unsigned int
purple_value_get_subtype (PurpleValue* value);

char const*
purple_value_get_specific_type (PurpleValue* value);

gboolean
purple_value_is_outgoing (PurpleValue* value);

void
purple_value_set_char (PurpleValue* value, char data);

void
purple_value_set_uchar (PurpleValue* value, char unsigned data);

void
purple_value_set_boolean (PurpleValue* value, gboolean data);

void
purple_value_set_short (PurpleValue* value, short data);

void
purple_value_set_ushort (PurpleValue* value, unsigned short data);

void
purple_value_set_int (PurpleValue* value, int data);

void
purple_value_set_uint (PurpleValue* value, unsigned int data);

void
purple_value_set_long (PurpleValue* value, long data);

void
purple_value_set_ulong (PurpleValue* value, unsigned long data);

void
purple_value_set_int64 (PurpleValue* value, gint64 data);

void
purple_value_set_uint64 (PurpleValue* value, guint64 data);

void
purple_value_set_string (PurpleValue* value, char const* data);

void
purple_value_set_object (PurpleValue* value, void* data);

void
purple_value_set_pointer (PurpleValue* value, void* data);

void
purple_value_set_enum (PurpleValue* value, int data);

void
purple_value_set_boxed (PurpleValue* value, void* data);

char
purple_value_get_char (PurpleValue* value);

char unsigned
purple_value_get_uchar (PurpleValue* value);

gboolean
purple_value_get_boolean (PurpleValue* value);

short
purple_value_get_short (PurpleValue* value);

unsigned short
purple_value_get_ushort (PurpleValue* value);

int
purple_value_get_int (PurpleValue* value);

unsigned int
purple_value_get_uint (PurpleValue* value);

long
purple_value_get_long (PurpleValue* value);

unsigned long
purple_value_get_ulong (PurpleValue* value);

gint64
purple_value_get_int64 (PurpleValue* value);

guint64
purple_value_get_uint64 (PurpleValue* value);

char const*
purple_value_get_string (PurpleValue* value);

void*
purple_value_get_object (PurpleValue* value);

void*
purple_value_get_pointer (PurpleValue* value);

int
purple_value_get_enum (PurpleValue* value);

void*
purple_value_get_boxed (PurpleValue* value);
