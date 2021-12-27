#include <string>
using namespace std;
string Tree::serialize();
Tree* Tree::deserialize(const string& str);



#include "test/003-test.h"
int main() { test_bst(); return 0; }