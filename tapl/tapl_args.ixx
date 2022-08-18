module;
#include <string>
#include <variant>

export module tapl:args;

namespace tapl {
  export struct CommandsArgumands {
    std::wstring filename;
  };

  export auto parseCommandArguments(int argc, wchar_t* argv[]) -> std::variant<CommandsArgumands, std::wstring> {
    using namespace std::literals;
    if (argc != 2) return std::wstring{ L"Error: tapl expacts a single argument, tapl.exe <filename>" };
    return CommandsArgumands{ std::wstring{argv[1]} };
  }
}
