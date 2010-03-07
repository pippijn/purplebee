MODULE = PurpleBee      PACKAGE = PurpleBee::Status::Primitive          PREFIX = purple_primitive_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

char const*
purple_primitive_get_id_from_type (PurpleStatusPrimitive type);

char const*
purple_primitive_get_name_from_type (PurpleStatusPrimitive type);

PurpleStatusPrimitive
purple_primitive_get_type_from_id (char const* id);
