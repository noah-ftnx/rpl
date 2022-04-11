#include <utility>
using namespace std;

struct Node {
  Node* left {};
  Node* right {};
  int data {};

  Node(int data) : data{data} {}

  bool is_leaf() { return left == nullptr && right == nullptr; }
};

struct Tree {
  Node* root {};

  pair<int, Node*> _recv(Node* node, int depth) {
    if (node == nullptr) return {-1, nullptr};

    if (node->is_leaf()) return { depth, node };
    else {
      auto leftST = _recv(node->left, depth+1) ;
      auto rightST = _recv(node->right, depth+1);

      if (leftST.first > rightST.first) {
        return leftST;
      } else {
        return rightST;
      }
    }
  }

  Node* deepest_node() {
    auto res = _recv(root, 0);
    return res.second;
  }

};



#include "test/11b.h"
int main() { run_tests(); return 0; }