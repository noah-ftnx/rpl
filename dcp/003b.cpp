// TREE: FULL
// INCLUDES

#include "test/003-base.h"

string Tree::serialize();
Tree* Tree::deserialize(const string& str);



#include "test/003-test.h"
int main() { test_full(); return 0; }