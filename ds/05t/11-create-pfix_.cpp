#include <string> // for Tree.print()
#include <stack>
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
  const Tree& operator=(const Tree&) = delete;
  Tree(const Tree&) = delete;
  Tree() = delete;

  Tree(const string& postfix) {
    stack<Node*> st;
    for (auto c: postfix) {
      Node* node = new Node(c);
      if (!isdigit(c)) { // symbol
        auto rhs = st.top(); st.pop();
        auto lhs = st.top(); st.pop();
        node->left=lhs;
        node->right=rhs;
        // up navigation
        node->left->parent=node;
        node->right->parent=node;
      }
      st.push(node);
    }
    root = move(st.top());
  }

  string to_string();
};



#include "test/11-cpfix.h"
int main() { run_tests(); return 0; }