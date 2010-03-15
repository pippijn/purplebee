/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <cstring>

struct stacktrace::frame
{
  char* func;
  char* file;
  unsigned long line;

  frame ()
    : func (0)
    , file (0)
    , line (0)
  {
  }

  frame (char const* func, char const* file, unsigned long line)
    : func (func ? strdup (func) : 0)
    , file (file ? strdup (file) : 0)
    , line (line)
  {
  }

  frame& operator = (frame&& rhs)
  {
    free (func); func = rhs.func; rhs.func = 0;
    free (file); file = rhs.file; rhs.file = 0;
                 line = rhs.line; rhs.line = 0;

    return *this;
  }

  frame (frame&& rhs)
    : func (rhs.func)
    , file (rhs.file)
    , line (rhs.line)
  {
    rhs.func = 0;
    rhs.file = 0;
    rhs.line = 0;
  }

  ~frame ()
  {
    free (func);
    free (file);
  }

private:
  frame (frame const& rhs)
    : func (rhs.func ? strdup (rhs.func) : 0)
    , file (rhs.func ? strdup (rhs.file) : 0)
    , line (rhs.line)
  {
  }

  friend struct std::pair<void const* const, frame>;
#if HAVE_BFD_H
  friend frame stacktrace::resolve_frame_internal (char const* base);
#endif
};
