MODULE = PurpleBee      PACKAGE = PurpleBee::Closure
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


# TODO: make this work
#void
#PurpleBeeClosure::DESTROY ()
    #CODE:
    #printf ("destroying callback %p (%s)\n", THIS, SvPV_nolen (ST (0)));
    #delete THIS;

void
DESTROY (SV* self)
    CODE:
    delete server->sv_to<PurpleBeeClosure*> (self);

SV*
PurpleBeeClosure::call ()
    CODE:
{
    purple_debug_info ("closure", "calling callback %p (%s)\n", THIS, SvPV_nolen (ST (0)));
    alarm (10);
    RETVAL = THIS->call ();
    alarm (0);
    purple_debug_info ("closure", "callback returned `%s'\n", SvPV_nolen (RETVAL));
}
    OUTPUT:
    RETVAL
