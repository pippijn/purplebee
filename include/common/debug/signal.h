/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include "common/util/common.h"

BEGIN_DECLS

// Sets up signal handlers for our debugging aid with backtrace
// and sigaction coolness.
void init_signals ();
// Resets the signal handlers to SIG_DFL.
// XXX: init_signals does not save the old signal handlers. Maybe it should.
void uninit_signals ();

// Controls whether a caught signal should spawn gdb and attach it to our PID.
extern bool spawn_gdb;

END_DECLS
