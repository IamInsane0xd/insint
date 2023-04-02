#ifndef _LEXER_H
#define _LEXER_H

#include "includes.h"

class Lexer {
public:
  Lexer();
  ~Lexer();

  void lex();

private:
  string m_src;
};

#endif
