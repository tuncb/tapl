module;
#include <string>

export module tapl:args;
import :utility;

namespace tapl {
  export struct CommandsArgumands {
    std::wstring filename;
  };

  export auto parseCommandArguments(int argc, wchar_t* argv[]) -> CommandsArgumands {
    if (argc != 2) throw TaplError("Error: tapl expacts a single argument, tapl.exe <filename>");
    return CommandsArgumands{ std::wstring{argv[1]} };
  }
}
