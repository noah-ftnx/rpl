
struct Node {
  Node* left {};
  Node* right {};
  int data {};

  Node(int data) : data{data} {}
};

struct Tree {
  // IMPLEMENT: deepest_node
  Node* deepest_node();
};



#include "test/11b.h"
int main() { run_tests(); return 0; }