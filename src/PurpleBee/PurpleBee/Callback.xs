MODULE = PurpleBee      PACKAGE = PurpleBee::Callback


void
perl_callback::DESTROY ()

SV*
perl_callback::call ()
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
