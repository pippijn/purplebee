MODULE = PurpleBee      PACKAGE = PurpleBee::Closure
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


void
PurpleBeeClosure::DESTROY ()
    CODE:
    void const* symbol = THIS->symbol ();
    char* symname = resolve_symbol (symbol);
    purple_debug_info ("closure", "deleting closure <%s>", symname);
    free (symname);
    delete THIS;

SV*
PurpleBeeClosure::call ()
    CODE:
{
    static int const max_count = 400;
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

    void const* symbol = THIS->symbol ();
    char* symname = resolve_symbol (symbol);
    purple_debug_info ("closure", "invoking closure <%s>", symname);

    if (frame const* frames = THIS->frames ())
      {
#if HAVE_LAMBDA
        auto print = [](char const* text)
        {
          if (text[0] == 'a' && text[1] == 't')
            purple_debug_info ("closure-trace", "  registered");
          purple_debug_info ("closure-trace", "  %s", text);
        };
        print_frames (frames, print);
#endif
      }

    alarm (10);
    RETVAL = THIS->invoke ();
    alarm (0);

    purple_debug_info ( "closure", "closure <%s> returned %s%s%s"
                      , symname
                      , RETVAL == &PL_sv_undef ? "" : "`"
                      , RETVAL == &PL_sv_undef ? "undef" : SvPV_nolen (RETVAL)
                      , RETVAL == &PL_sv_undef ? "" : "'"
                      );
    free (symname);
}
    OUTPUT:
    RETVAL
