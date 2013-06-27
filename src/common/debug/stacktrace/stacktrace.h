/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <vector>
#include <string>

#undef HAVE_BFD_H

#if HAVE_BFD_H
#include <bfd.h>
#include <cxxabi.h>
#include <dirent.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <link.h>
#include <pthread.h>
#endif

#define fatal(a, b) exit (1)
#define bfd_fatal(a) exit (1)
#define bfd_nonfatal(a) exit (1)
#define list_matching_formats(a) exit (1)

#define DLBFD 1

struct stacktrace
{
  struct frame;

#if HAVE_BFD_H
  struct dlbfd
  {
    void* handle;

    decltype (bfd_init)* init;
    decltype (bfd_map_over_sections)* map_over_sections;
    decltype (bfd_check_format)* check_format;
    decltype (bfd_check_format_matches)* check_format_matches;
    decltype (bfd_openr)* openr;
    decltype (bfd_close)* close;

    dlbfd ();
    ~dlbfd ();
  };

private:
  pthread_mutex_t mtx;
  asymbol** syms;       // Symbol table
  dlbfd dbfd;

  // These global variables are used to pass information between
  // translate_addresses and find_address_in_section.
  bfd_vma pc;
  const char* filename;
  const char* funcname;
  unsigned int line;
  unsigned int found;

  struct file_match;

  bool check_bfd ();

  // Read in the symbol table.
  asymbol** read_symtab (bfd* abfd);

  // Look for an address in a section. This is called via
  // bfd_map_over_sections.
  static void find_address_in_section (bfd* abfd, asection* section, void* data);

  frame translate_addresses (bfd* abfd, bfd_vma* addr, int naddr);
  frame process_file (const char* file_name, bfd_vma* addr, int naddr);

  static int find_matching_file ( struct dl_phdr_info* info
                                , size_t size __attribute__ ((__unused__))
                                , void* data
                                );

  frame resolve_frame_internal (char const* base);

public:
  stacktrace ();
  ~stacktrace ();
#else
# define check_bfd() false
#endif

  frame resolve_frame (void const* base);

  std::vector<frame> backtrace_symbols (void* const* buffer, size_t size);
};

#if HAVE_BFD_H && DLBFD
bool load_bfd (stacktrace::dlbfd& self, std::string& errors);
#endif
