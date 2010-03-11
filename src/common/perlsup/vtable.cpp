/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/perl/package.h"

template<>
MGVTBL perl_package<void>::vtbl = { 0, 0, 0, 0, 0, 0, 0, 0 };
