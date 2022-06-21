#include <vector> // for add
#include <string> // for to_string
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int n) : data{n} {}
};

struct Tree {
  Node* root;

  Tree(int n);

  void add(const vector<int>& data, const string& path); // given
  string to_string(); // given

  Node* _delete_node(int tgt, Node* node) {
    if (node==nullptr) return nullptr;

    if (tgt < node->data) {
      node->left = _delete_node(tgt, node->left);
    } else if (tgt > node->data) {
      node->right = _delete_node(tgt, node->right);
    } else { // node found
      // we will return node.
      Node* to_del = node; // is node to delete
      // 3 cases
      if (!node->left && !node->right) { // 1. leaf
        node = nullptr;
      } else if (!node->right) { // 2.a. left node only
        node = node->left;
      } else if (!node->left) { // 2.b. right node only
        node=node->right;
      } else { // has 2 children
        // swap with successor trick
        auto succ = node->right;
        while(succ->left) succ=succ->left;

        node->data = succ->data;

        // NOTE: this else block will only enter once.
        // that is because the successor is guaranteed to have <2 children (either 0 or 1),
        // as it can never have a left child (it's the min of the right subtree)
        node->right=_delete_node(node->data, node->right);
        to_del = nullptr; // delete above.
      }

      if (to_del) {
        to_del->left = to_del->right = nullptr;
        delete to_del;
      }
    }

    return node;
  }

  void delete_node(int tgt) {
    root = _delete_node(tgt, root);
  }
};



#include "test/13.h"
int main() { run_tests(); return 0; }