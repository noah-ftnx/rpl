#ifndef RPL_SDE_17_TEST_09_H_
#define RPL_SDE_17_TEST_09_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

template <class T>
class BinaryTreeNode {
 public:
  T data {};
  BinaryTreeNode* left {};
  BinaryTreeNode* right {};

  explicit BinaryTreeNode(T data) : data{data} {}
  ~BinaryTreeNode() { delete left; delete right; }
};

template <class T>
bool same(const vector<T>& a, const vector<T>& b) {
  return a == b;
}

template <class T>
void check(string name, BinaryTreeNode<T>* root, vector<vector<int>> correct) {
  auto r1 = getTreeTraversalRECV(root);
  auto r2 = getTreeTraversal(root);
  bool wrong = !same(r1, correct) || !same(r2, correct);
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << endl;
  delete root;
}

BinaryTreeNode<int>* make_empty() {
  return nullptr;
}

BinaryTreeNode<int>* make_single() {
  return new BinaryTreeNode<int>(1);
}

BinaryTreeNode<int>* make_three() {
  auto* root = new BinaryTreeNode<int>(1);
  root->left = new BinaryTreeNode<int>(2);
  root->right = new BinaryTreeNode<int>(3);
  return root;
}

BinaryTreeNode<int>* make_mixed() {
  auto* root = new BinaryTreeNode<int>(1);
  root->left = new BinaryTreeNode<int>(2);
  root->left->right = new BinaryTreeNode<int>(4);
  root->right = new BinaryTreeNode<int>(3);
  root->right->left = new BinaryTreeNode<int>(5);
  return root;
}

void run_tests() {
  check("empty", make_empty(), {{}, {}, {}});
  check("single", make_single(), {{1}, {1}, {1}});
  check("three", make_three(), {{2, 1, 3}, {1, 2, 3}, {2, 3, 1}});
  check("mixed", make_mixed(), {{2, 4, 1, 5, 3}, {1, 2, 4, 3, 5}, {4, 2, 5, 3, 1}});
  cout << endl;
}

#endif  // RPL_SDE_17_TEST_09_H_
