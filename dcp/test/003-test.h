#ifndef RPL_DCP_TEST_003_TEST_H_
#define RPL_DCP_TEST_003_TEST_H_

#include <iostream>
#include <cassert>
#include <queue>

void Tree::input_perfect() {
  root=new Node("root");
  root->left=new Node("left");
  root->right=new Node("right");
  root->left->left=new Node("left-left");
  root->left->right=new Node("left-right");
  root->right->left=new Node("right-left");
  root->right->right=new Node("right_right");
}



void Tree::input_full1() {
  root=new Node("root");
  root->left=new Node("left");
  root->right=new Node("right");
  root->right->left=new Node("right-left");
  root->right->right=new Node("right-right");
}

void Tree::input_full2() {
  root=new Node("root");
  root->left=new Node("left");
  root->right=new Node("right");
  root->left->left=new Node("left-left");
  root->left->right=new Node("left-right");
}


void Tree::input_nonbst() {
  root=new Node("005");
  root->left=new Node("100");
  root->left->left=new Node("050");
  root->left->left->left=new Node("025");
  root->right=new Node("034");
  root->right->left=new Node("003");
  root->right->right=new Node("010");
  root->right->right->left=new Node("500");
}

void Tree::input_bst() {
  input_full1(); // it's BST
}

string Tree::__get_bfs() {
  queue<Node*> q;
  q.push(root);
  string r;
  while (!q.empty()) {
    auto n=q.front();
    q.pop();
    r+= n->val + " ";
    if (n->left) q.push(n->left);
    if (n->right) q.push(n->right);
  }
  return r;
}
void DCP_TEST() {
  cout << "RUNNING DCP TEST: ";
  auto node = new Tree(new Node("root", new Node("left", new Node("left.left")), new Node("right")));
  assert(Tree::deserialize(node->serialize())->root->left->left->val == "left.left");
  cout << "passed.\n";
}

void test_tree(Tree*& t) {
  if (t==nullptr) {cout << "<null tree>\n"; return; }
  string r1 = t->__get_bfs();
  string str(t->serialize());
  Tree* td = Tree::deserialize(str);
  string r2 = td->__get_bfs();
  cout << "Tree: " << r2 << (r1.compare(r2)?" (WRONG)":"") << endl;
}

void test_perfect() {
  Tree *t = new Tree();
  t->input_perfect();
  test_tree(t);
}

void test_full() {
  cout << "FULL1:\n";
  Tree *t1 = new Tree();
  t1->input_full1();
  test_tree(t1);
  cout << "\nFULL2:\n";
  Tree *t2 = new Tree();
  t2->input_full2();
  test_tree(t2);
}

void test_bst() {
  Tree *t = new Tree();
  t->input_bst();
  test_tree(t);
}

void test_nonbst() {
  Tree *t = new Tree();
  t->input_nonbst();
  test_tree(t);

  DCP_TEST();
}

#endif  // RPL_DCP_TEST_003_TEST_H_
