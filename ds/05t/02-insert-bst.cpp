#include <vector>
using namespace std;

struct Node {
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}
};

class BSTree {
 public:
  Node* root {};

  // IMPLEMENT: insert one value
  void insert(int data);

  // IMPLEMENT: insert all values in order
  void insert(const vector<int>& values);
};

#include "test/02-insert-bst.h"
int main() { run_tests(); return 0; }
