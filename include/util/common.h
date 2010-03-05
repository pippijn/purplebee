#pragma once

#ifdef __cplusplus
# define BEGIN_DECLS            extern "C" {
# define END_DECLS              }
# define DEFAULT_ARG(arg)       = arg
# define NOTHROW                throw ()
#else
# define BEGIN_DECLS
# define END_DECLS
# define DEFAULT_ARG(arg)
# define NOTHROW
#endif
