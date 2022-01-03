#ifndef RPL_DS_08_TEST_11B_H_
#define RPL_DS_08_TEST_11B_H_

#include <string>
#include <iostream>

Tree* input1() {
  Tree* t = new Tree();
  t->root = new Node(0);
  t->root->left = new Node(4);
  t->root->right = new Node(10);
  t->root->left->left = new Node(55);

  return t;
}

Tree* input2() {
  Tree* t = new Tree();
  t->root = new Node(0);
  t->root->left = new Node(4);
  t->root->right = new Node(10);
  t->root->right->left = new Node(44);
  t->root->right->right= new Node(55);
  t->root->right->left->left = new Node(555);
  t->root->left->left = new Node(5);

  return t;
}

void test(Tree* tree, int correct) {
  Node* node = tree->deepest_node();
  int res = node!=nullptr? node->data:-9999;
  cout << "deepest node: " << to_string(res) << (res!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test(input1(), 55);
  test(input2(), 555);
  test(new Tree(), -9999);
}


#endif  // RPL_DS_08_TEST_11B_H_
