#ifndef RPL_DS_05T_TEST_TEST_BST_H_
#define RPL_DS_05T_TEST_TEST_BST_H_

#include <optional>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "../../../.inc/check.h"
#include "../../../.inc/check-opt.h"

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
  Node<T>* root{};

 public:
  explicit Tree() = default;
  ~Tree() {
    delete root;
  }

  void init_input1() {
    insert({70, 50, 35, 45, 20, 73, 15, 60});
  }

  void insert(vector<T> vec) {
    for (auto v : vec) insert(v);
  }

  void _insert(T data, Node<T>* node) {
    if (data > node->data) {  // insert: Right
      if (!node->right) {
        node->right = new Node(data);
        node->right->parent = node;
      } else
        _insert(data, node->right);
    } else {  // insert: Left
      if (!node->left) {
        node->left = new Node(data);
        node->left->parent = node;
      } else
        _insert(data, node->left);
    }
  }

  void insert(T data) {
    if (root == nullptr) {
      root = new Node(data);
    } else {
      _insert(data, root);
    }
  };

  Node<T>* _successor_recv(Node<T>* node, T data);
  Node<T>* successor_recv(T element);
};

void run_tests() {
  auto tree = Tree<int>();
  tree.init_input1();

  check_result("recv successor of 45", tree.successor_recv(45)->data, 50);
  check_result("recv successor of 70", tree.successor_recv(70)->data, 73);
  check_result("recv successor of 73", (void*)tree.successor_recv(73), (void*)nullptr);
  cout << endl;
}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_