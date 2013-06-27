/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#include <unordered_map>

#include "common/util/phoenix.h"

#include "stacktrace.h"

#if HAVE_BFD_H
#include "frame.h"
#include "file_match.h"

stacktrace::frame
stacktrace::resolve_frame_internal (char const* base)
{
  auto& cache = phoenix<std::unordered_map<void const*, frame>>::instance ();
#if 0
  auto found = cache.find (base);
  if (found != cache.end ())
    return found->second;
#endif

  file_match match { 0, base, 0, 0 };
  dl_iterate_phdr (find_matching_file, &match);
  bfd_vma addr = base - match.base;
  if (match.file && strlen (match.file))
    return cache[base] = std::move (process_file (match.file, &addr, 1));
  else
    return cache[base] = std::move (process_file ("/proc/self/exe", &addr, 1));
}
#endif
