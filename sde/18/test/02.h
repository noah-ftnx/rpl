#ifndef RPL_SDE_18_TEST_02_H_
#define RPL_SDE_18_TEST_02_H_

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
  Tree() = default;
  explicit Tree(T data) : root{new Node<T>(data)} {}
  ~Tree() { delete root; }

  void add(const vector<T>& data, const string& path) {
    if (data.size() != path.size()) { cout << "ERR\n"; exit(-1); }

    Node<T>* node = root;
    auto itd = data.begin();
    auto itp = path.begin();
    for (; itd != data.end(); itd++, itp++) {
      if (*itp == 'L') {
        if (node->left == nullptr)
          node->left = new Node<T>(*itd);
        else
          assert(node->left->data == *itd);
        node = node->left;
      } else if (*itp == 'R') {
        if (node->right == nullptr)
          node->right = new Node<T>(*itd);
        else
          assert(node->right->data == *itd);
        node = node->right;
      }
    }
  }

  void init_root_children() {
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

  void init_left_chain() {
    root = new Node<T>(1);
    add({2, 3, 4}, "LLL");
  }

  void init_right_chain() {
    root = new Node<T>(1);
    add({2, 3, 4}, "RRR");
  }

  void init_mixed_left_deeper() {
    root = new Node<T>(1);
    add({2, 4, 8}, "LLL");
    add({2, 5}, "LR");
    add({3}, "R");
  }

  void init_mixed_right_deeper() {
    root = new Node<T>(1);
    add({2}, "L");
    add({3, 6, 9, 10}, "RRRR");
  }

  void init_zigzag() {
    root = new Node<T>(1);
    add({2, 3, 4, 5}, "LRLR");
  }

  int max_depth();
};

void run_tests() {
  auto t1 = Tree<int>();
  check_result("depth:1 empty", t1.max_depth(), 0);

  auto t2 = Tree<int>(1);
  check_result("depth:2 single node", t2.max_depth(), 1);

  auto t3 = Tree<int>();
  t3.init_root_children();
  check_result("depth:3 root children", t3.max_depth(), 2);

  auto t4 = Tree<int>();
  t4.init_perfect_7();
  check_result("depth:4 perfect 7", t4.max_depth(), 3);

  auto t5 = Tree<int>();
  t5.init_left_chain();
  check_result("depth:5 left chain", t5.max_depth(), 4);

  auto t6 = Tree<int>();
  t6.init_right_chain();
  check_result("depth:6 right chain", t6.max_depth(), 4);

  auto t7 = Tree<int>();
  t7.init_mixed_left_deeper();
  check_result("depth:7 left deeper", t7.max_depth(), 4);

  auto t8 = Tree<int>();
  t8.init_mixed_right_deeper();
  check_result("depth:8 right deeper", t8.max_depth(), 5);

  auto t9 = Tree<int>();
  t9.init_zigzag();
  check_result("depth:9 zigzag", t9.max_depth(), 5);

  cout << endl;
}

#endif  // RPL_SDE_18_TEST_02_H_
