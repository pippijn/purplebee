/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/xassert.h"

#include "stacktrace.h"

#if HAVE_BFD_H
#include "dlbfd.h"
#include "frame.h"

stacktrace::frame
stacktrace::process_file (const char* file_name, bfd_vma* addr, int naddr)
{
  bfd* abfd = bfd_openr (file_name, NULL);

  if (abfd == NULL)
    bfd_fatal (file_name);

  if (bfd_check_format (abfd, bfd_archive))
    fatal ("%s: can not get addresses from archive", file_name);

  char** matching;
  if (!bfd_check_format_matches (abfd, bfd_object, &matching))
    {
      bfd_nonfatal (bfd_get_filename (abfd));
      if (bfd_get_error () == bfd_error_file_ambiguously_recognized)
        {
          list_matching_formats (matching);
          free (matching);
        }
      exit (1);
    }

  frame frame;
  {
    xassert (!syms);
    syms = read_symtab (abfd);

    frame = translate_addresses (abfd, addr, naddr);

    free (syms);
    syms = NULL;
  }

  bfd_close (abfd);
  return frame;
}
#endif
