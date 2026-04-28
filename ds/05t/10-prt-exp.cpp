#include <string>
using namespace std;

// CREATE:
// struct Node
// - with 'char' field to keep data. Make this a parameterized constructor
// - include link to parent. Create constructor.

class Tree {
 private:
  Node* root = {};

 public:
  Tree(const string& postfix); // given

  // BONUS: delete: default ctor, copy ctor, and copy assignment.

  string to_string();
};

#include "test/10-prtfix.h"
int main() { run_tests(); return 0; }
