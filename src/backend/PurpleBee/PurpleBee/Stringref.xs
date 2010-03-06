MODULE = PurpleBee      PACKAGE = PurpleBee::Stringref          PREFIX = purple_stringref_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


PurpleStringref*
purple_stringref_new (char const* value);

PurpleStringref*
purple_stringref_new_noref (char const* value);

#PurpleStringref*
#purple_stringref_printf (char const* format, ...);

PurpleStringref*
purple_stringref_ref (PurpleStringref* stringref);

void
purple_stringref_unref (PurpleStringref* stringref);

char const*
purple_stringref_value (PurpleStringref* stringref);

int
purple_stringref_cmp (PurpleStringref* s1, PurpleStringref* s2);

size_t
purple_stringref_len (PurpleStringref* stringref);
