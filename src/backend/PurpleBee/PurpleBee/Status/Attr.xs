MODULE = PurpleBee      PACKAGE = PurpleBee::Status::Attr               PREFIX = purple_status_attr_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

PurpleStatusAttr*
purple_status_attr_new (char const* id, char const* name, PurpleValue* value_type);

void
purple_status_attr_destroy (PurpleStatusAttr* attr);

char const*
purple_status_attr_get_id (PurpleStatusAttr* attr);

char const*
purple_status_attr_get_name (PurpleStatusAttr* attr);

PurpleValue*
purple_status_attr_get_value (PurpleStatusAttr* attr);
