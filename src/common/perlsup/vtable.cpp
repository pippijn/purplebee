#include "common/perl/package.h"

template<>
MGVTBL perl_package<void>::vtbl = { 0, 0, 0, 0, 0, 0, 0, 0 };
