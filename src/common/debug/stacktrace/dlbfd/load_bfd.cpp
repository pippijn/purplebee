/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include "common/util/force_assign.h"
#include "common/util/string.h"

#include "../stacktrace.h"

#if HAVE_BFD_H
template<typename To>
bool
load_symbol (void* handle, To& target, char const* symname, std::string& error)
{
  force_assign (target, dlsym (handle, symname));
  if (target)
    return true;

  error += "\n\tcould not resolve symbol: " + std::string (symname);
  return false;
}

bool
load_bfd_symbols (stacktrace::dlbfd& self, std::string& errors)
{
  return load_symbol (self.handle, self.init,                 "bfd_init", errors)
      && load_symbol (self.handle, self.map_over_sections,    "bfd_map_over_sections", errors)
      && load_symbol (self.handle, self.check_format,         "bfd_check_format", errors)
      && load_symbol (self.handle, self.check_format_matches, "bfd_check_format_matches", errors)
      && load_symbol (self.handle, self.openr,                "bfd_openr", errors)
      && load_symbol (self.handle, self.close,                "bfd_close", errors)
      ;
}

bool
try_load_bfd (stacktrace::dlbfd& self, char const* path, std::string& errors)
{
  // we might have tried loading the symbols from another object, before
  if (self.handle)
    dlclose (self.handle);
  // if we can load the given object
  if ((self.handle = dlopen (path, RTLD_NOW)))
    // try loading the needed bfd symbols from it
    return load_bfd_symbols (self, errors);

  errors += "\n\t";
  errors += dlerror ();

  return false;
}

// try *really* hard to find libbfd.so and load the symbols
bool
load_bfd (stacktrace::dlbfd& self, std::string& errors)
{
  // first, just see if it's there
  if (try_load_bfd (self, "libbfd.so", errors))
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
              if (try_load_bfd (self, ent->d_name, errors))
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
#endif
