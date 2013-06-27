/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/perl/interpreter.h"

extern PerlInterpreter* our_perl;

std::ostream& operator << (std::ostream& os, SV* sv);
