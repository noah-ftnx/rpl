// TREE: FULL
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#include "test/003-base.h"

string Tree::serialize() {
  if (root==nullptr) return "";
  queue<Node*> q;
  q.push(root);
  string res;
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    if (node->left == nullptr) {  // leaf
      res+="1\n";
    } else {
      res+="0\n";
      q.push(node->left);
      q.push(node->right);
    }
    res+=node->val + "\n";
  }

  res.pop_back(); // for eof to work
  return res;
}

Tree* Tree::deserialize(const string& str) {
  if (str.size() == 0) return nullptr;

  istringstream iss(str);
  auto get_node = [&iss](Node*& node, bool& leaf) {
    string line;
    getline(iss, line);
    leaf=(line=="1");
    getline(iss, line);
    node = new Node(line);
  };

  bool leaf; Node* nn;
  get_node(nn, leaf);
  auto tree = new Tree(nn);
  if (leaf) return tree;

  queue<Node*> q({tree->root});
  while(!iss.eof()) {
    auto parent = q.front(); q.pop();
    get_node(nn, leaf);  // left
    parent->left = nn;
    if (!leaf) { q.push(nn); }

    get_node(nn, leaf);  // right
    parent->right = nn;
    if (!leaf) { q.push(nn); }
  }

  return tree;
}



#include "test/003-test.h"
int main() { test_full(); return 0; }