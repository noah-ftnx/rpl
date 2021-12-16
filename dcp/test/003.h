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
    root->left->right=new Node(7);
    root->right->left=new Node(25);
    root->right->right=new Node(100);
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


void run_tests() {
  Tree *t = new Tree();
  t->input_perfect();

  string r1 = t->__get_bfs();

  string str(t->serialize());
  Tree* td = Tree::deserialize(str);
  string r2 = td->__get_bfs();
  eaout << "bfs: " << r2 << (r1.compare(r2)?" (WRONG)":"") << endl;
}

#endif  // RPL_DCP_TEST_003_H_
