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
    RETVAL = (*self) ();
}
    OUTPUT:
    RETVAL
