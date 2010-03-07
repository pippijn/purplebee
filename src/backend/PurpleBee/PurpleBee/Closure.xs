MODULE = PurpleBee      PACKAGE = PurpleBee::Closure
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


void
PurpleBeeClosure::DESTROY ()

SV*
PurpleBeeClosure::call ()
    CODE:
{
    static int const max_count = 200;
    static int same_count = 1;
    static auto last = THIS;
    if (THIS == last)
      same_count++;
    else
      {
        last = THIS;
        same_count = 1;
      }
    if (same_count > max_count)
      {
        purple_debug_fatal ("closure", "freak invocation loop: invoked closure %p over %d times in a row", THIS, max_count);
        croak ("fatal error");
      }

    alarm (10);
    RETVAL = THIS->invoke ();
    alarm (0);
}
    OUTPUT:
    RETVAL
