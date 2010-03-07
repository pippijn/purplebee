MODULE = PurpleBee      PACKAGE = PurpleBee::Status::Primitive          PREFIX = purple_primitive_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
#define TYPE    STATUS_
  const_val (UNSET);
  const_val (OFFLINE);
  const_val (AVAILABLE);
  const_val (UNAVAILABLE);
  const_val (INVISIBLE);
  const_val (AWAY);
  const_val (EXTENDED_AWAY);
  const_val (MOBILE);
  const_val (TUNE);
#undef TYPE
}

char const*
purple_primitive_get_id_from_type (PurpleStatusPrimitive type);

char const*
purple_primitive_get_name_from_type (PurpleStatusPrimitive type);

PurpleStatusPrimitive
purple_primitive_get_type_from_id (char const* id);
