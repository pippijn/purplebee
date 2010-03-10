#pragma once

#include "common/perl/interpreter.h"

extern PerlInterpreter* our_perl;

std::ostream& operator << (std::ostream& os, SV* sv);
