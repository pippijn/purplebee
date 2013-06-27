/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "stacktrace.h"

#if HAVE_BFD_H
void
stacktrace::find_address_in_section (bfd* abfd, asection* section, void* data)
{
  stacktrace* self = static_cast<stacktrace*> (data);

  bfd_vma vma;
  bfd_size_type size;

  if (self->found)
    return;

  if ((bfd_get_section_flags (abfd, section) & SEC_ALLOC) == 0)
    return;

  vma = bfd_get_section_vma (abfd, section);
  if (self->pc < vma)
    return;

  size = bfd_section_size (abfd, section);
  if (self->pc >= vma + size)
    return;

  self->found = bfd_find_nearest_line (abfd, section, self->syms, self->pc - vma,
                                       &self->filename, &self->funcname, &self->line);
}
#endif
