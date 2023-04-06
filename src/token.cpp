#include "includes/token.h"
#include <sstream>

Token::Token(size_t _line_num, string _svalue, Type _type) {
  line_num = _line_num;
  svalue = _svalue;
  type = _type;

  switch (type) {
  case Type::INTEGER:
    ivalue = std::atoi(svalue.c_str());
    fvalue = 0.f;
    break;

  case Type::CHAR:
    ivalue = *svalue.c_str();
    fvalue = 0.f;

  case Type::FLOAT:
    fvalue = static_cast<float>(std::atof(svalue.c_str()));
    ivalue = 0;
    break;

  default:
    ivalue = 0;
    fvalue = 0.f;
    break;
  }
}

const string Token::to_string() {
  string type_str;

  switch (type) {
  case Type::EOF_:
    type_str = "EOF";
    break;

  case Type::NONE:
    type_str = "NONE";
    break;

  case Type::INTEGER:
    type_str = "INTEGER";
    break;

  case Type::FLOAT:
    type_str = "FLOAT";
    break;

  case Type::CHAR:
    type_str = "CHAR";
    break;

  case Type::STRING:
    type_str = "STRING";
    break;

  case Type::PLUS:
    type_str = "PLUS";
    break;

  case Type::PLUS_EQUAL:
    type_str = "PLUS_EQUAL";
    break;

  case Type::MINUS:
    type_str = "MINUS";
    break;

  case Type::MINUS_EQUAL:
    type_str = "MINUS_EQUAL";
    break;

  case Type::STAR:
    type_str = "STAR";
    break;

  case Type::STAR_EQUAL:
    type_str = "STAR_EQUAL";
    break;

  case Type::SLASH:
    type_str = "SLASH";
    break;

  case Type::SLASH_EQUAL:
    type_str = "SLASH_EQUAL";
    break;

  case Type::CARET:
    type_str = "CARET";
    break;

  case Type::SYMBOL:
    type_str = "SYMBOL";
    break;

  case Type::KEYWORD:
    type_str = "KEYWORD";
    break;

  case Type::LEFT_PAREN:
    type_str = "LEFT_PAREN";
    break;

  case Type::RIGHT_PAREN:
    type_str = "RIGHT_PAREN";
    break;

  case Type::LEFT_SQUARE:
    type_str = "LEFT_SQUARE";
    break;

  case Type::RIGHT_SQUARE:
    type_str = "RIGHT_SQUARE";
    break;

  case Type::LEFT_CURLY:
    type_str = "LEFT_CURLY";
    break;

  case Type::RIGHT_CURLY:
    type_str = "RIGHT_CURLY";
    break;

  case Type::EQUAL:
    type_str = "EQUAL";
    break;

  case Type::DOUBLE_EQUAL:
    type_str = "DOUBLE_EQUAL";
    break;

  case Type::NOT_EQUAL:
    type_str = "NOT_EQUAL";
    break;

  case Type::LESS:
    type_str = "LESS";
    break;

  case Type::LESS_EQUAL:
    type_str = "LESS_EQUAL";
    break;

  case Type::GREATER:
    type_str = "GREATER";
    break;

  case Type::GREATER_EQUAL:
    type_str = "GREATER_EQUAL";
    break;

  case Type::AND:
    type_str = "AND";
    break;

  case Type::OR:
    type_str = "OR";
    break;
  }

  sstream ss;

  ss << "Token<" << type_str << ", \"" << svalue << "\", " << ivalue << ", "
     << fvalue << ">";

  return ss.str();
}
