#ifndef RPL_DS_05T_TEST_17_PERFECT_TREE_H_
#define RPL_DS_05T_TEST_17_PERFECT_TREE_H_

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../../../.inc/check.h"

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
    if (left) { delete left; left = nullptr; }
    if (right) { delete right; right = nullptr; }
  }
};

template <class T>
class Tree {
 private:
  Node<T>* root {};

 public:
  explicit Tree() = default;
  explicit Tree(T data) : root{new Node<T>(data)} {}
  ~Tree() { delete root; }

  void add(const vector<T>& data, const string& path) {
    if (data.size() != path.size()) { cout << "ERR\n"; exit(-1); }

    Node<T>* node = root;
    auto itd = data.begin();
    auto itp = path.begin();
    for (; itd != data.end(); itd++, itp++) {
      if (*itp == 'L') {
        if (node->left == nullptr) {
          node->left = new Node<T>(*itd);
          node->left->parent = node;
        } else {
          assert(node->left->data == *itd);
        }
        node = node->left;
      } else if (*itp == 'R') {
        if (node->right == nullptr) {
          node->right = new Node<T>(*itd);
          node->right->parent = node;
        } else {
          assert(node->right->data == *itd);
        }
        node = node->right;
      }
    }
  }

  void init_perfect_3() {
    root = new Node<T>(1);
    add({2}, "L");
    add({3}, "R");
  }

  void init_perfect_7() {
    root = new Node<T>(1);
    add({2, 4}, "LL");
    add({2, 5}, "LR");
    add({3, 6}, "RL");
    add({3, 7}, "RR");
  }

  void init_only_left() {
    root = new Node<T>(1);
    add({2}, "L");
  }

  void init_full_but_not_perfect() {
    root = new Node<T>(1);
    add({2, 4}, "LL");
    add({2, 5}, "LR");
    add({3}, "R");
  }

  void init_missing_deep_child() {
    root = new Node<T>(1);
    add({2, 4}, "LL");
    add({2}, "L");
    add({3, 6}, "RL");
    add({3, 7}, "RR");
  }

  bool is_perfect();
};

void run_tests() {
  auto tree1 = Tree<int>();
  check_bool("perfect:1 empty", tree1.is_perfect(), true);

  auto tree2 = Tree<int>(1);
  check_bool("perfect:2 single node", tree2.is_perfect(), true);

  auto tree3 = Tree<int>();
  tree3.init_perfect_3();
  check_bool("perfect:3 root has both", tree3.is_perfect(), true);

  auto tree4 = Tree<int>();
  tree4.init_perfect_7();
  check_bool("perfect:4 deeper perfect", tree4.is_perfect(), true);

  auto tree5 = Tree<int>();
  tree5.init_only_left();
  check_bool("perfect:5 only left", tree5.is_perfect(), false);

  auto tree6 = Tree<int>();
  tree6.init_full_but_not_perfect();
  check_bool("perfect:6 full but leaves differ", tree6.is_perfect(), false);

  auto tree7 = Tree<int>();
  tree7.init_missing_deep_child();
  check_bool("perfect:7 deeper missing child", tree7.is_perfect(), false);

  cout << endl;
}

#endif  // RPL_DS_05T_TEST_17_PERFECT_TREE_H_
