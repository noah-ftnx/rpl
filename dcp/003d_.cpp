#include <sstream>
#include <deque>
#include <string>

#include <queue> // header-dep
#include "test/003.h"

string _serialize(Node* node) {
  if (node == nullptr) return "\n";

  string res = to_string(node->data) + "\n";
  res += _serialize(node->left) + _serialize(node->right);
  return res;
}
string Tree::serialize() {
  string res = _serialize(root);
  res.pop_back();
  return res;
}


Node* _deserialize(deque<Node*>& dq) {
  auto n = dq.front(); dq.pop_front();
  if(n == nullptr) return nullptr;

  n->left= _deserialize(dq);
  n->right= _deserialize(dq);
  return n;
}
Tree* Tree::deserialize(const string& str) {
  istringstream iss(str);
  deque<Node*> dq;
  string line;
  while(!iss.eof()) {
    getline(iss, line);
    Node* n = nullptr;
    if (!line.empty()) n = new Node(stoi(line));
    dq.push_back(n);
  }

  Tree* t = new Tree();
  t->root=_deserialize(dq);
  return t;
}

int main() { test_nonbst(); return 0; }