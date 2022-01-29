#include <climits>
using namespace std;

struct Node {
  Node* left {};
  Node* right {};
  int data;
  Node(int data) : data{data} {}
};

int predecessor(Node* root) {
  if (root == nullptr) return INT_MIN;
  else if (root->left == root->right && root->left == nullptr) return INT_MIN; // 1 node

  Node *parent=nullptr, *node=root;
  while (node->right) {
    parent=node;
    node=node->right;
  }


  // no way to have another right node
  // we moved at the right-most node
  if (!node->left) { // it's a leaf node
    return parent->data;
  } else { // there is just a left node
            // return the highest on left sub-tree
    node=node->left;
    while(node->right) node=node->right;
    return node->data;
  }
}



#include "test/036.h"
int main() { run_tests(); return 0; }