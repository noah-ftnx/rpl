#ifndef RPL_SDE_19_TEST_06_H_
#define RPL_SDE_19_TEST_06_H_

#include <iostream>
#include <string>
using namespace std;

bool _wrong {};

struct Node {
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}
  ~Node() { delete left; delete right; }
};

bool same(Node* a, Node* b) {
  if (!a || !b) return a == b;
  return a->data == b->data && same(a->left, b->left) && same(a->right, b->right);
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

Node* make_mirror_perfect_7() {
  auto* root = new Node(1);
  root->left = new Node(3);
  root->right = new Node(2);
  root->left->left = new Node(7);
  root->left->right = new Node(6);
  root->right->left = new Node(5);
  root->right->right = new Node(4);
  return root;
}

Node* make_left_chain() {
  auto* root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(3);
  return root;
}

Node* make_right_chain() {
  auto* root = new Node(1);
  root->right = new Node(2);
  root->right->right = new Node(3);
  return root;
}

void mirror(Node* node);

void check(string name, Node* input, Node* correct) {
  mirror(input);
  bool wrong = !same(input, correct);
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << endl;
  delete input;
  delete correct;
}

void run_tests() {
  check("empty", nullptr, nullptr);
  check("single", new Node(1), new Node(1));
  check("perfect_7", make_perfect_7(), make_mirror_perfect_7());
  check("left_chain", make_left_chain(), make_right_chain());
  cout << endl;
}

#endif  // RPL_SDE_19_TEST_06_H_
