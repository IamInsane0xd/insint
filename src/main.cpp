#include "includes/includes.h"
#include "includes/lexer.h"
#include "includes/token.h"

int main() {
  Lexer lexer;
  string input;

  for (;;) {
    cout << ">>> ";
    std::getline(cin, input);

    lexer.set_src(input);
    lexer.lex();

    for (size_t i = 0; i < lexer.tokens.size(); i++) {
      cout << lexer.tokens.at(i).to_string() << nl;
    }
  }

  return 0;
}
