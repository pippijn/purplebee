/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

template<typename T>
struct auto_free
{
  auto_free (auto_free const& rhs) = delete;
  auto_free& operator = (auto_free const& rhs) = delete;

  explicit auto_free (T& ptr)
    : ptr (ptr)
  {
  }

  ~auto_free ()
  {
    free (ptr);
    ptr = NULL;
  }

  auto_free& operator = (T ptr)
  {
    this->ptr = ptr;
    return *this;
  }

  T& ptr;
};

#define auto_free(ptr) auto_free<decltype (ptr)> PASTE (auto_free_, __LINE__) (ptr); PASTE (auto_free_, __LINE__)
