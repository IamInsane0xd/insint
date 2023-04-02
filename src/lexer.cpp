#include "includes/lexer.h"
#include "includes/token.h"

Lexer::Lexer(string src) {
  m_src = src;
  m_pos = 0;
  tokens = vec<Token>();
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

void Lexer::lex() {}
