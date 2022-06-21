#include <string> // for Tree.print() // TODO INCLUDES.. hide..
#include <stack>
using namespace std;

struct Node {
  Node *left{};
  Node *right{};
  Node *parent{};
  char data;
  Node(char val) : data{} {}
};

class Tree {
  Node* root;

 public:
  Tree(const string& postfix) {
    stack<Node*> st;
    for (char c: postfix) {
      switch (c) {
        // operator
        case '+':
        case '-':
        case '*':
        case '\\':
        case '^':
        {
          // create 2 nodes:
          auto right = st.top(); st.pop();
          auto left = st.top(); st.pop();
          auto par = new Node(c);

          // linkage
          par->left=left;
          par->right=right;
          right->parent=left->parent=par;

          // push back
          st.push(par);
        }
        break;

        default: // number
          st.push(new Node(c));
      }
    }
    root = st.top(); st.pop();
  }
  // implemented (for verification)
  string to_string();
};



#include "test/11-cpfix.h"
int main() { run_tests(); return 0; }