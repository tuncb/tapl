
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <variant>

import tapl;

int wmain(int argc, wchar_t* argv[])
{
  // enable wstring output to console
  [[maybe_unused]] const auto err = _setmode(_fileno(stdout), _O_U16TEXT);

  const auto arguments_maybe = tapl::parseCommandArguments(argc, argv);
  if (std::holds_alternative<std::wstring>(arguments_maybe)) {
    std::wcerr << std::get<std::wstring>(arguments_maybe) << '\n';
  }

  const auto arguments = std::get<tapl::CommandsArgumands>(arguments_maybe);
  std::wcout << "Processing file: " << arguments.filename << "\n";
}