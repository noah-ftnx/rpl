#include "test/bst-tmpl-minmax.h"
template <class T>
T Tree<T>::min() {
  auto _min = [] (Node<T>* node) -> T {
    while (node->left) node=node->left;
    return node->data;
  };
  if (!root) return INT_MAX;
  return _min(root);
}

template <class T>
T Tree<T>::max() {
  auto _max = [] (Node<T>* node) -> T {
    while (node->right) node=node->right;
    return node->data;
  };

  if (!root) return INT_MIN;
  return _max(root);
}


int main() { run_tests(); return 0; }
