#include "includes/token.h"

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
    fvalue = std::atof(svalue.c_str());
    ivalue = 0;
    break;

  default:
    ivalue = 0;
    fvalue = 0.f;
    break;
  }
}
