#include "test/bst-tmpl-traversal.h"

template <class T>
void Tree<T>::_print_inorder(Node<T>* node) {
  if (node == nullptr) return;
  _print_inorder(node->left);
  cout << node->data << " ";
  _print_inorder(node->right);
}

template <class T>
void Tree<T>::print_inorder() {
  _print_inorder(root);
  cout << endl;
}

template <class T>
void Tree<T>::_print_preorder(Node<T>* node) {
  if (node == nullptr) return;
  cout << node->data << " ";
  _print_preorder(node->left);
  _print_preorder(node->right);
}

template <class T>
void Tree<T>::print_preorder() {
  _print_preorder(root);
  cout << endl;
}

template <class T>
void Tree<T>::_print_postorder(Node<T>* node) {
  if (node == nullptr) return;
  _print_postorder(node->left);
  _print_postorder((node->right));
  cout << node->data << " ";
}

template <class T>
void Tree<T>::print_postorder() {
  _print_postorder(root);
  cout << endl;
}

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