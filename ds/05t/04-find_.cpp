#include "test/test-bst-tmpl.h"
#include <queue>
using namespace std;

template<class T>
bool Tree<T>::_find(Node<T>* node, T element) {
  if (!node) return false;

  if (node->data == element) return true;

  if (element>node->data) return _find(node->right, element);
  else if (element<node->data) return _find(node->left, element);

  return false;
}

template<class T>
bool Tree<T>::find(T element) {
  if (!root) return false;
  return _find(root, element);
}

template<class T>
bool Tree<T>::find_iterative(T element) {
  auto node = root;

  while (node) {
    if (element == node->data) return true;
    if (element > node->data)  node=node->right;
    else node=node->left;
  }
  return false;
}

int main () { run_find_test(); }