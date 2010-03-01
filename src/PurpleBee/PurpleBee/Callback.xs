MODULE = PurpleBee      PACKAGE = PurpleBee::Callback

void
DESTROY ()
    CODE:
{
    puts ("************************************gone");
}

SV*
call (SV* self)
    CODE:
{
    perl_callback* cb = static_cast<perl_callback*> (server->SvPTR (self));
    RETVAL = (*cb) ();
}
