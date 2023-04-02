#ifndef _LEXER_H
#define _LEXER_H

#include "includes.h"
#include "token.h"

class Lexer {
public:
  vec<Token> tokens;

  Lexer(string src);
  inline ~Lexer(){};

private:
  string m_src;
  size_t m_pos;
  size_t m_current_line;
};

#endif
