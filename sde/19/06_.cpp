#include <utility>

struct Node;

#include "test/06.h"

// GFG: Function to convert a binary tree into its mirror tree.
void mirror(Node* node) {
  if (node==nullptr) return;
  mirror(node->left);
  mirror(node->right);
  swap(node->left, node->right);
}

int main() { run_tests(); return 0; }
