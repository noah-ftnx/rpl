#include <string>
#include <queue>
#include <istream>
#include <sstream>

#include "test/003.h"

string Tree::serialize() {
  stringstream ss;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    auto n = q.front(); q.pop();
    ss << n->data << endl;
    if(n->left) {
      q.push(n->left);
      // if it has a left node, it must have a right node too
      assert(n->right); q.push(n->right);
    }

  }
  return ss.str();
}

Tree* Tree::deserialize(const string& str) {
  if (str.empty()) return nullptr;
  istringstream iss(str);
  string line;
  getline(iss, line);
  Tree* t = new Tree();
  t->root = new Node(stoi(line));
  queue<Node*> q ({t->root}); // q.push(n)
  while (!iss.eof()) {
    getline(iss, line);
    if(line.empty()) break;

    auto n = q.front(); q.pop();
    n->left=new Node(stoi(line));
    q.push(n->left);

    getline(iss, line);
    n->right=new Node(stoi(line));
    q.push(n->right);
  }

  return t;
}

int main() { run_tests(); return 0; }


