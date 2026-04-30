#include "test/bst-09.h"

template <class T>
bool _bst(Node<T>* node, long low, long high) {
  if (!node) return true;
  if (node->data >= high || node->data <= low) return false;
  bool L = _bst(node->left, low, node->data);
  bool R = _bst(node->right, node->data, high);
  return L && R;
}

template <class T>
bool Tree<T>::is_bst() {
  return _bst(root, LLONG_MIN, LLONG_MAX);
}

int main() { run_tests(); return 0; }
