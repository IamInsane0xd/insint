#include "includes/lexer.h"

Lexer::Lexer(string src) {
  m_src = src;
  m_pos = 0;
  tokens = vec<Token>();
}
