#include "test/17-perfect-tree.h"

template <class T>
int left_depth(Node<T>* node) {
  int depth = 0;
  while (node) {
    depth++;
    node = node->left;
  }
  return depth;
}

template <class T>
bool is_perfect(Node<T>* node, int level, int depth) {
  if (!node) return true;
  if (!node->left && !node->right) return level == depth;
  if (!node->left || !node->right) return false;

  return is_perfect(node->left, level + 1, depth) &&
         is_perfect(node->right, level + 1, depth);
}

template <class T>
bool Tree<T>::is_perfect() {
  return ::is_perfect(root, 1, left_depth(root));
}

int main() { run_tests(); return 0; }
