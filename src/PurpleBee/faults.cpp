#include "PurpleBee.h"

static void
fault_user ()
{
  system ("killall -11 lt-server");
}

static void
fault_null_pointer ()
{
  *(char volatile*)0 = 0;
}

static __attribute__ ((__used__)) void
fault_stack_overflow2 ()
{
  asm ("call _ZL20fault_stack_overflowv");
}

static void
fault_stack_overflow ()
{
  asm ("call _ZL21fault_stack_overflow2v");
}

static void
fault_abort ()
{
  abort ();
}

static void
fault_illegal_instruction ()
{
  asm (".value 0x0b0f");
}

static void
fault_div_by_zero ()
{
  static int a, b;
  a /= b;
}

static void
fault_read_only ()
{
  static int const value = 0;
  (int&)value = 3;
}

enum class faults
{
  USER,
  SEGV,
  STCK,
  ABRT,
  ILL,
  DIV0,
  RO,
};

void
PurpleBee::fault (int kind)
{
  typedef void fault_function ();
  fault_function* faults[] = {
    fault_user,
    fault_null_pointer,
    fault_stack_overflow,
    fault_abort,
    fault_illegal_instruction,
    fault_div_by_zero,
    fault_read_only,
  };

  faults[kind] ();
}
