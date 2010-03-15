/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/force_assign.h"

#include "stacktrace.h"

#if HAVE_BFD_H
#include "file_match.h"

int stacktrace::find_matching_file ( struct dl_phdr_info* info
                                   , size_t size __attribute__ ((__unused__))
                                   , void* data
                                   )
{
  file_match* match = static_cast<file_match*> (data);

  ElfW(Addr) const  load_base = info->dlpi_addr;
  ElfW(Phdr) const* phdr      = info->dlpi_phdr;

  for (size_t n = 0; n < info->dlpi_phnum; n++, phdr++)
    {
      if (phdr->p_type == PT_LOAD)
        {
          auto vaddr = reinterpret_cast<char const*> (phdr->p_vaddr) + load_base;
          if (   match->address >= vaddr
              && match->address <  vaddr + phdr->p_memsz)
            {
              // we found a match
              force_assign (match->file, info->dlpi_name);
              force_assign (match->base, info->dlpi_addr);
            }
        }
    }
  return 0;
}
#endif
