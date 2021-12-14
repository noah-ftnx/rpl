#include "test/test-bst.h"
#include <queue>
using namespace std;

void Tree::print_bst_level() {
  if (!root) return;
  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
   int sz = q.size();
   while (sz--) {
     auto n = q.front(); q.pop();
     cout << n->data << " ";
     if (n->left) q.push(n->left);
     if (n->right) q.push(n->right);
   }
   cout << endl;
  }
}

int main () { run_tests(); }