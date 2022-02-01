// TREE: FULL
// INCLUDES
#include <optional>
#include <sstream>
#include <deque>
using namespace std;

#include "test/003-base.h"

string _serialize(Node* node) { // preorder
  string res;
  res+=node->val + "\n";
  if (node->left) res+=_serialize(node->left);
  if (node->right) res+=_serialize(node->right);
  return res;
}

string Tree::serialize() {
  if (root == nullptr) return "";
  string res = _serialize(root);
  res.pop_back();
  return res;
}

#include <iostream>
Node* _deserialize(deque<Node*>& dq, optional<string> mn, optional<string> mx) {
  auto node = dq.front(); dq.pop_front();

  if (!dq.empty() &&  // go to left
      (!mn || dq.front()->val > mn) && dq.front()->val < node->val) {
    node->left = _deserialize(dq, mn, {node->val});
  }

  if (!dq.empty() && // go to right
      dq.front()->val > node->val && (!mx || dq.front()->val < mx)) {
    node->right = _deserialize(dq, {node->val}, mx);
  }

  return node;
}

Tree* Tree::deserialize(const string& str) {
  if (str.empty()) return nullptr;
  istringstream iss(str);
  string line;
  deque<Node*> dq;
  while(!iss.eof()) {
    getline(iss, line);
    dq.push_back(new Node(line));
  }
  return new Tree(_deserialize(dq, {}, {}));
}



#include "test/003-test.h"
int main() { test_bst(); return 0; }