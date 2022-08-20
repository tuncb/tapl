
#include <fcntl.h>
#include <io.h>
#include <iostream>

#include <string>
#include <vector>

import tapl;

struct CommandsArgumands
{
  std::wstring filename;
};

auto parseCommandArguments(const std::vector<std::wstring> &args) -> CommandsArgumands
{
  if (args.size() != 2)
    throw tapl::TaplError("Error: tapl expacts a single argument, tapl.exe <filename>");
  return CommandsArgumands{std::wstring{args[1]}};
}

int wmain(int argc, wchar_t *argv[])
{
  // enable wstring output to console
  [[maybe_unused]] const auto err = _setmode(_fileno(stdout), _O_U16TEXT);

  const auto args = std::vector<std::wstring>{argv, argv + argc};

  try
  {
    const auto arguments = parseCommandArguments(args);
    std::wcout << "Processing file: " << arguments.filename << "\n";
  }
  catch (const tapl::TaplError &err)
  {
    std::cerr << err.what() << "\n";
  }
}