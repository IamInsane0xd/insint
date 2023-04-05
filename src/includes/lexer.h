#ifndef _LEXER_H
#define _LEXER_H

#include "includes.h"
#include "token.h"

class Lexer {
public:
  vec<Token> tokens;

  Lexer();
  Lexer(string src);
  inline ~Lexer(){};

  void reset();
  void next();
  char peek();
  char peek(int offset);
  void lex();

  inline void set_src(const string src) { m_src = src; }

private:
  string m_src;
  size_t m_current_line;
  size_t m_pos;
  char m_current;
};

#endif
