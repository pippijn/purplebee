MODULE = PurpleBee      PACKAGE = PurpleBee::Closure


void
PurpleBeeClosure::DESTROY ()

SV*
PurpleBeeClosure::call ()
    CODE:
{
    printf ("calling callback %p\n", THIS);
    alarm (10);
    RETVAL = THIS->call ();
    alarm (0);
    printf ("callback returned %p\n", RETVAL);
}
    OUTPUT:
    RETVAL
