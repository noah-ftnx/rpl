#ifndef RPL_DCP_TEST_003_H_
#define RPL_DCP_TEST_003_H_

#include <utility>

#include <iostream>

using namespace std;

struct Node {
  Node* left {};
  Node* right {};
  int data;
  Node(int data) : data{data} {}
};

struct Tree {
  Node *root{};

  explicit Tree() = default;

  void input_perfect() {
    root=new Node(20);
    root->left=new Node(10);
    root->right=new Node(31);
    root->left->left=new Node(5);
    root->left->right=new Node(15);
    root->right->left=new Node(25);
    root->right->right=new Node(100);
  }

  void input_full1() {
    root=new Node(20);
    root->left=new Node(10);
    root->right=new Node(31);
    root->right->left=new Node(25);
    root->right->right=new Node(100);
  }
  void input_full2() {
    root=new Node(20);
    root->left=new Node(10);
    root->right=new Node(31);
    root->left->left=new Node(5);
    root->left->right=new Node(15);
  }

  void input_bst() {
    input_full1(); // it's BST
  }

  string __get_bfs() {
    queue<Node*> q;
    q.push(root);
    string r;
    while (!q.empty()) {
      auto n=q.front();
      q.pop();
      r+= std::to_string(n->data) + " ";
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    return r;
  }

  string serialize();
  static Tree* deserialize(const string& str);
};


void test_tree(Tree*& t) {
  if (t==nullptr) {cout << "<null tree>\n"; return; }
  string r1 = t->__get_bfs();
  cout << "Tree: " << r1 << endl;
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
  cout << "\nFULL1:\n";
  Tree *t2 = new Tree();
  t2->input_full2();
  test_tree(t2);
}

void test_bst() {
  Tree *t = new Tree();
  t->input_bst();
  test_tree(t);
}

#endif  // RPL_DCP_TEST_003_H_
