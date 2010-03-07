/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>
#define PASTE2(a,b)             BOOST_PP_CAT(a,b)
#define PASTE3(a,b,c)           PASTE2(a,PASTE2(b,c))
#define PASTE4(a,b,c,d)         PASTE2(a,PASTE3(b,c,d))
#define PASTE5(a,b,c,d,e)       PASTE2(a,PASTE4(b,c,d,e))

#define PASTE                   PASTE2
#define STRINGIZE               BOOST_PP_STRINGIZE
