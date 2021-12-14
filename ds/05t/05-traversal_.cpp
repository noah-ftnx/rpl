#include "test/test-bst-tmpl-traversal.h"

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


int main() { run_tests(); return 0; }