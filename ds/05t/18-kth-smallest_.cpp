#include "test/18-kth-smallest.h"

template <class T>
optional<T> kth_smallest(Node<T>* node, int &k) {
  if (!node || k <= 0) return {};

  // inorder on BST visits values sorted:
  // left -> node -> right
  if (auto L = kth_smallest(node->left, k)) return L;

  // VISIT
  if (--k == 0) return node->data;

  return kth_smallest(node->right, k);
}

template <class T>
optional<T> Tree<T>::kth_smallest(int k) {
  return ::kth_smallest(root, k);
}

int main() { run_tests(); return 0; }
