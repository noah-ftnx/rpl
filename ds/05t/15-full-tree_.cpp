#include "test/15-full-tree.h"

template <class T>
bool is_full(Node<T>* node) {
  if (!node) return true;
  if (!node->left && !node->right) return true;
  if (!node->left || !node->right) return false;

  return is_full(node->left) && is_full(node->right);
}

template <class T>
bool Tree<T>::is_full() {
  return ::is_full(root);
}

int main() { run_tests(); return 0; }
