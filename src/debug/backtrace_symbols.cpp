#include <iostream>

#include <string>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <bfd.h>
#include <cxxabi.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <link.h>

#define fatal(a, b) exit (1)
#define bfd_fatal(a) exit (1)
#define bfd_nonfatal(a) exit (1)
#define list_matching_formats(a) exit (1)

static size_t const intstr_len = log10 (SIZE_MAX) + 1;
static size_t const ptrstr_len = intstr_len + 2; // for "0x"

template<typename To, typename From>
static void
must_assign (To& target, From source)
{
  assert (source);
  target = reinterpret_cast<To> (source);
}

struct stacktrace
{
  struct dlbfd
  {
    void* handle;

    decltype (bfd_init)* init;
    decltype (bfd_map_over_sections)* map_over_sections;
    decltype (bfd_check_format)* check_format;
    decltype (bfd_check_format_matches)* check_format_matches;
    decltype (bfd_openr)* openr;
    decltype (bfd_close)* close;

#define DLBFD 1
    dlbfd ()
    {
#if DLBFD
      handle = dlopen ("libbfd.so", RTLD_NOW);
      must_assign (init,                        dlsym (handle, "bfd_init"));
      must_assign (map_over_sections,           dlsym (handle, "bfd_map_over_sections"));
      must_assign (check_format,                dlsym (handle, "bfd_check_format"));
      must_assign (check_format_matches,        dlsym (handle, "bfd_check_format_matches"));
      must_assign (openr,                       dlsym (handle, "bfd_openr"));
      must_assign (close,                       dlsym (handle, "bfd_close"));
#define bfd_init                        dbfd.init
#define bfd_map_over_sections           dbfd.map_over_sections
#define bfd_check_format                dbfd.check_format
#define bfd_check_format_matches        dbfd.check_format_matches
#define bfd_openr                       dbfd.openr
#define bfd_close                       dbfd.close
#endif
    }

    ~dlbfd ()
    {
#if DLBFD
      dlclose (handle);
#endif
    }
  };


  asymbol** syms;       // Symbol table
  dlbfd dbfd;

  // These global variables are used to pass information between
  // translate_addresses and find_address_in_section.
  bfd_vma pc;
  const char* filename;
  const char* functionname;
  unsigned int line;
  bool found;

  // Read in the symbol table.
  void slurp_symtab (bfd* abfd)
  {
    if ((bfd_get_file_flags (abfd) & HAS_SYMS) == 0)
      return;

    unsigned int size;
    long symcount = bfd_read_minisymbols (abfd, false, (PTR*)&syms, &size);
    if (symcount == 0)
      // read dynamic
      symcount = bfd_read_minisymbols (abfd, true, (PTR*)&syms, &size);

    if (symcount < 0)
      bfd_fatal (bfd_get_filename (abfd));
  }

  // Look for an address in a section. This is called via
  // bfd_map_over_sections.
  static void find_address_in_section (bfd* abfd, asection* section, void* data)
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
                                         &self->filename, &self->functionname, &self->line);
  }

  struct frame
  {
    std::string func;
    std::string file;
    unsigned long line;

    friend std::ostream& operator << (std::ostream& os, stacktrace::frame const& frame)
    {
      return os << frame.func << '@' << frame.file << ':' << frame.line;
    }
  };

  frame translate_addresses (bfd* abfd, bfd_vma* addr, int naddr)
  {
    pc = addr[naddr - 1];

    found = false;
    bfd_map_over_sections (abfd, find_address_in_section, this);

    if (!found)
      {
        char addrstr[ptrstr_len + 3];
        snprintf (addrstr, sizeof addrstr, "0x%lx", addr[naddr - 1]);
        return { addrstr, "???", 0 };
      }
    else
      {
        std::string funcname;
        if (functionname == NULL || *functionname == '\0')
          funcname = "???";
        else
          {
            int status;
            char* realname = abi::__cxa_demangle (functionname, 0, 0, &status);
            funcname = status == 0 ? realname : functionname;
            if (realname)
              free (realname);
          }
        if (filename != NULL)
          {
            char const* h = strrchr (filename, '/');
            if (h != NULL)
              filename = h + 1;
          }
        return { funcname, filename, line };
      }
  }

  frame process_file (const char* file_name, bfd_vma* addr, int naddr)
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

    assert (!syms);
    slurp_symtab (abfd);

    frame frame = translate_addresses (abfd, addr, naddr);

    free (syms);
    syms = NULL;

    bfd_close (abfd);
    return frame;
  }

  struct file_match
  {
    const char* file;
    char const* address;
    char const* base;
    void* hdr;
  };

  static int find_matching_file ( struct dl_phdr_info* info
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
                must_assign (match->file, info->dlpi_name);
                must_assign (match->base, info->dlpi_addr);
              }
          }
      }
    return 0;
  }

  frame resolve_frame (char const* base)
  {
    file_match match { 0, base, 0, 0 };
    bfd_vma addr;
    dl_iterate_phdr (find_matching_file, &match);
    addr = base - match.base;
    if (match.file && strlen (match.file))
      return process_file (match.file, &addr, 1);
    else
      return process_file ("/proc/self/exe", &addr, 1);
  }

  std::vector<frame> backtrace_symbols (void* const* buffer, size_t size)
  {
    size_t stack_depth = size;

    std::vector<frame> frames;

    dbfd.init ();
    for (size_t x = 0; x < stack_depth; ++x)
      frames.push_back (resolve_frame (static_cast<char const*> (buffer[x])));

    return frames;
  }
};

static stacktrace stk;

char**
backtrace_symbols (void* const* buffer, int size)
{
  std::vector<stacktrace::frame> const frames = stk.backtrace_symbols (buffer, size);

  int const width = 30;
  size_t required = 0;
  for (auto it = frames.begin (),
            et = frames.end ();
       it != et; ++it)
    {
      required += it->file.length ();
      required += 1; // ':'
      required += intstr_len;
      required += width - 3;    // field width for file:line (-3 because a
                                // file and line both have at least 1
                                // character and we have ':' in between)
      required += it->func.length ();
      required += 1; // '\0'
    }

  size_t const memsize = required + frames.size () * sizeof (char*);
  char* const membase = static_cast<char*> (malloc (memsize));
  char* const memend  = membase + memsize;
  char** const syms = reinterpret_cast<char**> (membase);
  char* strings = membase + frames.size () * sizeof (char*);

  for (auto it = frames.begin (),
            et = frames.end ();
       it != et; ++it)
    {
      syms[it - frames.begin ()] = strings;
      char buf[it->file.length () + intstr_len + 2];
      snprintf (buf, sizeof buf, "%s:%lu", it->file.c_str (), it->line);
      strings += snprintf (strings, memend - membase,
                           "%-*s%s", width, buf, it->func.c_str ());
      ++strings; // '\0'
    }

  return syms;
}

char*
resolve_symbol (void* sym)
{
  return strdup (stk.resolve_frame (static_cast<char const*> (sym)).func.c_str ());
}
