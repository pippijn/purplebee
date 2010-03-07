/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <cstdlib>

namespace detail
{
  struct empty_phoenix_initialiser
  {
    template<typename T>
    void operator () (T &)
    {
    }
  };
}

template<typename Base, typename Context = Base, typename Initialiser = detail::empty_phoenix_initialiser>
struct phoenix
  : Base
{
  typedef Base                base_type;
  typedef Context             context_type;
  typedef Initialiser         initialiser_type;

  static base_type &instance ()
  {
    static phoenix object;
    static bool donethat = false;

    if (phoenix::destroyed)
      {
        donethat = false;
        new (&object) phoenix;
        atexit (phoenix::destroy);
      }

    if (!donethat)
      {
        donethat = true;
        initialiser_type () (object);
      }

    return object;
  }

private: // types
  typedef phoenix<base_type, context_type, initialiser_type> this_type;

private: // functions
  phoenix () throw ()
  {
    destroyed = false;
  }

  ~phoenix () throw ()
  {
    destroyed = true;
  }

  static void destroy ()
  {
    if (destroyed)
      return;
    static_cast<phoenix &> (instance ()).~phoenix ();
  }

private: // variables
  static bool destroyed;
};

template<typename BaseType, typename ContextType, typename InitialiserType>
bool phoenix<BaseType, ContextType, InitialiserType>::destroyed = false;
