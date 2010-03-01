MODULE = PurpleBee      PACKAGE = PurpleBee::Callback


void
DESTROY ()
    CODE:
{
    puts ("************************************gone");
}

SV*
call (perl_callback* self)
    CODE:
{
    printf ("calling callback %p\n", self);
    alarm (10);
    RETVAL = (*self) ();
    alarm (0);
    printf ("callback returned %p\n", RETVAL);
}
    OUTPUT:
    RETVAL
