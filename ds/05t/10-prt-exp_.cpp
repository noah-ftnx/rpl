#include <string>
#include <iostream>
using namespace std;

struct Node {
  Node* left {};
  Node* right {};
  Node* parent {};
  char data;

  Node(char c) : data{c} {}
};

class Tree {
 private:
  Node* root = {};

 public:
  Tree(const string& postfix); // given

  // delete copy op, default ctor, and copy ctor
  const Tree& operator=(const Tree&) = delete;
  Tree(const Tree&) = delete;
  Tree() = delete;

  string _to_string(Node* node, bool is_root=false) {
    if (node == nullptr) return "";

    bool skipParenthesis = (!node->left && !node->right) || is_root;

    string res;
    if (!skipParenthesis) res+="(";
    res+=_to_string(node->left) + node->data + _to_string(node->right);
    if (!skipParenthesis) res+=")";
    return res;
  }

  string to_string() { return _to_string(root, true); }

};

#include "test/10-prtfix.h"
int main() { run_tests(); return 0; }