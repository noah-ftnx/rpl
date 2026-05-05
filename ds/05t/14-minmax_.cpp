#include "test/14-minmax.h"

int Tree::min() {
  if (!root) return INT_MAX;

  auto node = root;
  while (node->left) node = node->left;
  return node->data;
}

int Tree::max() {
  if (!root) return INT_MIN;

  auto node = root;
  while (node->right) node = node->right;
  return node->data;
}

int main() { run_tests(); return 0; }
