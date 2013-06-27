#pragma once

enum class parse_status
{
  success,
  failure,
  resume,
};

parse_status parse_arguments (int argc, char** argv);
