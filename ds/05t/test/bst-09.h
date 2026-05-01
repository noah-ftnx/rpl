#ifndef RPL_DS_05T_TEST_TEST_BST_H_
#define RPL_DS_05T_TEST_TEST_BST_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <assert.h>
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

  void add(const vector<T>& data, const string& path) {
    if(data.size() != (path.size())) { cout << "ERR\n"; exit(-1); }

    Node<T>* node = root;
    auto itd=data.begin();
    auto itp=path.begin();
    for(; itd!=data.end(); itd++, itp++) {
      if(*itp=='L') { // LEFT NODE
        if (node->left == nullptr) {
          node->left = new Node<T>(*itd);
          node->left->parent = node;
        } else {
          assert(node->left->data == *itd);
        }
        node = node->left;
      } else if(*itp=='R') { // RIGHT NODE
        if(node->right == nullptr) {
          node->right = new Node<T>(*itd);
          node->right->parent=node;
        } else {
          assert(node->right->data == *itd);
        }
        node=node->right;
      }
    }
  }

  void init_input1() {
    insert({70, 50, 35, 45, 20, 73, 15, 60});
  }

  void init_input2() {
    root = new Node(1);
    add( { 2, 4, 8 }, { 'L', 'L', 'L' });
    add( { 2, 4, 9 }, { 'L', 'L', 'R' });
    add( { 2, 5, 10 }, { 'L', 'R', 'L' });
    add( { 2, 5, 11 }, { 'L', 'R', 'R' });
  }

  void init_input3() {
    root = new Node(10);
    add( { 5 }, { 'L' });
    add( { 15, 6 }, { 'R', 'L' });
  }

  void init_input4() {
    root = new Node(10);
    add( { 10 }, { 'L' });
  }

  void init_input5() {
    root = new Node(10);
    add( { 10 }, { 'R' });
  }

  void init_input6() {
    root = new Node(20);
    add( { 10, 5 }, { 'L', 'L' });
    add( { 10, 15 }, { 'L', 'R' });
    add( { 30, 25 }, { 'R', 'L' });
    add( { 30, 35 }, { 'R', 'R' });
  }

  void init_input7() {
    root = new Node(20);
    add( { 10, 5 }, { 'L', 'L' });
    add( { 10, 25 }, { 'L', 'R' });
  }

  void init_input8() {
    root = new Node(INT_MIN);
    add( { INT_MIN + 1 }, { 'R' });
  }

  void init_input9() {
    root = new Node(INT_MAX);
    add( { INT_MAX - 1 }, { 'L' });
  }

  bool _is_bst(Node<T>* node);
  bool is_bst();
};

void check_bst(string msg, bool result, bool correct) {
  cout << (result == correct ? "[PASS] " : "[FAIL] ") << left  << setw(28) << (msg + ":")
       << setw(7) << (result ? "true" : "false")
        << endl;
}

void run_tests() {
  auto tree1 = Tree<int>();
  tree1.init_input1();
  check_bst("bst:1 valid insert", tree1.is_bst(), true);

  auto tree2 = Tree<int>();
  tree2.init_input2();
  check_bst("bst:2 invalid left/right", tree2.is_bst(), false);

  auto tree3 = Tree<int>();
  tree3.init_input3();
  check_bst("bst:3 ancestor bound", tree3.is_bst(), false);

  auto tree4 = Tree<int>();
  tree4.init_input4();
  check_bst("bst:4 duplicate left", tree4.is_bst(), false);

  auto tree5 = Tree<int>();
  tree5.init_input5();
  check_bst("bst:5 duplicate right", tree5.is_bst(), false);

  auto tree6 = Tree<int>();
  tree6.init_input6();
  check_bst("bst:6 deeper valid", tree6.is_bst(), true);

  auto tree7 = Tree<int>();
  tree7.init_input7();
  check_bst("bst:7 deeper invalid", tree7.is_bst(), false);

  auto tree8 = Tree<int>();
  tree8.init_input8();
  check_bst("bst:8 INT_MIN", tree8.is_bst(), true);

  auto tree9 = Tree<int>();
  tree9.init_input9();
  check_bst("bst:9 INT_MAX", tree9.is_bst(), true);

  cout << endl;
}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_
