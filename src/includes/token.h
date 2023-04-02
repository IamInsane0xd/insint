#ifndef _TOKEN_H
#define _TOKEN_H

#include "includes.h"

class Token {
public:
  enum class Type {
    EOF_ = -1,
    INTEGER,
    FLOAT,
    CHAR,
    STRING,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    CARET,
    ARROW,
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
    BIGGER,
    BIGGER_EQUAL,
    AND,
    OR,
    SEMICOLON,
    TYPE_MAX,
  };

  Token(size_t _line_num, string _svalue, Type _type);
  inline ~Token(){};

  size_t line_num;
  string svalue;
  llong ivalue;
  float fvalue;
  Type type;
};

#endif
