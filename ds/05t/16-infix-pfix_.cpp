#include <cctype>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  if (op == '^') return 3;
  return 0;
}

bool left_assoc(char op) {
  return op != '^';
}

bool should_pop(char top, char op) {
  if (top == '(') return false;
  if (precedence(top) > precedence(op)) return true;
  return precedence(top) == precedence(op) && left_assoc(op);
}

string infix_to_postfix(string input) {
  string output;
  stack<char> ops;

  for (char c: input) {
    if (isspace(c)) continue;

    if (isalnum(c)) {
      output += c;
    } else if (c == '(') {
      ops.push(c);
    } else if (c == ')') {
      while (!ops.empty() && ops.top() != '(') {
        output += ops.top();
        ops.pop();
      }
      ops.pop();
    } else {
      while (!ops.empty() && should_pop(ops.top(), c)) {
        output += ops.top();
        ops.pop();
      }
      ops.push(c);
    }
  }

  while (!ops.empty()) {
    output += ops.top();
    ops.pop();
  }

  return output;
}

#include "test/16-infix-pfix.h"
int main() { run_tests(); return 0; }
