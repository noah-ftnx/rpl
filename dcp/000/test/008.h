#ifndef RPL_DCP_TEST_008_H_
#define RPL_DCP_TEST_008_H_

Node* tree0() {
  return nullptr;
}

Node* tree1() {
  return new Node(5);
}

Node* tree2() {
  Node* root= new Node(0);
  root->left= new Node(0);
  root->right= new Node(0);
  return root;
}

Node* tree3() {
  Node* root= new Node(0);
  root->left= new Node(1);
  root->right= new Node(1);
  return root;
}

Node* tree4() {
  Node* root= new Node(0);
  root->left=new Node(1);
  root->right=new Node(0);
  root->right->left=new Node(1);
  root->right->left->left=new Node(1);
  root->right->left->right=new Node(1);
  root->right->right=new Node(0);
  return root;
}

void check(string msg, Node* root, int correct) {
  int res = count_unival(root);
  cout << "unival:" << msg << ": " << res << (res!=correct?" (WRONG)":"") << endl;
}

void run_tests() {
  check("t0", tree0(), 0);
  check("t1", tree1(), 1);
  check("t2", tree2(), 3);
  check("t3", tree3(), 2);
  check("t4", tree4(), 5);
}

#endif  // RPL_DCP_TEST_008_H_
