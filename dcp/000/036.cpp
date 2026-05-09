
struct Node {
  Node* left {};
  Node* right {};
  int data;
  Node(int data) : data{data} {}
};

// IMPLEMENT: predecessor
int predecessor(Node* root);



#include "test/036.h"
int main() { run_tests(); return 0; }