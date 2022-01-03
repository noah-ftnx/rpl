#include <utility>
using namespace std;

struct Node {
  Node* left {};
  Node* right {};
  int data {};

  Node(int data) : data{data} {}

  bool leaf() { return left == nullptr && right == nullptr; }
};

struct Tree {
  Node* root {};

  pair<Node*, int> _deepest_node_using_height(Node* node, int height) { // extra implementation
    if (node->leaf()) return make_pair(node, height);

    pair<Node*, int> dleft, dright;
    if (node->left) {
      dleft = _deepest_node_using_height(node->left, height+1);
    }
    if (node->right) {
      dright = _deepest_node_using_height(node->right, height+1);
    }

    return (dleft.second > dright.second? dleft:dright);
  }

  // extra implementation
  Node* deepest_node_using_height() { return root?_deepest_node_using_height(root, 0).first: nullptr; }


  pair<Node*, int> _deepest_node_using_depth(Node* node) {
    if (node->leaf()) return make_pair(node, 1);

    pair<Node*, int> dleft, dright;
    if(node->left) {
      dleft = _deepest_node_using_depth(node->left);
      dleft.second++;
    }
    if (node->right) {
      dright = _deepest_node_using_depth(node->right);
      dright.second++;
    }

    if (node->right == nullptr) return dleft;
    else if (node->left == nullptr) return dright;
    else {
      return dleft.second > dright.second? dleft:dright;
    }
  }

  Node* deepest_node() { return root?_deepest_node_using_depth(root).first: nullptr; }
};



#include "test/11b.h"
int main() { run_tests(); return 0; }