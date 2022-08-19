module;
#include <stdexcept>

export module tapl:utility;

namespace tapl {
  export class TaplError : public std::runtime_error {
  public:
    TaplError(const std::string msg) : std::runtime_error(msg) {}
  };
}
