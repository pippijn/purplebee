/* Copyright © 2010 Pippijn van Steenhoven
 * See COPYING.AGPL for licence information.
 */
#pragma once

#include <sstream>

#include <pthread.h>

#include "util/common.h"
#include "util/funcall.h"
#include "util/output.h"
#include "util/type_traits/decay_array.h"
#include "util/xassert.h"

// This class holds a stringstream it writes to. It provides transactional
// behaviour for debug output using a mutex and pretty printing of anything
// supported by the "output" functions from util/output.h.
// This class's functions are not reentrant, so don't use it from the actual
// printing function.
class debug_stream
{
  // This class really does almost nothing, it just holds the debug_stream
  // reference and locks on construction/unlocks on destruction. We have this
  // in a non-template base class so we can define its members non-inline.
  // Translation units using debug_stream tend to take *really* long to
  // compile due to the heavy template magic used below.
  struct transaction_base
  {
  protected:
    transaction_base (debug_stream& dout);
    transaction_base (transaction_base&& other);
    ~transaction_base ();

    debug_stream& dout;
    padded (bool) owns;
  };

  // The actual class providing atomic transactions. It's a mere helper class
  // for the atomic() function in debug_stream. It is returned by atomic() and
  // is callable so we can write: dout.atomic (output_function) (a, b, c);
  template<typename ClosureT>
  struct transaction
    : private transaction_base
  {
    transaction (transaction_base const& other) = delete;
    transaction & operator = (transaction_base const& rhs) = delete;

    transaction (debug_stream& dout, ClosureT const& closure)
      : transaction_base (dout)
      , closure (closure)
    {
    }

    transaction (transaction&& other)
      : transaction_base (other)
      , closure (std::move (other.closure))
    {
    }

    // End of recursion. Invokes the saved closure (which may be just a
    // function but in our case, it is a purple debug function along with the
    // debug channel string (category). This function resets the output
    // stream content.
    void print ()
    {
      invoke_closure (closure, "%s", dout.out.str ().c_str ());
      dout.out.str ("");
    }

    // Uses dout's operator << to print all arguments passed.
    template<typename T, typename... Args>
    void print (T const& arg, Args const&... rest)
    {
      dout << arg;
      print (rest...);
    }

    template<typename... Args>
    void operator () (Args const&... args)
    {
      print (args...);
    }

    ClosureT closure;
  };

public:
  // Initialises the mutex.
  debug_stream ();
  // Destroys the mutex.
  ~debug_stream ();

  // Called at the end of a transaction to write the debug text
  // using the passed function (could be a pointer or copyable object).
  // After that, this function resets the output stream and unlocks it.
  template<typename FuncT, typename... PreArgs>
  void release (FuncT function, PreArgs const&... preargs)
  {
    function (preargs..., "%s", out.str ().c_str ());
    out.str ("");
    unlock ();
  }

  // Begins a transaction. The return value of this function can be stored
  // and as long as it exists, it can be used to write debug messages to the
  // closure created here.
  template<typename FuncT, typename... PreArgs>
  transaction<std::tuple<FuncT, typename decay_array<PreArgs>::type...>>
  atomic (FuncT function, PreArgs const&... preargs)
  {
    return transaction<std::tuple<FuncT, typename decay_array<PreArgs>::type...>>
             (*this, std::make_tuple (function, preargs...));
  }

  // Provides raw std::ostream formatting.
  // Requires the stream to be locked.
  template<typename T>
  debug_stream& operator << (T const& v)
  {
    xassert (!is_locked ());
    out << v;
    return *this;
  }

  // Provides prettyprinting using "output".
  template<typename T>
  void pretty (T const& v)
  {
    output (v, out);
  }

  // Acquires a lock on the debug stream. This lock must be manually released
  // with the release function. For automatic locking, use atomic(). This function
  void acquire ();

private:
  // Locks the stream.
  int lock ();
  // Unlocks the stream.
  int unlock ();

  // Returns whether the stream is locked.
  bool is_locked ();

  // Our internal output stream.
  std::ostringstream out;
  // The mutex used to lock the output stream.
  pthread_mutex_t mtx;
};

// We have one global debug stream. If you want to debug inside a debug
// handler, you will need another one.
extern debug_stream dout;
