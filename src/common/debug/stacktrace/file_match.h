/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
struct stacktrace::file_match
{
  const char* file;
  char const* address;
  char const* base;
  void* hdr;
};
