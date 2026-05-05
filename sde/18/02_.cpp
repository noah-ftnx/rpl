#include <algorithm>
#include "test/02.h"

template <class T>
int max_depth(Node<T>* node) {
  if (!node) return 0; // base case: empty subtree

  // depth counts nodes:
  // - single node => 1
  // - empty tree  => 0
  int L = max_depth(node->left);
  int R = max_depth(node->right);
  return 1 + max(L, R);
}

template <class T>
int Tree<T>::max_depth() {
  return ::max_depth(root);
}

int main() { run_tests(); return 0; }
