#include <string>
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


  // BONUS: delete: default ctor, copy ctor, and copy assignment.
  Tree() = delete;
  Tree(const Tree&) = delete;
  Tree& operator=(const Tree&) = delete;

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
