#ifndef RPL_DS_05T_TEST_14_MINMAX_H_
#define RPL_DS_05T_TEST_14_MINMAX_H_

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#include "../../../.inc/check.h"

class Node {
 public:
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}

  ~Node() { clear(); }

  void clear() {
    if (left) { delete left; left = nullptr; }
    if (right) { delete right; right = nullptr; }
  }
};

class Tree {
 private:
  Node* root {};

 public:
  Tree() = default;
  explicit Tree(int data) : root{new Node(data)} {}
  ~Tree() { delete root; }

  void insert(int data) {
    if (!root) {
      root = new Node(data);
      return;
    }

    auto node = root;
    while (true) {
      if (data < node->data) {
        if (!node->left) {
          node->left = new Node(data);
          return;
        }
        node = node->left;
      } else {
        if (!node->right) {
          node->right = new Node(data);
          return;
        }
        node = node->right;
      }
    }
  }

  void insert(const vector<int>& data) {
    for (auto v: data) insert(v);
  }

  void init_input1() {
    insert({10, 5, 25, 20, 30, 7, 3});
  }

  void init_left_chain() {
    insert({4, 3, 2, 1});
  }

  void init_right_chain() {
    insert({1, 2, 3, 4});
  }

  void init_negatives() {
    insert({0, -10, 10, -20, -5, 5, 20});
  }

  int min();
  int max();
};

void check_minmax(string msg, Tree& tree, int min, int max) {
  check_result(msg + " min", tree.min(), min);
  check_result(msg + " max", tree.max(), max);
}

void run_tests() {
  auto t1 = Tree();
  check_minmax("minmax:1 empty", t1, INT_MAX, INT_MIN);

  auto t2 = Tree(7);
  check_minmax("minmax:2 single node", t2, 7, 7);

  auto t3 = Tree();
  t3.init_input1();
  check_minmax("minmax:3 normal bst", t3, 3, 30);

  auto t4 = Tree();
  t4.init_left_chain();
  check_minmax("minmax:4 left chain", t4, 1, 4);

  auto t5 = Tree();
  t5.init_right_chain();
  check_minmax("minmax:5 right chain", t5, 1, 4);

  auto t6 = Tree();
  t6.init_negatives();
  check_minmax("minmax:6 negatives", t6, -20, 20);

  cout << endl;
}

#endif  // RPL_DS_05T_TEST_14_MINMAX_H_
