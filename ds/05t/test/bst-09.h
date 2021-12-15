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

  bool _is_bst(Node<T>* node);
  bool is_bst();
};

void run_tests() {
  auto tree1 = Tree<int>();
  tree1.init_input1();
  check_bool("bst:1", tree1.is_bst(), true);

  auto tree2 = Tree<int>();
  tree2.init_input2();
  check_bool("bst:2", tree2.is_bst(), false);

  cout << endl;
}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_