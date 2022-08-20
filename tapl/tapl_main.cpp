
#include <fcntl.h>
#include <io.h>
#include <iostream>

import tapl;

int wmain(int argc, wchar_t *argv[])
{
  // enable wstring output to console
  [[maybe_unused]] const auto err = _setmode(_fileno(stdout), _O_U16TEXT);

  try
  {
    const auto arguments = tapl::parseCommandArguments(argc, argv);
    std::wcout << "Processing file: " << arguments.filename << "\n";
  }
  catch (const tapl::TaplError &err)
  {
    std::cerr << err.what() << "\n";
  }
}