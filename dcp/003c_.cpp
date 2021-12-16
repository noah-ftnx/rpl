#include <sstream>
#include <deque>

#include <queue> // header-dep
#include "test/003.h"

string _serialize(Node* node) { // inorder
  string res = to_string(node->data) + "\n";
  if (node->left) res+= _serialize(node->left);
  if (node->right) res+= _serialize(node->right);
  return res;
}
string Tree::serialize() {
  if (!root) return "";
  string res = _serialize(root);
  res.pop_back();
  return res;
}

// min / max traversal of the inorder
Node* _deserialize(deque<Node*>& nodes, int mn=INT_MIN, int mx=INT_MAX) {
  auto n = nodes.front();  nodes.pop_front();

  if (!nodes.empty() &&
      nodes.front()->data > mn && nodes.front()->data < n->data) { // within limits: go left
    n->left=_deserialize(nodes, mn, n->data); // new max
  }

  if (!nodes.empty() &&
      nodes.front()->data > n->data && nodes.front()->data < mx) { // within limits: go right
    n->right=_deserialize(nodes, n->data, mx);
  }

  return n;
}

Tree* Tree::deserialize(const string& str) {
  istringstream iss(str);

  deque<Node*> dq;
  string line;
  while(!iss.eof()) {
    getline(iss, line);
    dq.push_back(new Node(stoi(line)));
  }

  auto root=_deserialize(dq);
  Tree *t = new Tree();
  t->root=root;
  return t;
}


int main() { test_bst(); return 0; }