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

  void init_input1() {
    root = new Node(10);
    root->left=new Node(5);
    root->right=new Node(25);
    root->right->left=new Node(20);
    root->right->right=new Node(30);
    root->left->right=new Node(7);
    root->left->left=new Node(3);
  }

  void add_nonbst(const vector<T>& data, const string& path) {
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


  void _print_preorder(Node<T>* node);
  void print_preorder();
  void _print_inorder(Node<T>* node);
  void print_inorder();
  void _print_postorder(Node<T>* node);
  void print_postorder();

  T min();
  T max();
};

void run_tests() {
  auto tree = Tree<int>(1); // not a BST
  tree.add( { 2, 4}, { 'L', 'L' });
  tree.add( { 2, 5}, { 'L', 'R' });
  tree.add( { 3}, { 'R' });

  cout << "   INORDER: ";
  tree.print_inorder();
  cout << "   CORRECT: 4 2 5 1 3\n\n";

  cout << " PRE ORDER: ";
  tree.print_preorder();
  cout << "   CORRECT: 1 2 4 5 3\n\n";

  cout << "POST ORDER: ";
  tree.print_postorder();
  cout << "   CORRECT: 4 5 2 3 1\n\n";


  cout << "min: " << tree.min() << endl;
  cout << "max: " << tree.max() << endl;

}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_