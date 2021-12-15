#ifndef RPL_DS_05T_TEST_TEST_BST_H_
#define RPL_DS_05T_TEST_TEST_BST_H_

#include <iostream>
#include <vector>
#include <string>
#include "../../../.check/check.h"
#include "../../../.check/check-opt.h"
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

  Node<T>* get_element(T element) {
    auto node = root;
    while (node) {
      if (element == node->data) return node;
      if (element > node->data)  node=node->right;
      else node=node->left;
    }
    return nullptr;
  }

  optional<T> successor(T element);
  optional<T> predecessor(T element);
  Node<T>* successor_with_parent(Node<T>* node);
};

void run_tests() {
  auto tree = Tree<int>();
  tree.init_input1();

  check_optional("successor of 45", tree.successor(45), make_optional(50));
  check_optional("successor of 70", tree.successor(70), make_optional(73));
  check_optional("successor of 73", tree.successor(73), {});
  cout << endl;

  check_optional("predecessor of 45", tree.predecessor(45), make_optional(35));
  check_optional("predecessor of 70", tree.predecessor(70), make_optional(60));
  check_optional("predecessor of 15", tree.predecessor(15), {});
  cout << endl;

  auto node = tree.get_element(45);
  check_result("successor_with_parent of 45", tree.successor_with_parent(node)->data, 50);
  node = tree.get_element(73);
  check_result("successor_with_parent of 73", (void *)tree.successor_with_parent(node), (void*) nullptr);

  // TODO recv?!
}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_