#ifndef _TOKEN_H
#define _TOKEN_H

#include "includes.h"

class Token {
public:
  enum class Type {
    EOF_ = -1,
    NONE,
    INTEGER,
    FLOAT,
    CHAR,
    STRING,
    PLUS,
    PLUS_EQUAL,
    MINUS,
    MINUS_EQUAL,
    STAR,
    STAR_EQUAL,
    SLASH,
    SLASH_EQUAL,
    CARET,
    SYMBOL,
    KEYWORD,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_SQUARE,
    RIGHT_SQUARE,
    LEFT_CURLY,
    RIGHT_CURLY,
    EQUAL,
    DOUBLE_EQUAL,
    LESS,
    LESS_EQUAL,
    GREATER,
    GREATER_EQUAL,
    AND,
    OR,
  };

  size_t line_num;
  string svalue;
  llong ivalue;
  float fvalue;
  Type type;

  Token(size_t _line_num, string _svalue, Type _type);
  inline ~Token(){};

  const string to_string();
};

#endif
