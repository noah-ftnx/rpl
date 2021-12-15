#include <optional>
#include <stack>
#include "test/bst-tmpl-succpred.h"


template <class T>
optional<T> Tree<T>::successor(T element) {
 // find the element
 if (!root) return {};
 bool found = false;
 auto node = root;
 stack<Node<T>*> st;
 while (!found && node) { // TRICKY
   if (element == node->data) { found=true; }
   else {
     st.push(node);
     if (element > node->data) node=node->right;
     else node = node->left;
   }
 }
 if (!found) return {};

 if (node->right) { // min of right subtree
   node = node->right;
   while(node->left) node=node->left;
   return node->data;
 } else { // first parent > than element
   while(!st.empty()) {
     auto p = st.top(); st.pop();
     if (p->data > element) return p->data;
   }
   return {};
 }
}

template <class T>
optional<T> Tree<T>::predecessor(T element) {
  // find the element & populate stack of parents
  if (!root) return {};
  bool found=false;
  auto node = root;
  stack<Node<T>*> st;
  while(!found && node) {
    if (node->data == element) { found = true; }
    else {
      st.push(node);
      if (element > node->data) node = node->right;
      else node = node->left;
    }
  }
  if (!found) return {};
  if (node->left) { // has left subtree: return it's max
    node=node->left;
    while (node->right) node=node->right;
    return node->data;
  } else { // first parent < element
    while (!st.empty()) {
      auto p = st.top(); st.pop();
      if (p->data < element) return p->data;
    }
    return {};
  }
}

template <class T>
Node<T>* Tree<T>::successor_with_parent(Node<T>* node) {
  if (node==nullptr) return nullptr;

  if (node->right) { // min of right subtree
    node=node->right;
    while(node->left) node=node->left;
    return node;
  } else { // first parent > than node
    auto par = node->parent;
    while (par) {
     if(par->data > node->data) return par;
     par=par->parent;
    }
    return nullptr;
  }
}


int main() { run_tests(); return 0; }