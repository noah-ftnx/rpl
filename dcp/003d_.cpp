// TREE: NON-BST (all, including non-bst )
// INCLUDES
#include <deque>
#include <string>
#include <sstream>
using namespace std;

#include "test/003-base.h"

string _serialize(Node* node) { // preorder
  if (node == nullptr) return "\n";

  return node->val + "\n" +
         _serialize(node->left) + _serialize(node->right);
}
string Tree::serialize() {
  if (root == nullptr) return "";
  string res = _serialize(root);
  res.pop_back(); // for eof
  return res;
}


Node* _deserialize(deque<Node*>& dq) {
  auto node = dq.front(); dq.pop_front();
  if(!node) return nullptr;

  node->left=_deserialize(dq);
  node->right=_deserialize(dq);
  return node;
}

Tree* Tree::deserialize(const string& str) {
  if (str.size() == 0) return nullptr;
  deque<Node*> dq;
  istringstream iss(str);
  string line;
  while(!iss.eof()) {
    getline(iss, line);
    Node* node = (line.empty()? nullptr : new Node(line));
    dq.push_back(node);
  }

  return new Tree(_deserialize(dq));
}



#include "test/003-test.h"
int main() { test_nonbst(); return 0; }