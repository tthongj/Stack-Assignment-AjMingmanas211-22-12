#include <iostream>
#include <cstring>
#include "stack.h"

int main(int argc, char* argv[]) {
  Stack s;
  int match;
  int i, j;
  char c;
  char openc = 0, closec = 0; // Initialize openc and closec to 0

  for (j = 1; j < argc; j++) {
    match = 1;
    openc = 0; // Reset openc for each argument
    closec = 0; // Reset closec for each argument

    for (i = 0; i < strlen(argv[j]); i++) {
      switch (argv[j][i]) {
        case '[':
          s.push(argv[j][i]);
          openc++; // Increment openc for each opening bracket
          break;
        case '{':
          s.push(argv[j][i]);
          openc++; // Increment openc for each opening brace
          break;
        case ']':
          c = s.pop();
          if (c != '[') match = 0; // Not a match
          closec++; // Increment closec for each closing bracket
          break;
        case '}':
          c = s.pop();
          if (c != '{') match = 0; // Not a match
          closec++; // Increment closec for each closing brace
          break;
      }
    }

    if (match == 0) {
      cout << "Parentheses do not match: too many parenthesis" << endl;
    } else if (openc > closec) {
      cout << "Not match: too many opening parentheses" << endl;
    } else if (openc < closec) {
      cout << "Not match: too many closing parentheses" << endl;
    } else {
      cout << "Parentheses match" << endl;
    }
  }

  return 0;
}
