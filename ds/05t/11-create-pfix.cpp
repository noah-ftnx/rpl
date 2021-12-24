#include <string> // for Tree.print()
#include <stack>
using namespace std;

class Tree {
  Tree(const string& postfix);
  string to_string();
};



#include "test/11-cpfix.h"
int main() { run_tests(); return 0; }