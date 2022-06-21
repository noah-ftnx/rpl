#include "test/bst-tmpl-succpred-recv.h"

template <class T>
Node<T>* Tree<T>::_successor_recv(Node<T>* node, T data) {  // inorder traversal
  static vector<Node<T>*> traversal;

  if (node->left) {
    auto found = _successor_recv(node->left, data);
    if(found) return found;
  }

  // visit
  if(!traversal.empty() && traversal.back()->data == data) { // TRICKY
    // prev item is what we are looking for
    // means current item is the solution
    return node;
  }
  traversal.push_back(node);

  if (node->right) {
    auto found= _successor_recv(node->right, data);
    if (found) return found;
  }
  return nullptr;
}

template <class T>
Node<T>* Tree<T>::successor_recv(T data) {
  return _successor_recv(root, data);
}

int main() { run_tests(); return 0; }