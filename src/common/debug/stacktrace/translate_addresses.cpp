/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <cmath>
#include <cstring>

#include "stacktrace.h"

#if HAVE_BFD_H
#include "dlbfd.h"
#include "frame.h"

static size_t const ptrstr_len = log (SIZE_MAX) / log (16) + 1 + 2; // for "0x"

stacktrace::frame
stacktrace::translate_addresses (bfd* abfd, bfd_vma* addr, int naddr)
{
  pc = addr[naddr - 1];

  found = false;
  bfd_map_over_sections (abfd, find_address_in_section, this);

  if (!found)
    {
      char addrstr[ptrstr_len + 3];
      snprintf (addrstr, sizeof addrstr, "0x%llx", (unsigned long long)addr[naddr - 1]);
      return { addrstr, "???", 0 };
    }
  else
    {
      std::string func;
      if (funcname == NULL || *funcname == '\0')
        func = "???";
      else
        {
          int status;
          char* realname = abi::__cxa_demangle (funcname, 0, 0, &status);
          func = status == 0 ? realname : funcname;
          if (realname)
            free (realname);
        }
      if (filename == NULL)
        filename = "???";
      else
      if (char const* h = strrchr (filename, '/'))
        filename = h + 1;
      return { func.c_str (), filename, line };
    }
}
#endif
