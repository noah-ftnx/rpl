#include <vector>
using namespace std;

template <class T>
class BinaryTreeNode;

// IMPLEMENT: return all three traversals
vector<vector<int>> getTreeTraversalRECV(BinaryTreeNode<int> *root);
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root);

#include "test/09.h"
int main() { run_tests(); return 0; }
