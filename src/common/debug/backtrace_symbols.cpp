/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <vector>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#if HAVE_BFD_H
#include <bfd.h>
#include <cxxabi.h>
#include <dirent.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <link.h>
#include <pthread.h>
#endif

#include "common/debug/backtrace.h"
#include "common/util/phoenix.h"
#include "common/util/string.h"
#include "common/util/xassert.h"

#define fatal(a, b) exit (1)
#define bfd_fatal(a) exit (1)
#define bfd_nonfatal(a) exit (1)
#define list_matching_formats(a) exit (1)

static size_t const intstr_len = log (SIZE_MAX) / log (10) + 1;
static size_t const ptrstr_len = log (SIZE_MAX) / log (16) + 1 + 2; // for "0x"

template<typename To, typename From>
static bool
force_assign (To& target, From source)
{
  return (target = reinterpret_cast<To> (source));
}

struct stacktrace
{
  struct frame
  {
    std::string func;
    std::string file;
    unsigned long line;
  };

#if HAVE_BFD_H
private:
  struct dlbfd
  {
    void* handle;

    decltype (bfd_init)* init;
    decltype (bfd_map_over_sections)* map_over_sections;
    decltype (bfd_check_format)* check_format;
    decltype (bfd_check_format_matches)* check_format_matches;
    decltype (bfd_openr)* openr;
    decltype (bfd_close)* close;

    template<typename To>
    bool load_symbol (To& target, char const* symname, std::string& error)
    {
      force_assign (target, dlsym (handle, symname));
      if (target)
        return true;

      error += "\n\tcould not resolve symbol: " + std::string (symname);
      return false;
    }

    bool load_bfd_symbols (std::string& errors)
    {
      return load_symbol (init,                 "bfd_init", errors)
          && load_symbol (map_over_sections,    "bfd_map_over_sections", errors)
          && load_symbol (check_format,         "bfd_check_format", errors)
          && load_symbol (check_format_matches, "bfd_check_format_matches", errors)
          && load_symbol (openr,                "bfd_openr", errors)
          && load_symbol (close,                "bfd_close", errors)
          ;
    }

    bool try_load_bfd (char const* path, std::string& errors)
    {
      // we might have tried loading the symbols from another object, before
      if (handle)
        dlclose (handle);
      // if we can load the given object
      if ((handle = dlopen (path, RTLD_NOW)))
        // try loading the needed bfd symbols from it
        return load_bfd_symbols (errors);

      errors += "\n\t";
      errors += dlerror ();

      return false;
    }

    // try *really* hard to find libbfd.so and load the symbols
    bool load_bfd (std::string& errors)
    {
      // first, just see if it's there
      if (try_load_bfd ("libbfd.so", errors))
        return true;
    
      // then, look through common library dirs to see if something that
      // looks like libbfd.so can be found
      char const* dirs[] = {
        "/lib",
        "/usr/lib",
        "/usr/local/lib",
        NULL
      };
    
      for (char const** dirit = dirs; *dirit; ++dirit)
        {
          char const* const dirname = *dirit;
          DIR* dirp = opendir (dirname);
          if (dirp)
            {
              while (dirent* ent = readdir (dirp))
                if (!strncmp (ent->d_name, "libbfd"))
                  if (try_load_bfd (ent->d_name, errors))
                    return true;
            }
          else
            {
              errors += "\n\t";
              errors += dirname;
              errors += ": ";
              errors += strerror (errno);
            }
        }
    
      return false;
    }

#define DLBFD 1
    dlbfd ()
      : handle (0)
    {
#if DLBFD
      std::string errors;

      if (!load_bfd (errors))
        {
          // we tried so hard but failed in the end
          // that probably means it's not there, so bail out
          fprintf (stderr, "unable to load BFD library, backtrace will not be available:%s\n",
                   errors.c_str ());
          handle = 0;
        }
#define bfd_init                  dbfd.init
#define bfd_map_over_sections     dbfd.map_over_sections
#define bfd_check_format          dbfd.check_format
#define bfd_check_format_matches  dbfd.check_format_matches
#define bfd_openr                 dbfd.openr
#define bfd_close                 dbfd.close
#endif
    }

    ~dlbfd ()
    {
#if DLBFD
      if (handle)
        dlclose (handle);
#endif
    }
  };

  pthread_mutex_t mtx;
  asymbol** syms;       // Symbol table
  dlbfd dbfd;

