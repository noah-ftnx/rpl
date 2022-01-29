#ifndef RPL_DCP_TEST_036_H_
#define RPL_DCP_TEST_036_H_

#include <iostream>
#include <iomanip>

Node* input1() {
  Node* root = new Node(15);
  root->left=new Node(5);
  root->left->left=new Node(1);
  root->left->right=new Node(10);
  root->right=new Node(20);
  root->right->left=new Node(17);
  root->right->right=new Node(40);
  // 2nd: 20

  return root;
}

Node* input2() {
  Node* root = new Node(15);
  root->left=new Node(5);
  root->left->left=new Node(1);
  root->left->right=new Node(10);
  root->right=new Node(20);
  root->right->left=new Node(17);
  // 2nd: 17

  return root;
}

Node* input3() {
  Node* root = new Node(15);
  root->left=new Node(5);
  root->left->left=new Node(1);
  root->left->right=new Node(10);
  root->left->right->right=new Node(11);
  // 2nd: 11

  return root;
}

Node* input4() { return nullptr; }
Node* input5() { return new Node(10); }

void test(Node* root, int correct) {
  int result = predecessor(root);

  cout << "second smallest: " << setw(2) << (result==INT_MIN? "NAN":to_string(result))
       << (correct!=result? " (WRONG)":"") << endl;
}

void run_tests() {
  test(input1(), 20);
  test(input2(), 17);
  test(input3(), 11);
  test(input4(), INT_MIN);
  test(input5(), INT_MIN);
}

#endif  // RPL_DCP_TEST_036_H_
