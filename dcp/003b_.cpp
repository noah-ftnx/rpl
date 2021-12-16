#include <sstream>
#include <queue>


#include "test/003.h"


string Tree::serialize() {
  if(!root) return "";
  queue<Node*> q({root});
  string res;
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    if (!node->left) { // is leaf
      res+="1\n";
    } else {
      res+="0\n";
      q.push(node->left);
      q.push(node->right);
    }
    res+=to_string(node->data) + "\n";
  }

  res.pop_back(); // eof works!
  return res;
}

Tree* Tree::deserialize(const string& str) {
  if (str.empty()) return nullptr;
  istringstream iss(str);

  auto parse_node = [&] (Node*& node, bool& leaf) {
    string line;
    getline(iss, line); // line1: is leaf
    leaf = (line=="1");

    getline(iss, line); // line2: node
    node = new Node(stoi(line));
  };

  bool is_leaf;
  Node* nn;
  parse_node(nn, is_leaf);

  Tree* t = new Tree();
  t->root = nn;
  if(is_leaf) return t;

  queue<Node*> q ({nn});
  while(!iss.eof()) {
    auto node = q.front(); q.pop();

    parse_node(nn, is_leaf); // left child
    node->left=nn;
    if(!is_leaf) q.push(node->left);

    parse_node(nn, is_leaf); // right child
    node->right=nn;
    if(!is_leaf) q.push(node->right);
  }

  return t;
}


int main() { test_full(); return 0; }


