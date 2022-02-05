
#define DIGIT 0
#define PLUS 1
#define MINUS 2
#define MUL 3
#define DIV 4

struct Node {
  Node *left{}, *right{};
  char data;
  Node(char c) : data{c} {}
};

int get_operation(char c) {
  switch (c) {
    case '+': return PLUS;
    case '-': return MINUS;
    case '*': return MUL;
    case '/': return DIV;
    default:  return DIGIT;
  }
}

#include <climits>
double evaluate_tree(Node* node) {
  if (node==nullptr) return INT_MIN;  // covers null tree or wrong equations

  int op = get_operation(node->data);
  if (op == DIGIT) return (double) node->data-'0';

  double left = (double) evaluate_tree(node->left);
  double right = (double) evaluate_tree(node->right);

  if (left == INT_MIN || right == INT_MIN) return INT_MIN;

  switch(op) {
    case PLUS:  return left + right;
    case MINUS: return left - right;
    case MUL:   return left * right;
    case DIV: {
      if (right==0) return INT_MIN;
      return left / right;
    }
    default: return INT_MIN;
  }
}



#include "test/050.h"
int main() { run_tests(); return 0; }