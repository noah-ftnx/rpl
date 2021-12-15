#ifndef RPL_DS_05T_TEST_TEST_BST_H_
#define RPL_DS_05T_TEST_TEST_BST_H_

#include <iostream>
#include <vector>
#include <string>
#include "../../../.check/check.h"
using namespace std;

template <class T>
class Node {
 public:
  T data {};
  Node* left {};
  Node* right {};
  Node* parent {};

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

  explicit Tree(T data) {
    root = new Node(data);
  }
  explicit Tree(Node<T>* root) : root{root} {}
  ~Tree() { delete root; }
  void print_bst_level();


  void insert(vector<T> vec) { for (auto v: vec) insert(v); }

  void _insert(T data, Node<T>* node) {
    if (data > node->data)  { // insert: Right
      if (!node->right) {
        node->right = new Node(data);
        node->right->parent=node;
      }
      else _insert(data, node->right);
    } else { // insert: Left
      if (!node->left) {
        node->left = new Node(data);
        node->left->parent=node;
      }
      else _insert(data, node->left);
    }
  }

  void insert(T data) {
    if (root == nullptr) { root = new Node(data); }
    else {
      _insert(data, root);
    }
  }

  void init_input1() {
    insert({10, 5, 25, 20, 30, 7, 3});
  }

  // FIND
  bool _find(Node<T>* node, T element);
  bool find(T element);
  bool find_iterative(T element);

  T min();
  T max();
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

 check_result("min: ", tree->min(), 3);
 check_result("max: ", tree->max(), 30);
}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_