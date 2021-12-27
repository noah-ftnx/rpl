// INCLUDES
#include <string>
#include <queue>
#include <sstream>
using namespace std;

#include "test/003-base.h"

string Tree::serialize() {
  string res;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    auto n = q.front(); q.pop();
    res+=n->val+ "\n";
    if(n->left) {
      q.push(n->left);
      assert(n->right); // it must also have a right node too
      q.push(n->right);
    }
  }
  res.pop_back(); // TRICKY: so eof works
  return res;
}

Tree* Tree::deserialize(const string& str) {
  if (str.empty()) return nullptr;
  istringstream iss(str);
  string line;
  getline(iss, line);
  Tree* t = new Tree();
  t->root = new Node(line);
  queue<Node*> q ({t->root});
  while (!iss.eof()) {
    getline(iss, line);

    auto n = q.front(); q.pop();
    n->left=new Node(line);
    q.push(n->left);

    getline(iss, line);
    n->right=new Node(line);
    q.push(n->right);
  }

  return t;
}

#include "test/003-test.h"
int main() { test_perfect(); return 0; }