  // These global variables are used to pass information between
  // translate_addresses and find_address_in_section.
  bfd_vma pc;
  const char* filename;
  const char* funcname;
  unsigned int line;
  padded (bool) found;

  bool check_bfd ()
  {
#if DLBFD
    return dbfd.handle;
#else
    return true;
#endif
  }

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
                                         &self->filename, &self->funcname, &self->line);
  }

  frame translate_addresses (bfd* abfd, bfd_vma* addr, int naddr)
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
        return { func, filename, line };
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

    xassert (!syms);
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
                force_assign (match->file, info->dlpi_name);
                force_assign (match->base, info->dlpi_addr);
              }
          }
      }
    return 0;
  }

  frame resolve_frame_internal (char const* base)
  {
    auto& cache = phoenix<std::unordered_map<void const*, frame>>::instance ();
    auto found = cache.find (base);
    if (found != cache.end ())
      return found->second;

    file_match match { 0, base, 0, 0 };
    dl_iterate_phdr (find_matching_file, &match);
    bfd_vma addr = base - match.base;
    if (match.file && strlen (match.file))
      return cache[base] = process_file (match.file, &addr, 1);
    else
      return cache[base] = process_file ("/proc/self/exe", &addr, 1);
  }

public:
  stacktrace ()
    : syms (0)
    , dbfd ()
    , pc (0)
    , filename ("file")
    , funcname ("func")
    , line (0)
    , found (false)
  {
    bfd_init ();
    xassert (pthread_mutex_init (&mtx, NULL) == 0);
  }

  ~stacktrace ()
  {
    xassert (pthread_mutex_destroy (&mtx) == 0);
  }
#else
#define check_bfd() false
#endif

  frame resolve_frame (void const* base)
  {
    xassert (base);
    if (!check_bfd ())
      return { "func", "file", 0 };

#if HAVE_BFD_H
    xassert (pthread_mutex_lock (&mtx) == 0);

    frame frame = resolve_frame_internal (static_cast<char const*> (base));

    xassert (pthread_mutex_unlock (&mtx) == 0);

    return frame;
#endif
  }

  std::vector<frame> backtrace_symbols (void* const* buffer, size_t size)
  {
    xassert (buffer);
    xassert (size > 0);

    size_t stack_depth = size;
    std::vector<frame> frames;

    if (!check_bfd ())
      {
        for (size_t x = 0; x < stack_depth; ++x)
          frames.emplace_back (frame { "func", "file", 0 });
        return frames;
      }

#if HAVE_BFD_H
    xassert (pthread_mutex_lock (&mtx) == 0);

    for (size_t x = 0; x < stack_depth; ++x)
      frames.push_back (resolve_frame_internal (static_cast<char const*> (buffer[x])));

    xassert (pthread_mutex_unlock (&mtx) == 0);

    return frames;
#endif
  }
};

static stacktrace stk;


char**
backtrace_symbols (void* const* buffer, int size) throw ()
try
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
      ptrdiff_t i = it - frames.begin ();
      syms[i] = strings;
      char buf[it->file.length () + intstr_len + 2];
      if (it->line)
        snprintf (buf, sizeof buf, "%s:%lu", it->file.c_str (), it->line);
      else
        snprintf (buf, sizeof buf, "%s:???", it->file.c_str ());
      strings += snprintf (strings, memend - membase,
                           "%-*s%s", width, buf, it->func.c_str ());
      ++strings; // '\0'
    }

  return syms;
}
catch (...)
{
  puts ("caught unexpected exception while building backtrace");
  return NULL;
}

frame*
backtrace_frames (void* const* buffer, int size) throw ()
try
{
  std::vector<stacktrace::frame> const frames = stk.backtrace_symbols (buffer, size);

  frame* const ret = new frame[frames.size () + 1] ();

  for (auto it = frames.begin (),
            et = frames.end ();
       it != et; ++it)
    {
      ptrdiff_t i = it - frames.begin ();

      std::copy (it->func.begin (), it->func.end (), ret[i].func);
      ret[i].func[it->func.length ()] = '\0';

      std::copy (it->file.begin (), it->file.end (), ret[i].file);
      ret[i].file[it->file.length ()] = '\0';

      ret[i].line = it->line;
    }

  return ret;
}
catch (...)
{
  puts ("caught unexpected exception while building backtrace");
  return NULL;
}

char*
resolve_symbol (void const* sym) throw ()
try
{
  return strdup (stk.resolve_frame (sym).func.c_str ());
}
catch (...)
{
  puts ("caught unexpected exception while building backtrace");
  return NULL;
}
