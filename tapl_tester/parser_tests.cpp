#include <catch2/catch_all.hpp>

import tapl;

TEST_CASE("Test number parsing", "[parser]")
{
  using namespace tapl;

  REQUIRE(parse(u8"").tokens.empty());
  REQUIRE(tapl::parse(u8"23").tokens == std::vector<Token>{{TokenType::Number, 0, 2}});
  REQUIRE(tapl::parse(u8"23 35").tokens == std::vector<Token>{{TokenType::Number, 0, 2}, {TokenType::Number, 3, 5}});
  REQUIRE(tapl::parse(u8"23 35 65").tokens ==
          std::vector<Token>{{TokenType::Number, 0, 2}, {TokenType::Number, 3, 5}, {TokenType::Number, 6, 8}});
}
