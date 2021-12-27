// TREE: NON-BST (all, including non-bst )
// INCLUDES

#include "test/003-base.h"


Node* _deserialize(deque<Node*>& dq);
Tree* Tree::deserialize(const string& str);



#include "test/003-test.h"
int main() { test_nonbst(); return 0; }