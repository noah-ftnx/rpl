#include <string>
#include <iostream>
using namespace std;

// struct Node;

class Tree {
 private:
  Node* root = {};

 public:
  Tree(const string& postfix); // given

  // delete copy op, default ctor, and copy ctor

  string to_string();
};

#include "test/10-prtfix.h"
int main() { run_tests(); return 0; }