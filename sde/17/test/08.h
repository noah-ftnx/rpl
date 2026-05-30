#ifndef RPL_SDE_17_TEST_08_H_
#define RPL_SDE_17_TEST_08_H_

#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

struct Node {
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}
  ~Node() { delete left; delete right; }
};

bool same(const vector<int>& a, const vector<int>& b) {
  return a == b;
}

void check(string name, Node* root, vector<int> correct) {
  Solution sol;
  auto got = sol.topView(root);
  bool wrong = !same(got, correct);
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << endl;
  delete root;
}

Node* make_single() {
  return new Node(1);
}

Node* make_perfect_7() {
  auto* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  return root;
}

Node* make_mixed() {
  auto* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);
  root->left->right->right = new Node(5);
  root->right->left = new Node(6);
  return root;
}

void run_tests() {
  check("empty", nullptr, {});
  check("single", make_single(), {1});
  check("perfect_7", make_perfect_7(), {4, 2, 1, 3, 7});
  check("mixed", make_mixed(), {2, 1, 3});
  cout << endl;
}

#endif  // RPL_SDE_17_TEST_08_H_
