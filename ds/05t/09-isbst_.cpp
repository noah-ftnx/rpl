#include "test/bst-09.h"

template <class T>
bool Tree<T>::_is_bst(Node<T>* node) {
  bool res = !node->left || (node->data > node->left->data && _is_bst(node->left));
  if(!res) return false;
  res = !node->right || (node->data < node->right->data && _is_bst(node->right));
  return res;
}

template <class T>
bool Tree<T>::is_bst() { return _is_bst(root); }

int main() { run_tests(); return 0; }