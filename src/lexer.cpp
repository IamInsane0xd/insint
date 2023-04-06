#include "includes/lexer.h"
#include "includes/token.h"

Lexer::Lexer() { Lexer(""); }

Lexer::Lexer(string src) {
  tokens = vec<Token>();

  m_src = src;
  m_current_line = 1ul;
  m_pos = 0ul;
  m_current = '\0';
}

void Lexer::reset() {
  tokens.clear();

  m_src = "";
  m_current_line = 1ul;
  m_pos = 0ul;
  m_current = '\0';
}

void Lexer::next() {
  if (m_pos >= m_src.length()) {
    m_current = '\0';
    return;
  }

  m_current = m_src.at(m_pos++);
}

char Lexer::peek() { return peek(1); }

char Lexer::peek(int offset) {
  if (m_pos - 1 + offset >= m_src.length())
    return '\0';

  return m_src.at(m_pos - 1 + offset);
}

/// @brief Peeks the next character and matches it with the expected next
/// character. If it matches, it also calls next()
/// @returns A boolean like value, 1 for success, 0 for failure
int Lexer::match(char _next) {
  if (peek() == _next) {
    next();
    return 1;
  }

  return 0;
}

void Lexer::lex() {
  next();

  string svalue;
  Token::Type type;
  int error;
  sstream error_msg;

  // TODO: Lex symbols (and recognize keywords)

  // FIXME: Currently any whitespace character except the newline will throw an
  // error, as they are not handled
  while (m_current != '\0') {
    error = 0;
    error_msg.str(string());

    while (std::isspace(m_current)) {
      next();
      continue;
    }

    switch (m_current) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      // TODO: Lex integer or float
      break;

    case '\'':
      // TODO: Lex character
      break;

    case '"':
      // TODO: Lex string
      break;

    case '+':
      if (match('=')) {
        svalue = "+=";
        type = Token::Type::PLUS_EQUAL;
        break;
      }

      svalue = "+";
      type = Token::Type::PLUS;
      break;

    case '-':
      if (match('=')) {
        svalue = "-=";
        type = Token::Type::MINUS_EQUAL;
        break;
      }

      svalue = "-";
      type = Token::Type::MINUS;
      break;

    case '*':
      if (match('=')) {
        svalue = "*=";
        type = Token::Type::STAR_EQUAL;
        break;
      }

      svalue = "*";
      type = Token::Type::STAR;
      break;

    case '/':
      if (match('=')) {
        svalue = "/=";
        type = Token::Type::SLASH_EQUAL;
        break;
      }

      svalue = "/";
      type = Token::Type::SLASH;
      break;

    case '^':
      svalue = "^";
      type = Token::Type::CARET;
      break;

    case '(':
      svalue = "(";
      type = Token::Type::LEFT_PAREN;
      break;

    case ')':
      svalue = ")";
      type = Token::Type::RIGHT_PAREN;
      break;

    case '[':
      svalue = "[";
      type = Token::Type::LEFT_SQUARE;
      break;

    case ']':
      svalue = "]";
      type = Token::Type::RIGHT_SQUARE;
      break;

    case '{':
      svalue = "{";
      type = Token::Type::LEFT_CURLY;
      break;

    case '}':
      svalue = "}";
      type = Token::Type::RIGHT_CURLY;
      break;

    case '=':
      if (match('=')) {
        svalue = "==";
        type = Token::Type::DOUBLE_EQUAL;
        break;
      }

      svalue = "=";
      type = Token::Type::EQUAL;
      break;

    case '!':
      if (match('=')) {
        svalue = "!=";
        type = Token::Type::NOT_EQUAL;
        break;
      }

      error = 1;
      error_msg << "Unrecognized token '" << m_current << "'";
      break;

    case '<':
      if (match('=')) {
        svalue = "<=";
        type = Token::Type::LESS_EQUAL;
        break;
      }

      svalue = "<";
      type = Token::Type::LESS;
      break;

    case '>':
      if (match('=')) {
        svalue = ">=";
        type = Token::Type::GREATER_EQUAL;
        break;
      }

      svalue = ">";
      type = Token::Type::GREATER;
      break;

    case '&':
      if (match('&')) {
        svalue = "&&";
        type = Token::Type::AND;
        break;
      }

      error = 1;
      error_msg << "Unrecognized token '" << m_current << "'";
      break;

    case '|':
      if (match('|')) {
        svalue = "||";
        type = Token::Type::OR;
        next();
        break;
      }

      error = 1;
      error_msg << "Unrecognized token '" << m_current << "'";
      break;

    default:
      error = 1;
      error_msg << "Unrecognized token '" << m_current << "'";
      break;
    }

    if (error) {
      cout << "Lexing error on line " << m_current_line << ": "
           << error_msg.str() << nl;

      tokens.clear();
      return;
    }

    tokens.push_back(Token(m_current_line, svalue, type));
    next();
  }

  tokens.push_back(Token(m_current_line, "", Token::Type::EOF_));
}
