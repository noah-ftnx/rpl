#include <vector>
#include <string>
#include <iostream>
using namespace std;

class BSTree {

  ///////////// for verification
  string __get_bfs() {
    queue<Node<T>*> q;
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
  /////////////
};



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------



string correct_bfs="35 15 45 20 70 60 73 50 ";

void run_tests() {
  auto t1= new BSTree<int>();
  vector<int> v1 {35, 15, 20, 45, 70, 60, 73, 50};
  t1->insert(v1);
  string s = t1->__get_bfs();
  cout << s  << (s.compare(correct_bfs)!=0?" (WRONG)": "")<< endl;
}

int main() { run_tests(); return 0; }