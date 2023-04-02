#include "includes/includes.h"
#include <string>

int main() {
  string input;

  for (;;) {
    cout << ">>> ";
    std::getline(cin, input);
    cout << input << nl;
  }

  return 0;
}
