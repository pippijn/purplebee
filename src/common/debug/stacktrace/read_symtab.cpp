/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "stacktrace.h"

#if HAVE_BFD_H
asymbol**
stacktrace::read_symtab (bfd* abfd)
{
  asymbol** symtab;

  if ((bfd_get_file_flags (abfd) & HAS_SYMS) == 0)
    return NULL;

  unsigned int size;
  long symcount = bfd_read_minisymbols (abfd, false, (PTR*)&symtab, &size);
  if (symcount == 0)
    // read dynamic
    symcount = bfd_read_minisymbols (abfd, true, (PTR*)&symtab, &size);

  if (symcount < 0)
    bfd_fatal (bfd_get_filename (abfd));

  return symtab;
}
#endif
