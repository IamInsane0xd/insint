#include "includes/lexer.h"
#include "includes/token.h"

Lexer::Lexer() { Lexer(""); }

Lexer::Lexer(string src) {
  tokens = vec<Token>();

  m_src = src;
  m_current_line = 1;
  m_pos = 0;
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
  if (m_pos + offset >= m_src.length())
    return '\0';

  return m_src.at(m_pos + offset);
}

void Lexer::lex() {
  next();

  string svalue;
  Token::Type type;

  // TODO: Lex symbols (and recognize keywords)

  // FIXME: Currently any whitespace character except the newline will throw an
  // error, as they are not handled
  while (m_current != '\0') {
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
      if (peek() == '=') {
        svalue = "+=";
        type = Token::Type::PLUS_EQUAL;
        next();
        break;
      }

      svalue = "+";
      type = Token::Type::PLUS;
      break;

    case '-':
      if (peek() == '=') {
        svalue = "-=";
        type = Token::Type::MINUS_EQUAL;
        next();
        break;
      }

      svalue = "-";
      type = Token::Type::MINUS;
      break;

    case '*':
      if (peek() == '=') {
        svalue = "*=";
        type = Token::Type::STAR_EQUAL;
        next();
        break;
      }

      svalue = "*";
      type = Token::Type::STAR;
      break;

    case '/':
      if (peek() == '=') {
        svalue = "/=";
        type = Token::Type::SLASH_EQUAL;
        next();
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
      if (peek() == '=') {
        svalue = "==";
        type = Token::Type::DOUBLE_EQUAL;
        next();
        break;
      }

      svalue = "=";
      type = Token::Type::EQUAL;
      break;

    case '<':
      if (peek() == '=') {
        svalue = "<=";
        type = Token::Type::LESS_EQUAL;
        next();
        break;
      }

      svalue = "<";
      type = Token::Type::LESS;
      break;

    case '>':
      if (peek() == '=') {
        svalue = ">=";
        type = Token::Type::GREATER_EQUAL;
        next();
        break;
      }

      svalue = ">";
      type = Token::Type::GREATER;
      break;

    case '&':
      if (peek() == '&') {
        svalue = "&&";
        type = Token::Type::AND;
        next();
        break;
      }

      // FIXME: Error handling
      assert(false && "Unrecognized token '&'");
      break;

    case '|':
      if (peek() == '|') {
        svalue = "||";
        type = Token::Type::OR;
        next();
        break;
      }

      assert(false && "Unrecognized token '|'");
      break;
    }

    tokens.push_back(Token(m_current_line, svalue, type));
  }
}
