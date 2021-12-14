#ifndef RPL_DS_05T_TEST_TEST_BST_H_
#define RPL_DS_05T_TEST_TEST_BST_H_

#include <iostream>
#include "../../../.check/check.h"
using namespace std;

template <class T>
class Node {
 public:
  T data {};
  Node* left {};
  Node* right {};

  explicit Node(T data) : data{data} {}

  ~Node() { clear(); }

  void clear() {
    if(left) { delete left; left=nullptr; }
    if (right) { delete right; right=nullptr; }
  }
};

template <class T>
class Tree {
 private:
  Node<T>* root {};
 public:

  explicit Tree() = default;
  explicit Tree(Node<T>* root) : root{root} {}
  ~Tree() { delete root; }
  void print_bst_level();

  void init_input1() {
    root = new Node(10);
    root->left=new Node(5);
    root->right=new Node(25);
    root->right->left=new Node(20);
    root->right->right=new Node(30);
    root->left->right=new Node(7);
    root->left->left=new Node(3);
  }

  bool _find(Node<T>* node, T element);
  bool find(T element);
  bool find_iterative(T element);
};

void run_find_test() {
  auto tree = new Tree<int>();
  tree->init_input1();

  int query=20;
  check_bool("find:recv: " + std::to_string(query), tree->find(query), true);
  check_bool("find:iter: " + std::to_string(query), tree->find_iterative(query), true);

  query=21;
  check_bool("find:recv: " + std::to_string(query), tree->find(query), false);
  check_bool("find:iter: " + std::to_string(query), tree->find_iterative(query), false);
}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_