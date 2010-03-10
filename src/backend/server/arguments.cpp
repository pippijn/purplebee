#include <cstring>
#include <vector>

#include <argtable2.h>
#include <purple.h>

#include "arguments.h"

template<typename T>
static T*
push (std::vector<void*>& table, T* arg)
{
  table.push_back (arg);
  return arg;
}

static void
set_prgname (char const* arg0)
{
  char const* prgname = strrchr (arg0, '/');
  if (prgname)
    ++prgname;
  else
    prgname = arg0;
  g_set_prgname (prgname);
}

parse_status
parse_arguments (int argc, char** argv)
{
  if (argc < 1)
    return parse_status::failure;

  set_prgname (argv[0]);

  std::vector<void*> table;

  auto help     = push (table, arg_lit0 (NULL, "help"   , "display this help text and exit"));
  auto version  = push (table, arg_lit0 (NULL, "version", "output version information and exit"));
  auto end      = push (table, arg_end (20));

  void** const argtable = &table[0];

  if (arg_nullcheck (argtable))
    {
      printf ("%s: insufficient memory\n", g_get_prgname ());
      return parse_status::failure;
    }

  int error_count = arg_parse (argc, argv, argtable);

  if (help->count)
    {
      printf ("Usage: %s", g_get_prgname ());
      arg_print_syntax (stdout, argtable, "\n");
      arg_print_glossary_gnu (stdout, argtable);
      printf ("Report %s bugs to %s\n", PACKAGE_NAME, PACKAGE_BUGREPORT);
      printf ("Also see the documentation at %s\n", PACKAGE_URL);
      return parse_status::success;
    }

  if (version->count)
    {
      printf ("%s version %s\n", PACKAGE_NAME, PACKAGE_VERSION);
      printf ("Copyright © 2010 The %s development team\n", PACKAGE_NAME);
      puts ("This program is GPLv3+: <http://gnu.org/licenses/gpl.html>");
      puts ("Individual source files are AGPLv3+: <http://gnu.org/licenses/agpl.html>");
      puts ("");
      puts ("Written by Pippijn van Steenhoven and Moritz Wilhelmy");
      arg_freetable (argtable, table.size ());
      return parse_status::success;
    }

  if (error_count > 0)
    {
      arg_print_errors (stdout, end, g_get_prgname ());
      printf ("Try `%s --help' for more information.\n", g_get_prgname ());
      arg_freetable (argtable, table.size ());
      return parse_status::failure;
    }

  arg_freetable (argtable, table.size ());
  return parse_status::resume;
}
