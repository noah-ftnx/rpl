#include <vector>
#include <deque>
using namespace std;

// TODO: define Node
// left, right, parent, data (templated)

// TODO: Tree TEMPLATE
struct Tree {
  Node<T>* root {};
  Tree(T value) { root = new Node<T>(value); }

  Tree(T value);
  void add(const vector<T>& data, const string& path); // given

  void query_successors(deque<int>& query, deque<int>& answer);

};


#include <string>
#include "test/12.h"
int main() { run_tests(); return 0; }
