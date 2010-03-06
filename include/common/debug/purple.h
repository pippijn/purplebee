/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <string>

#include <purple.h>

namespace purple
{
  template<typename T>
  char const* va_listise (std::string&& str, T const& arg);

  template<typename... Args>
  static inline void
  debug (PurpleDebugLevel level, char const* category, char const* format, Args const&... args)
  {
    purple_debug (level, category, format, va_listise (std::string (), args)...);
  }

  template<typename... Args>
  static inline void
  debug_misc (char const* category, char const* format, Args const&... args)
  {
    purple_debug_misc (category, format, va_listise (std::string (), args)...);
  }

  template<typename... Args>
  static inline void
  debug_info (char const* category, char const* format, Args const&... args)
  {
    purple_debug_info (category, format, va_listise (std::string (), args)...);
  }

  template<typename... Args>
  static inline void
  debug_warning (char const* category, char const* format, Args const&... args)
  {
    purple_debug_warning (category, format, va_listise (std::string (), args)...);
  }

  template<typename... Args>
  static inline void
  debug_error (char const* category, char const* format, Args const&... args)
  {
    purple_debug_error (category, format, va_listise (std::string (), args)...);
  }

  template<typename... Args>
  static inline void
  debug_fatal (char const* category, char const* format, Args const&... args)
  {
    purple_debug_fatal (category, format, va_listise (std::string (), args)...);
  }
}
