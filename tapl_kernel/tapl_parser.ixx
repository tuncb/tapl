module;
#include <ranges>
#include <string>
#include <vector>

export module tapl:parser;

namespace tapl
{
export enum class TokenType
{
  Number,
  None
};

export struct Token
{
  TokenType type;
  size_t start;
  size_t end;

  friend bool operator==(const Token &lhs, const Token &rhs)
  {
    return lhs.type == rhs.type && lhs.start == rhs.start && lhs.end == rhs.end;
  }
};

export struct ParseError
{
  size_t start;
  size_t end;
  int errorType;
};

export struct ParseResponse
{
  std::vector<Token> tokens;
  std::vector<ParseError> errors;
};

struct SkipTokenizer
{
  auto fits(const std::u8string &code, size_t pos) -> bool
  {
    const std::u8string skipped = u8" \t";
    return std::ranges::find(skipped, code[pos]) != skipped.end();
  }
};

struct IntegerTokenizer
{
  auto fits(const std::u8string &code, size_t pos) -> bool
  {
    const std::u8string integer_numbers = u8"0123456789";
    return std::ranges::find(integer_numbers, code[pos]) != integer_numbers.end();
  }

  auto type() -> TokenType
  {
    return TokenType::Number;
  }
};

export auto parse(const std::u8string &code) -> ParseResponse
{
  ParseResponse response;

  Token current_token{TokenType::None, 0, 0};

  const auto addToken = [&response](Token &token) -> void {
    response.tokens.push_back(token);
    token.type = TokenType::None;
  };

  SkipTokenizer skipper;
  IntegerTokenizer integer_tokenizer;

  for (size_t pos = 0; pos < code.size(); ++pos)
  {
    if (skipper.fits(code, pos))
    {
      if (current_token.type != TokenType::None)
      {
        addToken(current_token);
      }
      continue;
    }

    if (integer_tokenizer.fits(code, pos))
    {
      if (current_token.type == TokenType::None)
      {
        current_token = {TokenType::Number, pos, pos + 1};
      }
      else if (current_token.type == TokenType::Number)
      {
        ++current_token.end;
      }
      continue;
    }
  }

  if (current_token.type != TokenType::None)
  {
    addToken(current_token);
  }

  return response;
}

} // namespace tapl