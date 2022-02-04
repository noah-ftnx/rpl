#ifndef RPL_DCP_000_TEST_050_H_
#define RPL_DCP_000_TEST_050_H_

#include <iostream>
#include <iomanip>
using namespace std;

bool _wrong {};

void test(Node* root, double correct) {
  double result = evaluate_tree(root);

  cout << "Result: " << setw(12) << result << ": \t\t"
       << (result!=correct? "WRONG.": "Correct.") << endl;
}

//      *
//     / \
//    +    +
//   / \  / \
//  3  2  4  5
Node* input1() {
  Node* root = new Node('*');
  root->left=new Node('+');
  root->right=new Node('+');
  root->left->left=new Node('3');
  root->left->right=new Node('2');

  root->right->left=new Node('4');
  root->right->right=new Node('5');

  return root;
}

//  3  2  4  5
Node* input1_invalid() {
  Node* root = new Node('*');
  root->left=new Node('+');
  root->right=new Node('+');
  return root;
}

Node* input3() {
  Node* root = new Node('*');
  root->left = new Node('5');
  root->right = new Node('2');
  return root;
}

Node* input4() {
  Node* root = new Node('/');
  root->left = new Node('5');
  root->right = new Node('2');
  return root;
}

Node* input5() {
  Node* root = new Node('/');
  root->left = new Node('5');
  root->right = new Node('0');
  return root;
}

void run_tests() {
  test(input1(), 45);
  test(input1_invalid(), INT_MIN);
  test(nullptr, INT_MIN);
  test(input3(), 10);
  test(input4(), 2.5);
  test(input5(), INT_MIN);
}

#endif  // RPL_DCP_000_TEST_050_H_
