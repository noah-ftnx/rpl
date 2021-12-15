#ifndef RPL_DS_05T_TEST_TEST_BST_H_
#define RPL_DS_05T_TEST_TEST_BST_H_

#include <iostream>
using namespace std;

class Node {
 public:
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}

  ~Node() { clear(); }

  void clear() {
    if(left) { delete left; left=nullptr; }
    if (right) { delete right; right=nullptr; }
  }
};

class Tree {
 private:
  Node* root {};
 public:

  explicit Tree() = default;
  explicit Tree(Node* root) : root{root} {}
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
};

void run_tests() {
  auto t = Tree();
  t.init_input1();

  cout << "VERIFY MANUALLY:\n";
  t.print_bst_level();

  cout << "\nCorrect output:\n";
  cout<< "10\n";
  cout<< "5 25\n";
  cout<< "3 7 20 30\n";
}

#endif  // RPL_DS_05T_TEST_TEST_BST_H_