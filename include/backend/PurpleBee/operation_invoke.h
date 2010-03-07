/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "backend/PurpleBee/operation.h"

template<typename F, typename... Args>
void
PurpleBee_operation<F, Args...>::pre_call (user_data_type& perl, closure_type const& closure)
{
  purple_debug_info ( "closure", "calling <%s>"
                    , resolve_symbol (std::get<0> (closure))
                    );
}

template<typename F, typename... Args>
void
PurpleBee_operation<F, Args...>::post_call (user_data_type& perl, closure_type const& closure, return_type const& RETVAL)
{
  PerlInterpreter* my_perl = perl.perl ();
  purple_debug_info ( "closure", "<%s> returned %s%s%s"
                    , resolve_symbol (std::get<0> (closure))
                    , RETVAL == &PL_sv_undef ? "" : "`"
                    , RETVAL == &PL_sv_undef ? "undef" : SvPV_nolen (RETVAL)
                    , RETVAL == &PL_sv_undef ? "" : "'"
                    );
}
